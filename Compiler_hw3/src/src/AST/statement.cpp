#include "AST/statement.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

#include <iostream>
using namespace std;

StatementNode::StatementNode(uint32_t line, uint32_t col): ASTNodeBase(line,col){
}

void StatementNode::printNode(){
}

StatementNode::~StatementNode(){
    ;
}

void StatementNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}