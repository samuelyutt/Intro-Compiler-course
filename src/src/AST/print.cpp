#include <iostream>
#include "AST/print.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
PrintNode::PrintNode(uint32_t line, uint32_t col): StatementNode(line,col){
}

void PrintNode::printNode(){
	tabcount++;
    tab(tabcount);
    DumpVisitor dvisitor;
	cout << "print statement <line: " << location.line << ", col: " << location.col << "> " << endl;
    target->accept(dvisitor);
	tabcount--;
}

PrintNode::~PrintNode(){
    ;
}

void PrintNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
