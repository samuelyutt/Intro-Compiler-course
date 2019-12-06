#include <iostream>
#include "AST/binaryoperator.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
BinaryOperatorNode::BinaryOperatorNode(uint32_t line, uint32_t col): ExpressionNode(line,col){
}

void BinaryOperatorNode::printNode(){
    DumpVisitor dvisitor;
	cout << "binary operator <line: " << location.line << ", col: " << location.col << "> " << 
	op << endl;
    leftOperand->accept(dvisitor);
    rightOperand->accept(dvisitor);
}

BinaryOperatorNode::~BinaryOperatorNode(){
    ;
}

void BinaryOperatorNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
