#include <iostream>
#include "AST/binaryoperator.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
extern int tabcount;
extern void tab(int count);
BinaryOperatorNode::BinaryOperatorNode(uint32_t line, uint32_t col): ExpressionNode(line,col){
}

void BinaryOperatorNode::printNode(){
    tabcount++;
    tab(tabcount);
    DumpVisitor dvisitor;
	cout << "binary operator <line: " << location.line << ", col: " << location.col << "> " << 
	op << endl;
    leftOperand->accept(dvisitor);
    rightOperand->accept(dvisitor);
    tabcount--;
}

BinaryOperatorNode::~BinaryOperatorNode(){
    ;
}

void BinaryOperatorNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
