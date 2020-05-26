#include "semantic/SemanticAnalyzer.hpp"
#include "semantic/symboltable.hpp"
#include "AST/program.hpp"
#include "AST/declaration.hpp"
#include "AST/variable.hpp"
#include "AST/constant_value.hpp"
#include "AST/function.hpp"
#include "AST/compound_statement.hpp"
#include "AST/assignment.hpp"
#include "AST/print.hpp"
#include "AST/read.hpp"
#include "AST/variable_reference.hpp"
#include "AST/binary_operator.hpp"
#include "AST/unary_operator.hpp"
#include "AST/if.hpp"
#include "AST/while.hpp"
#include "AST/for.hpp"
#include "AST/return.hpp"
#include "AST/function_call.hpp"

#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include <cstring>

extern int32_t OptDmp;
extern FILE *fp;
extern string fname;

int lvl = 0;
int kindstatus = 0;
int fromfunc = 0, fromprgm = 0, fromDecl = 0, varRefErr = 0;
string retValType;
SymbolEntry* curEntry;
SymbolTable* curTable;
SymbolManager* curManager = new SymbolManager();
std::stack <string> exprType;

//
// TODO: implementations of visit(xxxxNode *)
//
void dumpDemarcation(const char chr) {
    for (size_t i = 0; i < 110; ++i) {
        printf("%c", chr);
    }
    puts("");
}

void dumpSymbolTable() {
    if (OptDmp) {
        SymbolTable tmpTable = curManager->tables.top();
        dumpDemarcation('=');
        printf("%-33s%-11s%-11s%-17s%-11s\n", "Name", "Kind", "Level", "Type", "Attribute");
        dumpDemarcation('-');
        for (uint i=0; i< tmpTable.entries.size(); i++) {
            printf("%-33s", tmpTable.entries[i].name.c_str());
            printf("%-11s", tmpTable.entries[i].kind.c_str());
            printf("%d%-10s", tmpTable.entries[i].level, tmpTable.entries[i].level==0?"(global)":"(local)");
            printf("%-17s", tmpTable.entries[i].type.c_str());
            printf("%-11s", tmpTable.entries[i].attribute.c_str());
            puts("");
        }
        dumpDemarcation('-');
    }
}

void dumpErr(int line, int col, int errnum, string param1, string param2, string param3) {
    fprintf(stderr, "<Error> Found in line %d, column %d: ", line, col);

    switch (errnum) {
        case 0:
            fprintf(stderr, "symbol '%s' is redeclared\n", param1.c_str());
            break;
        case 1:
            fprintf(stderr, "program name must be the same as filename\n");
            break;
        case 2:
            fprintf(stderr, "identifier at the end of program must be the same as identifier at the beginning of program\n");
            break;
        case 3:
            fprintf(stderr, "identifier at the end of function must be the same as identifier at the beginning of function\n");
            break;
        case 4:
            fprintf(stderr, "'%s' declared as an array with a lower bound greater or equal to upper bound\n", param1.c_str());
            break;
        case 5:
            fprintf(stderr, "use of undeclared identifier '%s'\n", param1.c_str());
            break;
        case 6:
            fprintf(stderr, "index of array reference must be an integer\n");
            break;
        case 7:
            fprintf(stderr, "there is an over array subscript\n");
            break;
        case 8:
            fprintf(stderr, "invalid operands to binary operation '%s' ('%s' and '%s')\n", param1.c_str(), param2.c_str(), param3.c_str());
            break;
        case 9:
            fprintf(stderr, "invalid operand to unary operation '%s' ('%s')\n", param1.c_str(), param2.c_str());
            break;
        case 10:
            fprintf(stderr, "program/procedure should not return a value\n");
            break;
        case 11:
            fprintf(stderr, "return '%s' from a function with return type '%s'\n", param1.c_str(), param2.c_str());
            break;

    }
    
    char errline[1000];
    int c = 0, cn = 0, ln = 0;
    fseek ( fp , 0 , SEEK_SET );
    while (ln != line-1 && c != EOF) {
        c = fgetc (fp);
        cn++;
        if (c == '\n') ln++;
    }
    fseek ( fp , cn , SEEK_SET );
    fgets (errline , 1000 , fp);
    fprintf(stderr, "%s", errline);
    for (int i=0; i < col-1; i++) fprintf(stderr, " ");
    fprintf(stderr, "^\n");
    
    return;
}

int reDeclCheck(string newSymbol) {
    for (uint i=0; i< curTable->entries.size(); i++) {
        if (curTable->entries[i].name == newSymbol)
            return 1;
    }
    return 0;
}

