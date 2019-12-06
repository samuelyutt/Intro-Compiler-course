#include <iostream>
#include "AST/unaryoperator.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
UnaryOperatorNode::UnaryOperatorNode(uint32_t line, uint32_t col): ExpressionNode(line,col){
}

void UnaryOperatorNode::printNode(){
    DumpVisitor dvisitor;
	cout << "unary operator <line: " << location.line << ", col: " << location.col << "> " << 
	op << endl;
    operand->accept(dvisitor);
}

UnaryOperatorNode::~UnaryOperatorNode(){
    ;
}

void UnaryOperatorNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
