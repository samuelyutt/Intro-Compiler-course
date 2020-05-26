#include <iostream>
#include "AST/constantvalue.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
ConstantValueNode::ConstantValueNode(uint32_t line, uint32_t col): ExpressionNode(line,col){
}

void ConstantValueNode::printNode(){
	tabcount++;
    tab(tabcount);
	cout << "constant <line: " << location.line << ", col: " << location.col << "> " << 
	constant_value << endl;
	tabcount--;
}

ConstantValueNode::~ConstantValueNode(){
    ;
}

void ConstantValueNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
