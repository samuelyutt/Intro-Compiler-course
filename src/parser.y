%{

#include "include/AST/ast.hpp"
#include "include/AST/program.hpp"
#include "include/AST/declaration.hpp"
#include "include/AST/constantvalue.hpp"
#include "include/AST/variable.hpp"
#include "include/AST/programbody.hpp"
#include "include/AST/expression.hpp"
#include "include/AST/variablereference.hpp"
#include "include/AST/binaryoperator.hpp"
#include "include/AST/unaryoperator.hpp"
#include "include/AST/functioncallexpr.hpp"
#include "include/AST/compoundstmt.hpp"
#include "include/AST/statement.hpp"
#include "include/AST/arrtype.hpp"
#include "include/AST/arrdeclaration.hpp"
#include "include/AST/assignment.hpp"
#include "include/AST/print.hpp"
#include "include/AST/read.hpp"
#include "include/AST/return.hpp"
#include "include/AST/while.hpp"
#include "include/AST/if.hpp"
#include "include/AST/for.hpp"
#include "include/AST/functioninvokation.hpp"
#include "include/core/error.h"
#include "include/visitor/dumpvisitor.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <vector>

#define YYLTYPE yyltype

typedef struct YYLTYPE {
    uint32_t first_line;
    uint32_t first_column;
    uint32_t last_line;
    uint32_t last_column;
} yyltype;

/* Declared by scanner.l */
extern int32_t LineNum;
extern char Buffer[512];

/* Declared by lex */
extern FILE *yyin;
extern char *yytext;

extern "C" int yylex(void);
extern "C" int yyparse();
static void yyerror(const char *msg);

static ProgramNode *root;
%}

%locations
%code requires{ 
    #include "AST/program.hpp"
    #include "AST/declaration.hpp"
    #include "AST/constantvalue.hpp"
    #include "AST/variable.hpp"
    #include "AST/programbody.hpp"
    #include "AST/expression.hpp"
    #include "AST/variablereference.hpp"
    #include "AST/binaryoperator.hpp"
    #include "AST/unaryoperator.hpp"
    #include "AST/functioncallexpr.hpp"
    #include "AST/compoundstmt.hpp"
    #include "AST/statement.hpp"
    #include "AST/arrtype.hpp"
    #include "AST/arrdeclaration.hpp"
    #include "AST/assignment.hpp"
    #include "AST/print.hpp"
    #include "AST/read.hpp"
    #include "AST/return.hpp"
    #include "AST/while.hpp"
    #include "AST/if.hpp"
    #include "AST/for.hpp"
    #include "AST/functioninvokation.hpp"
}

    /* Delimiter */
%token COMMA SEMICOLON COLON
%token L_PARENTHESIS R_PARENTHESIS
%token L_BRACKET R_BRACKET

    /* Operator */
%token ASSIGN
%left OR
%left AND
%right NOT
%left LESS LESS_OR_EQUAL EQUAL GREATER GREATER_OR_EQUAL NOT_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MOD
%right UNARY_MINUS

    /* Keyword */
%token ARRAY BOOLEAN INTEGER REAL STRING
%token END BEGIN_ /* Use BEGIN_ since BEGIN is a keyword in lex */
%token DO ELSE FOR IF THEN WHILE
%token DEF OF TO RETURN VAR
%token FALSE TRUE
%token PRINT READ

    /* Identifier */
%token ID

    /* Literal */
%token INT_LITERAL
%token REAL_LITERAL
%token STRING_LITERAL

%union {
    char*                               str;
    ProgramNode*                        program_node;
    ProgramBodyNode*                    programbody_node;
    DeclarationNode*                    declaration_node;
    ConstantValueNode*                  constantvalue_node;
    ExpressionNode*                     expression_node;
    VariableNode*                       variable_node;
    VariableReferenceNode*              variablereference_node;
    FunctionCallExprNode*               functioncallexpr_node;
    StatementNode*                      statement_node;
    CompoundStmtNode*                   compoundstmt_node;
    ArrTypeNode*                        arrtype_node;
    FunctionNode*                       function_node;
    std::vector<DeclarationNode*>*      v_declaration_node;
    std::vector<VariableNode*>*         v_variable_node;
    std::vector<ExpressionNode*>*       v_expression_node;
    std::vector<StatementNode*>*        v_statement_node;
    std::vector<ArrDeclarationNode*>*   v_arrdecl_node;
    std::vector<FunctionNode*>*         v_function_node;
}

