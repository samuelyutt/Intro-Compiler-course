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
/*#include "include/AST/compoundstatement.hpp"
#include "include/AST/read.hpp"
#include "include/AST/return.hpp"
#include "include/AST/unaryoperator.hpp"
#include "include/AST/variable.hpp"
#include "include/AST/variablereference.hpp"
#include "include/AST/while.hpp"
#include "include/AST/for.hpp"
#include "include/AST/function.hpp"
#include "include/AST/if.hpp"
#include "include/AST/functioncall.hpp"
#include "include/AST/print.hpp"
#include "include/AST/assignment.hpp"*/
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
static VariableReferenceNode *t;
//static ConstantValueNode *t2;

//std::vector<VariableNode*>      v_variable_node;
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
    //#include "AST/.hpp"
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
    char*                   str;
    ProgramNode*            program_node;
    ProgramBodyNode*        programbody_node;
    DeclarationNode*        declaration_node;
    ConstantValueNode*      constantvalue_node;
    ExpressionNode*         expression_node;
    VariableNode*           variable_node;
    VariableReferenceNode*  variablereference_node;

    std::vector<DeclarationNode*>*      v_declaration_node;
    std::vector<VariableNode*>*         v_variable_node;
    std::vector<ExpressionNode*>*       v_expression_node;
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
%type<variablereference_node>   VariableReference

%type<str>                  ProgramName
%type<str>                  INT_LITERAL
%type<str>                  REAL_LITERAL
%type<str>                  STRING_LITERAL
%type<str>                  TRUE
%type<str>                  FALSE
%type<str>                  ID
%type<str>                  Type
    


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
        $$->v_declarationNode = *$1;
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
    Epsilon
    |
    Functions
;

Functions:
    FunctionDeclaration
    |
    Functions FunctionDeclaration
;

FunctionDeclaration:
    FunctionName L_PARENTHESIS FormalArgList R_PARENTHESIS ReturnType SEMICOLON
    CompoundStatement
    END FunctionName
;

FunctionName:
    ID
;

FormalArgList:
    Epsilon
    |
    FormalArgs
;

FormalArgs:
    FormalArg
    |
    FormalArgs SEMICOLON FormalArg
;

FormalArg:
    IdList COLON Type
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
    COLON ScalarType
    |
    Epsilon
;

    /*
       Data Types and Declarations
                                   */

Declaration:
    VAR IdList COLON Type SEMICOLON {
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
    ArrDecl ScalarType
;

ArrDecl:
    ARRAY INT_LITERAL TO INT_LITERAL OF
    |
    ArrDecl ARRAY INT_LITERAL TO INT_LITERAL OF
;

LiteralConstant:
    INT_LITERAL {
        $$ = new ConstantValueNode(@1.first_line, @1.first_column);
        $$->constant_value.assign($1);
        $$->type = "integer";
    }
    |
    REAL_LITERAL {
        $$ = new ConstantValueNode(@1.first_line, @1.first_column);
        $$->constant_value.assign($1);
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
    CompoundStatement
    |
    Simple
    |
    Condition
    |
    While
    |
    For
    |
    Return
    |
    FunctionInvokation
;

CompoundStatement:
    BEGIN_
    DeclarationList
    StatementList
    END
;

Simple:
    VariableReference ASSIGN Expression SEMICOLON
    |
    PRINT Expression SEMICOLON
    |
    READ VariableReference SEMICOLON
;

VariableReference:
    ID {
        $$ = new VariableReferenceNode(@1.first_line, @1.first_column);
        $$->name.assign($1);
        t = $$;
    }
    |
    ID ArrForm {
        $$ = new VariableReferenceNode(@1.first_line, @1.first_column);
        $$->name.assign($1);
        $$->v_expressionNode = *$2;
        t = $$;
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
    END IF
;

ElseOrNot:
    ELSE
    StatementList
    |
    Epsilon
;

While:
    WHILE Expression DO
    StatementList
    END DO
;

For:
    FOR ID ASSIGN INT_LITERAL TO INT_LITERAL DO
    StatementList
    END DO
;

Return:
    RETURN Expression SEMICOLON
;

FunctionInvokation:
    FunctionCall SEMICOLON
;

FunctionCall:
    ID L_PARENTHESIS ExpressionList R_PARENTHESIS
;

ExpressionList:
    Epsilon
    |
    Expressions
;

Expressions:
    Expression
    |
    Expressions COMMA Expression
;

StatementList:
    Epsilon
    |
    Statements
;

Statements:
    Statement
    |
    Statements Statement
;

Expression:
    L_PARENTHESIS Expression R_PARENTHESIS
    |
    MINUS Expression %prec UNARY_MINUS
    |
    Expression MULTIPLY Expression
    |
    Expression DIVIDE Expression
    |
    Expression MOD Expression
    |
    Expression PLUS Expression
    |
    Expression MINUS Expression
    |
    Expression LESS Expression
    |
    Expression LESS_OR_EQUAL Expression
    |
    Expression GREATER Expression
    |
    Expression GREATER_OR_EQUAL Expression
    |
    Expression EQUAL Expression
    |
    Expression NOT_EQUAL Expression
    |
    NOT Expression
    |
    Expression AND Expression
    |
    Expression OR Expression
    |
    LiteralConstant {
        $$ = $1;
    }
    |
    VariableReference
    |
    FunctionCall
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

int main(int argc, const char *argv[]) {
    CHECK(argc == 2, "Usage: ./parser <filename>\n");

    FILE *fp = fopen(argv[1], "r");

    CHECK(fp != NULL, "fopen() fails.\n");
    yyin = fp;
    yyparse();

    //freeProgramNode(root);
    DumpVisitor dvisitor;
    root->accept(dvisitor);
    t->accept(dvisitor);
    //t2->accept(dvisitor);

    //std::cout << "CPP works!" << std::endl;
    printf("\n"
           "|--------------------------------|\n"
           "|  There is no syntactic error!  |\n"
           "|--------------------------------|\n");
    return 0;
}
