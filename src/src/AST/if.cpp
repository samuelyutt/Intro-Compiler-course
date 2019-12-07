#include <iostream>
#include "AST/if.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
IfNode::IfNode(uint32_t line, uint32_t col): StatementNode(line,col){
}

void IfNode::printNode(){
    DumpVisitor dvisitor;
	cout << "if statement <line: " << location.line << ", col: " << location.col << "> " << endl;
    condition->accept(dvisitor);
    for (auto statementNode: body) {
    	statementNode->accept(dvisitor);
    }
    if (!body_of_else.empty()) cout << "else" << endl;
    for (auto statementNode: body_of_else) {
    	statementNode->accept(dvisitor);
    }
}

IfNode::~IfNode(){
    ;
}

void IfNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