%type<program_node>             Program
%type<programbody_node>         ProgramBody
%type<declaration_node>         Declaration
%type<v_declaration_node>       DeclarationList
%type<v_declaration_node>       Declarations
%type<constantvalue_node>       LiteralConstant
%type<v_variable_node>          IdList
%type<expression_node>          Expression
%type<v_expression_node>        ArrForm
%type<v_expression_node>        Expressions
%type<v_expression_node>        ExpressionList
%type<variablereference_node>   VariableReference
%type<functioncallexpr_node>    FunctionCall
%type<statement_node>           Statement
%type<statement_node>           Simple
%type<statement_node>           Condition
%type<statement_node>           While
%type<statement_node>           For
%type<statement_node>           Return
%type<statement_node>           FunctionInvokation
%type<v_statement_node>         Statements
%type<v_statement_node>         StatementList
%type<v_statement_node>         ElseOrNot
%type<compoundstmt_node>        CompoundStatement
%type<v_arrdecl_node>           ArrDecl
%type<arrtype_node>             ArrType
%type<declaration_node>         FormalArg
%type<v_declaration_node>       FormalArgs
%type<v_declaration_node>       FormalArgList
%type<function_node>            FunctionDeclaration
%type<v_function_node>          Functions
%type<v_function_node>          FunctionList
%type<str>                      ProgramName
%type<str>                      INT_LITERAL
%type<str>                      REAL_LITERAL
%type<str>                      STRING_LITERAL
%type<str>                      TRUE
%type<str>                      FALSE
%type<str>                      ID
%type<str>                      ScalarType
%type<str>                      FunctionName
%type<str>                      ReturnType
%type<str>                      Type
    

%%
    /*
       Program Units
                     */

Program:
    ProgramName SEMICOLON ProgramBody END ProgramName {
        $$ = root = new ProgramNode(@1.first_line, @1.first_column);
        $$->name.assign($1);
        $$->programBodyNode = $3;
    }
;

ProgramName:
    ID
;

ProgramBody:
    DeclarationList FunctionList CompoundStatement {
        $$ = new ProgramBodyNode(@1.first_line, @1.first_column);
        if($1 != NULL) $$->v_declarationNode = *$1;
        if($2 != NULL) $$->v_functionNode = *$2;
        if($3 != NULL) $$->compoundStmtNode = $3;
    }
;

DeclarationList:
    Epsilon {
        $$ = NULL;
    }
    |
    Declarations {
        $$ = $1;
    }
;

Declarations:
    Declaration {
        $$ = new std::vector<DeclarationNode*>;
        $$->emplace_back($1);
    }
    |
    Declarations Declaration {
        $1->emplace_back($2);
        $$ = $1;
    }
;

FunctionList:
    Epsilon {
        $$ = NULL;
    }
    |
    Functions {
        $$ = $1;
    }
;

Functions:
    FunctionDeclaration {
        $$ = new std::vector<FunctionNode*>;
        $$->emplace_back($1);
    }
    |
    Functions FunctionDeclaration {
        $1->emplace_back($2);
        $$ = $1;
    }
;

FunctionDeclaration:
    FunctionName L_PARENTHESIS FormalArgList R_PARENTHESIS ReturnType SEMICOLON
    CompoundStatement
    END FunctionName {
        $$ = new FunctionNode(@1.first_line, @1.first_column);
        $$->name.assign($1);
        if($3 != NULL) $$->parameters = *$3;
        $$->return_type.assign($5);
        $$->body = $7;
    }
;

FunctionName:
    ID {
        $$ = $1;
    }
;

FormalArgList:
    Epsilon {
        $$ = NULL;
    }
    |
    FormalArgs {
        $$ = $1;
    }
