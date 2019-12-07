#include <iostream>
#include "AST/assignment.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
AssignmentNode::AssignmentNode(uint32_t line, uint32_t col): StatementNode(line,col){
}

void AssignmentNode::printNode(){
    DumpVisitor dvisitor;
	cout << "assignment statement <line: " << location.line << ", col: " << location.col << "> " << endl;
    lvalue->accept(dvisitor);
    expression->accept(dvisitor);
}

AssignmentNode::~AssignmentNode(){
    ;
}

void AssignmentNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
