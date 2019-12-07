#include <iostream>
#include "AST/variablereference.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
VariableReferenceNode::VariableReferenceNode(uint32_t line, uint32_t col): ExpressionNode(line,col){
}

void VariableReferenceNode::printNode(){
	tabcount++;
    tab(tabcount);
    DumpVisitor dvisitor;
	cout << "variable reference <line: " << location.line << ", col: " << location.col << "> " << 
	name << endl;
	for (auto expressionNode: v_expressionNode) {
    	tab(tabcount);
		cout << "[" << endl;
    	expressionNode->accept(dvisitor);
    	tab(tabcount);
    	cout << "]" << endl;
    }
	tabcount--;
}

VariableReferenceNode::~VariableReferenceNode(){
    ;
}

void VariableReferenceNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
