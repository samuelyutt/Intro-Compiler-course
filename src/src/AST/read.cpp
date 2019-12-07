#include <iostream>
#include "AST/read.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
ReadNode::ReadNode(uint32_t line, uint32_t col): StatementNode(line,col){
}

void ReadNode::printNode(){
    DumpVisitor dvisitor;
	cout << "read statement <line: " << location.line << ", col: " << location.col << "> " << endl;
    target->accept(dvisitor);
}

ReadNode::~ReadNode(){
    ;
}

void ReadNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
