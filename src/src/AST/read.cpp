#include <iostream>
#include "AST/read.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
ReadNode::ReadNode(uint32_t line, uint32_t col): StatementNode(line,col){
}

void ReadNode::printNode(){
	tabcount++;
    tab(tabcount);
    DumpVisitor dvisitor;
	cout << "read statement <line: " << location.line << ", col: " << location.col << "> " << endl;
    target->accept(dvisitor);
	tabcount--;
}

ReadNode::~ReadNode(){
    ;
}

void ReadNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