void SemanticAnalyzer::visit(ProgramNode *m) {
    if (m->program_name+".p" != fname) {
        dumpErr(m->line_number, m->col_number, 1, "", "", "");
    }
    if (m->program_name != m->end_name) {
        dumpErr(m->end_line_number, m->end_col_number, 2, "", "", "");
    }
    SymbolTable* table = new SymbolTable();
    curTable = table;
    if ( reDeclCheck(m->program_name.substr(0, 31)) ) {
        dumpErr(m->line_number, m->col_number, 0, m->program_name.c_str(), "", "");
    } else {
        SymbolEntry* entry = new SymbolEntry();
        curEntry = entry;
        curEntry->name = m->program_name.substr(0, 31);
        curEntry->kind = "program";
        curEntry->level = lvl;
        curEntry->type = "void";
        curTable->addSymbol(*curEntry);
    }

    if (m->declaration_node_list != nullptr) {
        for(uint i=0; i< m->declaration_node_list->size(); i++){
            (*(m->declaration_node_list))[i]->accept(*this);
        }
    }

    curManager->pushScope(*curTable);
    
    

    if (m->function_node_list != nullptr) {
        for(uint i=0; i< m->function_node_list->size(); i++){
            (*(m->function_node_list))[i]->accept(*this);
        }
    }
    
    fromprgm = 1;
    if (m->compound_statement_node != nullptr)
        m->compound_statement_node->accept(*this);
    fromprgm = 0;
    ////////
    dumpSymbolTable();
    curManager->popScope();
    ////////
}

void SemanticAnalyzer::visit(DeclarationNode *m) {
    if (m->variables_node_list != nullptr)
        for(uint i=0; i< m->variables_node_list->size(); i++){
            (*(m->variables_node_list))[i]->accept(*this);
        }
}

void SemanticAnalyzer::visit(VariableNode *m) {
    if ( reDeclCheck(m->variable_name.substr(0, 31)) ) {
        dumpErr(m->line_number, m->col_number, 0, m->variable_name.c_str(), "", "");
    } else {

    	SymbolEntry* entry = new SymbolEntry();
    	curEntry = entry;
    	curEntry->name = m->variable_name.substr(0, 31);
    	curEntry->kind = kindstatus==0?"variable":"parameter";
    	curEntry->level = lvl;
    	curEntry->type = m->getTypeForTable();

        if (!m->isArrRangeAvbl()) {
            dumpErr(m->line_number, m->col_number, 4, m->variable_name.c_str(), "", "");
        }

        fromDecl = 1;
        if (m->constant_value_node != nullptr)
            m->constant_value_node->accept(*this);
        fromDecl = 0;

        curTable->addSymbol(*curEntry);
    }

    
}

void SemanticAnalyzer::visit(ConstantValueNode *m) {
    if (varRefErr == 1) {
        dumpErr(m->line_number, m->col_number, 6, "", "", "");
        varRefErr = 2;
        return;
    } else if (varRefErr == 2) {
        return;
    }

    if (fromDecl) {
    	curEntry->kind = "constant";
        switch(m->constant_value->type){
            case TYPE_INTEGER: curEntry->attribute = to_string(m->constant_value->int_literal); break;
            case TYPE_REAL:    curEntry->attribute = to_string(m->constant_value->real_literal); break;
            case TYPE_STRING:  curEntry->attribute = m->constant_value->string_literal; break;
            case TYPE_BOOLEAN:
                switch(m->constant_value->boolean_literal){
                    case Boolean_TRUE:  curEntry->attribute = "true"; break;
                    case Boolean_FALSE: curEntry->attribute = "false"; break;
                    default: curEntry->attribute = "unknown"; break;
                } 
                break;
            default: curEntry->attribute = "unknown"; break;
        }
    }

    string type;
    switch(m->constant_value->type){
        case TYPE_INTEGER: type = "integer"; break;
        case TYPE_REAL:    type = "real"; break;
        case TYPE_STRING:  type = "string"; break;
        case TYPE_BOOLEAN: type = "boolean"; break;
        default: type = "unknown"; break;
    }
    exprType.push(type);
    
}

