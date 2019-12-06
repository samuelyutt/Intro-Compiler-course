#include <iostream>
#include "AST/functioncallexpr.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
FunctionCallExprNode::FunctionCallExprNode(uint32_t line, uint32_t col): ExpressionNode(line,col){
}

void FunctionCallExprNode::printNode(){
    DumpVisitor dvisitor;
	cout << "function call statement <line: " << location.line << ", col: " << location.col << "> " << 
	name << endl;
    for (auto expressionNode: v_expressionNode) {
    	expressionNode->accept(dvisitor);
    }
}

FunctionCallExprNode::~FunctionCallExprNode(){
    ;
}

void FunctionCallExprNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
