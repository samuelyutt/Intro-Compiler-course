#include <iostream>
#include "AST/while.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
WhileNode::WhileNode(uint32_t line, uint32_t col): StatementNode(line,col){
}

void WhileNode::printNode(){
    DumpVisitor dvisitor;
	cout << "while statement <line: " << location.line << ", col: " << location.col << "> " << endl;
    condition->accept(dvisitor);
    for (auto statementNode: body) {
    	statementNode->accept(dvisitor);
    }
}

WhileNode::~WhileNode(){
    ;
}

void WhileNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
