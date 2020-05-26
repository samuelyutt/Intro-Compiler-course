#include <iostream>
#include "AST/variable.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
VariableNode::VariableNode(uint32_t line, uint32_t col): ASTNodeBase(line,col){
}

void VariableNode::printNode(){
	tabcount++;
    tab(tabcount);
    DumpVisitor dvisitor;
	cout << "variable <line: " << location.line << ", col: " << location.col << "> " << 
	name << " " << type;
	if (arrTypeNode != NULL) {
	    arrTypeNode->accept(dvisitor);
	}
	cout << endl;
	if (constantValueNode != NULL) {
	    constantValueNode->accept(dvisitor);
	}
	tabcount--;
}

VariableNode::~VariableNode(){
    ;
}

void VariableNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