;

FormalArgs:
    FormalArg {
        $$ = new std::vector<DeclarationNode*>;
        $$->emplace_back($1);
    }
    |
    FormalArgs SEMICOLON FormalArg {
        $1->emplace_back($3);
        $$ = $1;
    }
;

FormalArg:
    IdList COLON ScalarType {
        for (auto variableNode: *$1) {
            variableNode->type = $3;
            variableNode->constantValueNode = NULL;
        }
        $$ = new DeclarationNode(@1.first_line, @1.first_column);
        $$->v_variableNode = *$1;
    }
    |
    IdList COLON ArrType {
        for (auto variableNode: *$1) {
            variableNode->type = $3->type;
            variableNode->constantValueNode = NULL;
            variableNode->arrTypeNode = $3;
        }
        $$ = new DeclarationNode(@1.first_line, @1.first_column);
        $$->v_variableNode = *$1;
    }
;

IdList:
    ID {
        VariableNode* variableNode = new VariableNode(@1.first_line, @1.first_column);
        variableNode->name.assign($1);
        $$ = new std::vector<VariableNode*>;
        $$->emplace_back(variableNode);
    }
    |
    IdList COMMA ID {
        VariableNode* variableNode = new VariableNode(@3.first_line, @3.first_column);
        variableNode->name.assign($3);
        $1->emplace_back(variableNode);
        $$ = $1;
    }
;

ReturnType:
    COLON ScalarType {
        $$ = $2;
    }
    |
    Epsilon {
        $$ = "void";
    }
;

    /*
       Data Types and Declarations
                                   */

Declaration:
    VAR IdList COLON ArrType SEMICOLON {
        for (auto variableNode: *$2) {
            variableNode->type = $4->type;
            variableNode->constantValueNode = NULL;
            variableNode->arrTypeNode = $4;
        }
        $$ = new DeclarationNode(@1.first_line, @1.first_column);
        $$->v_variableNode = *$2;
    }
    |
    VAR IdList COLON ScalarType SEMICOLON {
        for (auto variableNode: *$2) {
            variableNode->type = $4;
            variableNode->constantValueNode = NULL;
        }
        $$ = new DeclarationNode(@1.first_line, @1.first_column);
        $$->v_variableNode = *$2;
    }
    |
    VAR IdList COLON LiteralConstant SEMICOLON{
        for (auto variableNode: *$2) {
            variableNode->type = $4->type;
            variableNode->constantValueNode = $4;
        }
        $$ = new DeclarationNode(@1.first_line, @1.first_column);
        $$->v_variableNode = *$2;
    }
;


/*
Declaration:
    VAR IdList COLON TypeOrConstant SEMICOLON {
        $$ = t1 = new DeclarationNode(@1.first_line, @1.first_column);
    }
;

TypeOrConstant:
    Type {
        $$ = NULL;
    }
    |
    LiteralConstant {
        $$ = $1;
    }
;
*/

Type:
    ScalarType
    |
    ArrType
;

ScalarType:
    INTEGER
    |
    REAL
    |
    STRING
    |
    BOOLEAN
;

ArrType:
    ArrDecl ScalarType {
        $$ = new ArrTypeNode(@1.first_line, @1.first_column);
        $$->type.assign($2);
        $$->v_arrdeclarationNode = *$1;
    }
;

ArrDecl:
    ARRAY INT_LITERAL TO INT_LITERAL OF {
        ArrDeclarationNode* node = new ArrDeclarationNode(@1.first_line, @1.first_column);
        node->bgn.assign($2);
        node->end.assign($4);
        $$ = new std::vector<ArrDeclarationNode*>;
        $$->emplace_back(node);
    }
    |
    ArrDecl ARRAY INT_LITERAL TO INT_LITERAL OF {
        ArrDeclarationNode* node = new ArrDeclarationNode(@1.first_line, @1.first_column);
        node->bgn.assign($3);
        node->end.assign($5);
        $1->emplace_back(node);
        $$ = $1;
    }
;

