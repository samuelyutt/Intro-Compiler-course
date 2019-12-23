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

int lvl = 0;
int kindstatus = 0;
int fromfunc = 0;
SymbolEntry* curEntry;
SymbolTable* curTable;
SymbolManager* curManager = new SymbolManager();

//
// TODO: implementations of visit(xxxxNode *)
//
void dumpDemarcation(const char chr) {
    for (size_t i = 0; i < 110; ++i) {
        printf("%c", chr);
    }
    puts("");
}

void SemanticAnalyzer::visit(ProgramNode *m) {
    SymbolTable* table = new SymbolTable();
    curTable = table;

    SymbolEntry* entry = new SymbolEntry();
    curEntry = entry;
    curEntry->name = m->program_name.substr(0, 31);
    curEntry->kind = "program";
    curEntry->level = lvl;
    curEntry->type = "void";
    curTable->addSymbol(*curEntry);

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
    

    if (m->compound_statement_node != nullptr)
        m->compound_statement_node->accept(*this);

    ////////
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
	SymbolEntry* entry = new SymbolEntry();
	curEntry = entry;
	curEntry->name = m->variable_name.substr(0, 31);
	curEntry->kind = kindstatus==0?"variable":"parameter";
	curEntry->level = lvl;
	curEntry->type = m->getTypeForTable();

    if (m->constant_value_node != nullptr)
        m->constant_value_node->accept(*this);

    curTable->addSymbol(*curEntry);
}

void SemanticAnalyzer::visit(ConstantValueNode *m) {
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

void SemanticAnalyzer::visit(FunctionNode *m) {
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
    
    lvl++;
    SymbolTable* table = new SymbolTable();
    curTable = table;
    kindstatus = 1;

    if (m->parameters != nullptr)
        for(uint i=0; i< m->parameters->size(); i++){
            (*(m->parameters))[i]->node->accept(*this);
        }

    kindstatus = 0;    

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
        curManager->popScope();
        curTable = &curManager->tables.top();
        ////////
        lvl--;
}

void SemanticAnalyzer::visit(AssignmentNode *m) {}

void SemanticAnalyzer::visit(PrintNode *m) {}

void SemanticAnalyzer::visit(ReadNode *m) {}

void SemanticAnalyzer::visit(VariableReferenceNode *m) {}

void SemanticAnalyzer::visit(BinaryOperatorNode *m) {}

void SemanticAnalyzer::visit(UnaryOperatorNode *m) {}

void SemanticAnalyzer::visit(IfNode *m) {
        if (m->condition != nullptr)
            m->condition->accept(*this);

        if (m->body != nullptr)
            for(uint i=0; i< m->body->size(); i++)
                (*(m->body))[i]->accept(*this);

        if (m->body_of_else != nullptr){
            this->print_space();
            std::cout<<"else"<<std::endl;

            this->space_counter_increase();
                for(uint i=0; i< m->body_of_else->size(); i++)
                    (*(m->body_of_else))[i]->accept(*this);
            this->space_counter_decrease();
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

void SemanticAnalyzer::visit(ReturnNode *m) {}

void SemanticAnalyzer::visit(FunctionCallNode *m) {}
