#include <iostream>
#include "AST/assignment.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
AssignmentNode::AssignmentNode(uint32_t line, uint32_t col): StatementNode(line,col){
}

void AssignmentNode::printNode(){
    tabcount++;
    tab(tabcount);
    DumpVisitor dvisitor;
	cout << "assignment statement <line: " << location.line << ", col: " << location.col << "> " << endl;
    lvalue->accept(dvisitor);
    expression->accept(dvisitor);
    tabcount--;
}

AssignmentNode::~AssignmentNode(){
    ;
}

void AssignmentNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