LiteralConstant:
    INT_LITERAL {
        $$ = new ConstantValueNode(@1.first_line, @1.first_column);
        if ($1[0] == '0')
            $$->constant_value.assign( std::to_string(std::stoi($1, 0, 8)) );
        else
            $$->constant_value.assign( std::to_string(std::stoi($1)) );
        $$->type = "integer";
    }
    |
    REAL_LITERAL {
        $$ = new ConstantValueNode(@1.first_line, @1.first_column);
        $$->constant_value.assign( std::to_string(std::stof($1)) );
        $$->type = "real";
    }
    |
    STRING_LITERAL {
        $$ = new ConstantValueNode(@1.first_line, @1.first_column);
        $$->constant_value.assign($1);
        $$->type = "string";
    }
    |
    TRUE {
        $$ = new ConstantValueNode(@1.first_line, @1.first_column);
        $$->constant_value.assign($1);
        $$->type = "boolean";
    }
    |
    FALSE {
        $$ = new ConstantValueNode(@1.first_line, @1.first_column);
        $$->constant_value.assign($1);
        $$->type = "boolean";
    }
;

    /*
       Statements
                  */

Statement:
    CompoundStatement {
        $$ = $1;
    }
    |
    Simple {
        $$ = $1;
    }
    |
    Condition {
        $$ = $1;
    }
    |
    While {
        $$ = $1;
    }
    |
    For {
        $$ = $1;
    }
    |
    Return {
        $$ = $1;
    }
    |
    FunctionInvokation {
        $$ = $1;
    }
;

CompoundStatement:
    BEGIN_
    DeclarationList
    StatementList
    END {
        CompoundStmtNode* node = new CompoundStmtNode(@1.first_line, @1.first_column);
        if($2 != NULL) node->v_declarationNode = *$2;
        if($3 != NULL) node->v_statementNode = *$3;
        $$ = node;
    }
;

Simple:
    VariableReference ASSIGN Expression SEMICOLON {
        AssignmentNode* node = new AssignmentNode(@2.first_line, @2.first_column);
        node->lvalue = $1;
        node->expression = $3;
        $$ = node;
    }
    |
    PRINT Expression SEMICOLON {
        PrintNode* node = new PrintNode(@1.first_line, @1.first_column);
        node->target = $2;
        $$ = node;
    }
    |
    READ VariableReference SEMICOLON {
        ReadNode* node = new ReadNode(@1.first_line, @1.first_column);
        node->target = $2;
        $$ = node;
    }
;

VariableReference:
    ID {
        $$ = new VariableReferenceNode(@1.first_line, @1.first_column);
        $$->name.assign($1);
    }
    |
    ID ArrForm {
        $$ = new VariableReferenceNode(@1.first_line, @1.first_column);
        $$->name.assign($1);
        $$->v_expressionNode = *$2;
    }
;

ArrForm:
    L_BRACKET Expression R_BRACKET {
        $$ = new std::vector<ExpressionNode*>;
        $$->emplace_back($2);
    }
    |
    ArrForm L_BRACKET Expression R_BRACKET {
        $1->emplace_back($3);
        $$ = $1;
    }
;

Condition:
    IF Expression THEN
    StatementList
    ElseOrNot
    END IF {
        IfNode* node = new IfNode(@1.first_line, @1.first_column);
        node->condition = $2;
        if($4 != NULL) node->body = *$4;
        if($5 != NULL) node->body_of_else = *$5;
        $$ = node;
    }
;

ElseOrNot:
    ELSE
    StatementList {
        $$ = $2;
    }
    |
    Epsilon {
        $$ = NULL;
    }
;

While:
    WHILE Expression DO
    StatementList
    END DO {
        WhileNode* node = new WhileNode(@1.first_line, @1.first_column);
        node->condition = $2;
        if($4 != NULL) node->body = *$4;
        $$ = node;
    }
;