void SemanticAnalyzer::visit(FunctionNode *m) {
    if (m->function_name != m->end_name) {
        dumpErr(m->end_line_number, m->end_col_number, 3, "", "", "");
    }
    if ( reDeclCheck(m->function_name.substr(0, 31)) ) {
        dumpErr(m->line_number, m->col_number, 0, m->function_name.c_str(), "", "");
    } else {
        SymbolEntry* entry = new SymbolEntry();
        curEntry = entry;
        curEntry->name = m->function_name.substr(0, 31);
        curEntry->kind = "function";
        curEntry->level = lvl;
    
        switch(m->return_type->type_set){
            case SET_SCALAR:
                switch(m->return_type->type){
                    case TYPE_INTEGER: curEntry->type = "integer"; break;
                    case TYPE_REAL:    curEntry->type = "real"; break;
                    case TYPE_STRING:  curEntry->type = "string"; break;
                    case TYPE_BOOLEAN: curEntry->type = "boolean"; break;
                    default:           curEntry->type = "unknown"; break;
                }
                break;
            case UNKNOWN_SET:
                switch(m->return_type->type){
                    case TYPE_VOID: curEntry->type = "void"; break;
                    default:        curEntry->type = "unknown"; break;
                }
                break;
            default: curEntry->type = "unknown"; break; break;
        }
        for(uint i=0; i<m->prototype.size(); i++){
            if(i != 0) curEntry->attribute += ", ";
            switch(m->prototype[i]->type_set){
                case SET_SCALAR:
                case SET_CONSTANT_LITERAL:
                    switch(m->prototype[i]->type){
                        case TYPE_INTEGER: curEntry->attribute += "integer"; break;
                        case TYPE_REAL:    curEntry->attribute += "real"; break;
                        case TYPE_STRING:  curEntry->attribute += "string"; break;
                        case TYPE_BOOLEAN: curEntry->attribute += "boolean"; break;
                        default:           curEntry->attribute += "unknown"; break;
                    }
                    break;
                case SET_ACCUMLATED:
                    switch(m->prototype[i]->type){
                        case TYPE_INTEGER: curEntry->attribute += "integer"; break;
                        case TYPE_REAL:    curEntry->attribute += "real"; break;
                        case TYPE_STRING:  curEntry->attribute += "string"; break;
                        case TYPE_BOOLEAN: curEntry->attribute += "boolean"; break;
                        default:           curEntry->attribute += "unknown"; break;
                    }

                    for(uint j=0; j<m->prototype[i]->array_range.size(); j++){
                        if (j==0) curEntry->attribute += " ";
                        curEntry->attribute += "[";
                        curEntry->attribute += to_string(m->prototype[i]->array_range[j].end-m->prototype[i]->array_range[j].start);
                        curEntry->attribute += "]";
                    }
                    break;
                default: curEntry->attribute += "unknown"; break;
            }
        }
        curManager->tables.top().addSymbol(*curEntry);
    }
    
    lvl++;
    SymbolTable* table = new SymbolTable();
    curTable = table;
    kindstatus = 1;

    if (m->parameters != nullptr)
        for(uint i=0; i< m->parameters->size(); i++){
            (*(m->parameters))[i]->node->accept(*this);
        }

    kindstatus = 0; 

    switch(m->return_type->type_set){
        case SET_SCALAR:
            switch(m->return_type->type){
                case TYPE_INTEGER: retValType = "integer"; break;
                case TYPE_REAL:    retValType = "real"; break;
                case TYPE_STRING:  retValType = "string"; break;
                case TYPE_BOOLEAN: retValType = "boolean"; break;
                default:           retValType = "unknown"; break;
            }
            break;
        case UNKNOWN_SET:
            switch(m->return_type->type){
                case TYPE_VOID: retValType = "void"; break;
                default:        retValType = "unknown"; break;
            }
            break;
        default: retValType = "unknown"; break; break;
    }

    fromfunc = 1;
    if (m->body != nullptr)
        m->body->accept(*this);
    fromfunc = 0;
    
}

void SemanticAnalyzer::visit(CompoundStatementNode *m) {
    if (!fromfunc) {
        lvl++;
        SymbolTable* table = new SymbolTable();
        curTable = table;
    }
    fromfunc = 0;

    if (m->declaration_node_list != nullptr)
        for(uint i=0; i< m->declaration_node_list->size(); i++){
            (*(m->declaration_node_list))[i]->accept(*this);
        }
    curManager->pushScope(*curTable);

    if (m->statement_node_list != nullptr)
        for(uint i=0; i< m->statement_node_list->size(); i++){
            (*(m->statement_node_list))[i]->accept(*this);
        }

    

    ////////
    dumpSymbolTable();
    curManager->popScope();
    curTable = &curManager->tables.top();
    ////////
    lvl--;
}

