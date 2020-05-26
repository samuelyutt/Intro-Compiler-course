#include <iostream>
#include "AST/unaryoperator.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
UnaryOperatorNode::UnaryOperatorNode(uint32_t line, uint32_t col): ExpressionNode(line,col){
}

void UnaryOperatorNode::printNode(){
	tabcount++;
    tab(tabcount);
    DumpVisitor dvisitor;
	cout << "unary operator <line: " << location.line << ", col: " << location.col << "> " << 
	op << endl;
    operand->accept(dvisitor);
	tabcount--;
}

UnaryOperatorNode::~UnaryOperatorNode(){
    ;
}

void UnaryOperatorNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