For:
    FOR ID ASSIGN INT_LITERAL TO INT_LITERAL DO
    StatementList
    END DO {
        ConstantValueNode* bgnConstantValueNode = new ConstantValueNode(@4.first_line, @4.first_column);
        bgnConstantValueNode->constant_value.assign($4);
        bgnConstantValueNode->type = "integer";

        ConstantValueNode* endConstantValueNode = new ConstantValueNode(@6.first_line, @6.first_column);
        endConstantValueNode->constant_value.assign($6);
        endConstantValueNode->type = "integer";

        /*************************************/
        
        VariableNode* variableNode = new VariableNode(@2.first_line, @2.first_column);
        variableNode->name.assign($2);
        variableNode->type = "integer";
        variableNode->constantValueNode = NULL;

        DeclarationNode* declarationNode = new DeclarationNode(@2.first_line, @2.first_column);
        declarationNode->v_variableNode.emplace_back(variableNode);

        /*************************************/
        
        VariableReferenceNode* variableReferenceNode = new VariableReferenceNode(@2.first_line, @2.first_column);
        variableReferenceNode->name.assign($2);

        AssignmentNode* assignmentNode = new AssignmentNode(@3.first_line, @3.first_column);
        assignmentNode->lvalue = variableReferenceNode;
        assignmentNode->expression = bgnConstantValueNode;

        /*************************************/

        ForNode* node = new ForNode(@1.first_line, @1.first_column);
        node->loop_var_decl = declarationNode;
        node->init_assignment = assignmentNode;
        node->condition = endConstantValueNode;
        if($8 != NULL) node->body = *$8;
        $$ = node;
    }
;

Return:
    RETURN Expression SEMICOLON {
        ReturnNode* node = new ReturnNode(@1.first_line, @1.first_column);
        node->return_value = $2;
        $$ = node;
    }
;

FunctionInvokation:
    FunctionCall SEMICOLON {
        FunctionInvokationNode* node = new FunctionInvokationNode(@1.first_line, @1.first_column);
        node->name = $1->name;
        node->v_expressionNode = $1->v_expressionNode;
        $$ = node;
    }
;

FunctionCall:
    ID L_PARENTHESIS ExpressionList R_PARENTHESIS {
        $$ = new FunctionCallExprNode(@1.first_line, @1.first_column);
        $$->name.assign($1);
        if($3 != NULL) $$->v_expressionNode = *$3;
    }
;

ExpressionList:
    Epsilon {
        $$ = NULL;
    }
    |
    Expressions {
        $$ = $1;
    }
;

Expressions:
    Expression {
        $$ = new std::vector<ExpressionNode*>;
        $$->emplace_back($1);
    }
    |
    Expressions COMMA Expression {
        $1->emplace_back($3);
        $$ = $1;
    }
;

StatementList:
    Epsilon {
        $$ = NULL;
    }
    |
    Statements {
        $$ = $1;
    }
;

Statements:
    Statement {
        $$ = new std::vector<StatementNode*>;
        $$->emplace_back($1);
    }
    |
    Statements Statement{
        $1->emplace_back($2);
        $$ = $1;
    }
;

