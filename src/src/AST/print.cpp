#include <iostream>
#include "AST/print.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
PrintNode::PrintNode(uint32_t line, uint32_t col): StatementNode(line,col){
}

void PrintNode::printNode(){
    DumpVisitor dvisitor;
	cout << "print statement <line: " << location.line << ", col: " << location.col << "> " << endl;
    target->accept(dvisitor);
}

PrintNode::~PrintNode(){
    ;
}

void PrintNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
