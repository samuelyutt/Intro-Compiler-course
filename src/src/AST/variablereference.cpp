#include <iostream>
#include "AST/variablereference.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
VariableReferenceNode::VariableReferenceNode(uint32_t line, uint32_t col): ExpressionNode(line,col){
}

void VariableReferenceNode::printNode(){
    DumpVisitor dvisitor;
	cout << "variable reference <line: " << location.line << ", col: " << location.col << "> " << 
	name << endl;
	for (auto expressionNode: v_expressionNode) {
		cout << "[" << endl;
    	expressionNode->accept(dvisitor);
    	cout << "]" << endl;
    }
}

VariableReferenceNode::~VariableReferenceNode(){
    ;
}

void VariableReferenceNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