void SemanticAnalyzer::visit(AssignmentNode *m) {
    if (m->variable_reference_node != nullptr)
        m->variable_reference_node->accept(*this);
    
    if (m->expression_node != nullptr)
        m->expression_node->accept(*this);
}

void SemanticAnalyzer::visit(PrintNode *m) {
    if (m->expression_node != nullptr)
        m->expression_node->accept(*this);
}

void SemanticAnalyzer::visit(ReadNode *m) {
    if (m->variable_reference_node != nullptr)
        m->variable_reference_node->accept(*this);   
}

void SemanticAnalyzer::visit(VariableReferenceNode *m) {
    if (varRefErr == 1) {
        dumpErr(m->line_number, m->col_number, 6, "", "", "");
        varRefErr = 2;
        return;
    } else if (varRefErr == 2) {
        return;
    }
    
    int inTable = 0, subscript = 0;
    std::stack <SymbolTable> tmpTables = curManager->tables;
    char type[100], newtype[100];
    while (!tmpTables.empty() && !inTable) {
        SymbolTable tmpTable = tmpTables.top();
        for (uint i=0; i< tmpTable.entries.size() && !inTable; i++) {
            if(tmpTable.entries[i].name == m->variable_name) {
                inTable = 1;
                //type = tmpTable.entries[i].type;
                strcpy(type, tmpTable.entries[i].type.c_str());
                for (int j=0; j<strlen(type); j++) {
                    if (type[j] == '[')
                        subscript++;
                }
                int count = 0, apnd = 1, nodes = 0, k = 0;
                if (m->expression_node_list != nullptr)
                    nodes = m->expression_node_list->size();
                for (int j=0; j<strlen(type); j++) {
                    if (type[j] == '[') {
                        if (count < nodes)
                            apnd = 0;
                        else
                            apnd = 1;
                    } else if (type[j] == ']') {
                        count++;
                    }
                    if (apnd) {
                        newtype[k++] = type[j];
                    }
                }
                //newtype.append("\0");
                if (newtype[k-1] == ' ') newtype[k-1] = '\0';
                else newtype[k] = '\0';
                //std::cout << newtype;
            }
        }
        tmpTables.pop();
    }
    if (!inTable) {
        dumpErr(m->line_number, m->col_number, 5, m->variable_name.c_str(), "", "");
    } else {
        if (m->expression_node_list != nullptr) {
            if (subscript < m->expression_node_list->size()) {
                dumpErr(m->line_number, m->col_number, 7, "", "", "");
                exprType.push("error");
            } else {
                int subscriptAvbl = 1;
                for(uint i=0; i< m->expression_node_list->size(); i++){
                    (*(m->expression_node_list))[i]->accept(*this);
                    if (exprType.top() == "error") {
                        subscriptAvbl = 0;
                        break;
                    } else if (exprType.top() != "integer") {
                        varRefErr = 1;
                        (*(m->expression_node_list))[i]->accept(*this);
                        varRefErr = 0;
                        subscriptAvbl = 0;
                    }
                }
                if (subscriptAvbl && subscript >= m->expression_node_list->size()) {
                    exprType.push(newtype);
                } else {
                    exprType.push("error");
                }
            }
        } else {
            exprType.push(newtype);
        }
    }
}

