#include <iostream>
#include "AST/return.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
ReturnNode::ReturnNode(uint32_t line, uint32_t col): StatementNode(line,col){
}

void ReturnNode::printNode(){
    DumpVisitor dvisitor;
	cout << "return statement <line: " << location.line << ", col: " << location.col << "> " << endl;
    return_value->accept(dvisitor);
}

ReturnNode::~ReturnNode(){
    ;
}

void ReturnNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
