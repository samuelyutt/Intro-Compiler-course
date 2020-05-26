#include <iostream>
#include "AST/function.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
FunctionNode::FunctionNode(uint32_t line, uint32_t col): ASTNodeBase(line,col){
}

void FunctionNode::printNode(){
    tabcount++;
    tab(tabcount);
    DumpVisitor dvisitor;
	cout << "function declaration <line: " << location.line << ", col: " << location.col << "> " <<
    name << " " << return_type << " (";
    unsigned int j = 0;
    for (auto parameter : parameters) {
        std::vector<VariableNode*> v_variable = parameter->v_variableNode;
        unsigned int i = 0;
        for (auto variable : v_variable) {
            cout << variable->type;
            if (variable->arrTypeNode != NULL) {
                ArrTypeNode* arrType = variable->arrTypeNode;
                std::vector<ArrDeclarationNode*> v_arrdeclaration = arrType->v_arrdeclarationNode;
                for (auto arrdeclaration : v_arrdeclaration) {
                    cout << "[" << arrdeclaration->bgn << "]";
                }
            }
            i++;
            if (i < v_variable.size()) cout << ", ";
        }
        j++;
        if (j < parameters.size()) cout << ", ";
    }
    cout << ")" << endl;
    for (auto parameter : parameters) {
        parameter->accept(dvisitor);
    }
    body->accept(dvisitor);
    tabcount--;
}

FunctionNode::~FunctionNode(){
    ;
}

void FunctionNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