void SemanticAnalyzer::visit(BinaryOperatorNode *m) {
    if (m->left_operand != nullptr)
        m->left_operand->accept(*this);

    string leftType = exprType.top();
    exprType.pop();

    if (m->right_operand != nullptr)
        m->right_operand->accept(*this);

    string rightType = exprType.top();
    exprType.pop();

    if (varRefErr)
        return;

    string strop;
    switch(m->op){
        case OP_OR:               strop = "or"; break;
        case OP_AND:              strop = "and"; break;
        case OP_LESS:             strop = "<"; break;
        case OP_LESS_OR_EQUAL:    strop = "<="; break;
        case OP_EQUAL:            strop = "="; break;
        case OP_GREATER:          strop = ">"; break;
        case OP_GREATER_OR_EQUAL: strop = ">="; break;
        case OP_NOT_EQUAL:        strop = "<>"; break;
        case OP_PLUS:             strop = "+"; break;
        case OP_MINUS:            strop = "-"; break;
        case OP_MULTIPLY:         strop = "*"; break;
        case OP_DIVIDE:           strop = "/"; break;
        case OP_MOD:              strop = "mod"; break;
        default:                  strop = "unknown"; break;
    }
    if (leftType == "error" || rightType == "error") {
        exprType.push("error");
    } else {
        switch(m->op){
            case OP_PLUS:
                if ( leftType == "string" && rightType == "string" ) {
                    exprType.push("string");
                    break;
                }
            case OP_MINUS:
            case OP_MULTIPLY:
            case OP_DIVIDE:
                if ( leftType == "integer" && rightType == "integer" ) {
                    exprType.push("integer");
                } else if ( leftType == "real" && rightType == "real" ) {
                    exprType.push("real");
                } else if ( (leftType == "real" && rightType == "integer") ||
                            (leftType == "integer" && rightType == "real") ) {
                    exprType.push("real");
                } else {
                    dumpErr(m->line_number, m->col_number, 8, strop, leftType, rightType);
                    exprType.push("error");
                }
                break;

            case OP_MOD:
                if ( leftType == "integer" && rightType == "integer" ) {
                    exprType.push("integer");
                } else {
                    dumpErr(m->line_number, m->col_number, 8, strop, leftType, rightType);
                    exprType.push("error");
                }
                break;

            case OP_OR:
            case OP_AND:
                if ( leftType == "boolean" || rightType == "boolean" ) {
                    exprType.push("boolean");
                } else {
                    dumpErr(m->line_number, m->col_number, 8, strop, leftType, rightType);
                    exprType.push("error");
                }
                break;
            case OP_LESS:
            case OP_LESS_OR_EQUAL:
            case OP_EQUAL:
            case OP_GREATER:
            case OP_GREATER_OR_EQUAL:
            case OP_NOT_EQUAL:
                if ( (leftType == "integer" || leftType == "real") && 
                     (rightType == "integer" || rightType == "real") ) {
                    exprType.push("boolean");
                } else {
                    dumpErr(m->line_number, m->col_number, 8, strop, leftType, rightType);
                    exprType.push("error");
                }
                break;

            default:
                exprType.push("error");
                break;
        }
    }
}

void SemanticAnalyzer::visit(UnaryOperatorNode *m) {
    if (m->operand != nullptr)
        m->operand->accept(*this);

    if (varRefErr)
        return;

    string operandType = exprType.top();
    switch(m->op){
        case OP_NOT:
            if (operandType != "boolean") {
                dumpErr(m->line_number, m->col_number, 9, "not", operandType, "");
                exprType.pop();
                exprType.push("error");
            }
            break;
        case OP_MINUS:
            if (operandType != "integer" && operandType != "real") {
                dumpErr(m->line_number, m->col_number, 9, "-", operandType, "");
                exprType.pop();
                exprType.push("error");
            }
            break;
        default:
            //std::cout<<"unknown";
            break;
    }
}

void SemanticAnalyzer::visit(IfNode *m) {
    if (m->condition != nullptr)
        m->condition->accept(*this);

    if (m->body != nullptr)
        for(uint i=0; i< m->body->size(); i++)
            (*(m->body))[i]->accept(*this);

    if (m->body_of_else != nullptr){
        for(uint i=0; i< m->body_of_else->size(); i++)
            (*(m->body_of_else))[i]->accept(*this);
    }
}

void SemanticAnalyzer::visit(WhileNode *m) {
    if (m->condition != nullptr)
        m->condition->accept(*this);

    if (m->body != nullptr)
        for(uint i=0; i< m->body->size(); i++)
            (*(m->body))[i]->accept(*this);
}

void SemanticAnalyzer::visit(ForNode *m) {
    if (m->loop_variable_declaration != nullptr)
        m->loop_variable_declaration->accept(*this);
    
    if (m->initial_statement != nullptr)
        m->initial_statement->accept(*this);

    if (m->condition != nullptr)
        m->condition->accept(*this);

    if (m->body != nullptr)
        for(uint i=0; i< m->body->size(); i++)
            (*(m->body))[i]->accept(*this);
}

void SemanticAnalyzer::visit(ReturnNode *m) {
    if (fromprgm) {
        dumpErr(m->line_number, m->col_number, 10, "", "", "");
        return;
    }
    if (m->return_value != nullptr)
        m->return_value->accept(*this);
    if (exprType.top().c_str() != retValType && exprType.top() != "error") {
        dumpErr(m->line_number, m->col_number+7, 11, exprType.top().c_str(), retValType, "");
    }
}

void SemanticAnalyzer::visit(FunctionCallNode *m) {
    if (varRefErr == 1) {
        dumpErr(m->line_number, m->col_number, 6, "", "", "");
        varRefErr = 2;
        return;
    } else if (varRefErr == 2) {
        return;
    }
    
    if (m->arguments != nullptr)
        for(uint i=0; i< m->arguments->size(); i++)
            (*(m->arguments))[i]->accept(*this);
}