Expression:
    L_PARENTHESIS Expression R_PARENTHESIS {
        $$ = $2;
    }
    |
    MINUS Expression %prec UNARY_MINUS {
        UnaryOperatorNode* node = new UnaryOperatorNode(@1.first_line, @1.first_column);
        node->op = "neg";
        node->operand = $2;
        $$ = node;
    }
    |
    Expression MULTIPLY Expression {
        BinaryOperatorNode* node = new BinaryOperatorNode(@2.first_line, @2.first_column);
        node->op = "*";
        node->leftOperand = $1;
        node->rightOperand = $3;
        $$ = node;
    }
    |
    Expression DIVIDE Expression {
        BinaryOperatorNode* node = new BinaryOperatorNode(@2.first_line, @2.first_column);
        node->op = "/";
        node->leftOperand = $1;
        node->rightOperand = $3;
        $$ = node;
    }
    |
    Expression MOD Expression {
        BinaryOperatorNode* node = new BinaryOperatorNode(@2.first_line, @2.first_column);
        node->op = "mod";
        node->leftOperand = $1;
        node->rightOperand = $3;
        $$ = node;
    }
    |
    Expression PLUS Expression {
        BinaryOperatorNode* node = new BinaryOperatorNode(@2.first_line, @2.first_column);
        node->op = "+";
        node->leftOperand = $1;
        node->rightOperand = $3;
        $$ = node;
    }
    |
    Expression MINUS Expression {
        BinaryOperatorNode* node = new BinaryOperatorNode(@2.first_line, @2.first_column);
        node->op = "-";
        node->leftOperand = $1;
        node->rightOperand = $3;
        $$ = node;
    }
    |
    Expression LESS Expression {
        BinaryOperatorNode* node = new BinaryOperatorNode(@2.first_line, @2.first_column);
        node->op = "<";
        node->leftOperand = $1;
        node->rightOperand = $3;
        $$ = node;
    }
    |
    Expression LESS_OR_EQUAL Expression {
        BinaryOperatorNode* node = new BinaryOperatorNode(@2.first_line, @2.first_column);
        node->op = "<=";
        node->leftOperand = $1;
        node->rightOperand = $3;
        $$ = node;
    }
    |
    Expression GREATER Expression {
        BinaryOperatorNode* node = new BinaryOperatorNode(@2.first_line, @2.first_column);
        node->op = ">";
        node->leftOperand = $1;
        node->rightOperand = $3;
        $$ = node;
    }
    |
    Expression GREATER_OR_EQUAL Expression {
        BinaryOperatorNode* node = new BinaryOperatorNode(@2.first_line, @2.first_column);
        node->op = ">=";
        node->leftOperand = $1;
        node->rightOperand = $3;
        $$ = node;
    }
    |
    Expression EQUAL Expression {
        BinaryOperatorNode* node = new BinaryOperatorNode(@2.first_line, @2.first_column);
        node->op = "=";
        node->leftOperand = $1;
        node->rightOperand = $3;
        $$ = node;
    }
    |
    Expression NOT_EQUAL Expression {
        BinaryOperatorNode* node = new BinaryOperatorNode(@2.first_line, @2.first_column);
        node->op = "<>";
        node->leftOperand = $1;
        node->rightOperand = $3;
        $$ = node;
    }
    |
    NOT Expression {
        UnaryOperatorNode* node = new UnaryOperatorNode(@1.first_line, @1.first_column);
        node->op = "not";
        node->operand = $2;
        $$ = node;
    }
    |
    Expression AND Expression {
        BinaryOperatorNode* node = new BinaryOperatorNode(@2.first_line, @2.first_column);
        node->op = "and";
        node->leftOperand = $1;
        node->rightOperand = $3;
        $$ = node;
    }
    |
    Expression OR Expression {
        BinaryOperatorNode* node = new BinaryOperatorNode(@2.first_line, @2.first_column);
        node->op = "or";
        node->leftOperand = $1;
        node->rightOperand = $3;
        $$ = node;
    }
    |
    LiteralConstant {
        $$ = $1;
    }
    |
    VariableReference {
        $$ = $1;
    }
    |
    FunctionCall {
        $$ = $1;
    }
;

    /*
       misc
            */
Epsilon:
;
%%

void yyerror(const char *msg) {
    fprintf(stderr,
            "\n"
            "|-----------------------------------------------------------------"
            "---------\n"
            "| Error found in Line #%d: %s\n"
            "|\n"
            "| Unmatched token: %s\n"
            "|-----------------------------------------------------------------"
            "---------\n",
            LineNum, Buffer, yytext);
    exit(-1);
}

int tabcount;

void tab(int count) {
    for (int i = 0; i < count; i++)
        std::cout << "  ";
}

int main(int argc, const char *argv[]) {
    CHECK(argc >= 2, "Usage: ./parser <filename>\n");

    FILE *fp = fopen(argv[1], "r");

    CHECK(fp != NULL, "fopen() fails.\n");
    yyin = fp;
    yyparse();

    tabcount = 0;
    //freeProgramNode(root);
    DumpVisitor dvisitor;
    root->accept(dvisitor);

    //std::cout << "CPP works!" << std::endl;
    printf("\n"
           "|--------------------------------|\n"
           "|  There is no syntactic error!  |\n"
           "|--------------------------------|\n");
    return 0;
}
