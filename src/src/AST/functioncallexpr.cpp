#include <iostream>
#include "AST/functioncallexpr.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
FunctionCallExprNode::FunctionCallExprNode(uint32_t line, uint32_t col): ExpressionNode(line,col){
}

void FunctionCallExprNode::printNode(){
	tabcount++;
    tab(tabcount);
    DumpVisitor dvisitor;
	cout << "function call statement <line: " << location.line << ", col: " << location.col << "> " << 
	name << endl;
    for (auto expressionNode: v_expressionNode) {
    	expressionNode->accept(dvisitor);
    }
	tabcount--;
}

FunctionCallExprNode::~FunctionCallExprNode(){
    ;
}

void FunctionCallExprNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
