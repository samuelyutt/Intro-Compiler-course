#include <iostream>
#include "AST/if.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
IfNode::IfNode(uint32_t line, uint32_t col): StatementNode(line,col){
}

void IfNode::printNode(){
	tabcount++;
    tab(tabcount);
    DumpVisitor dvisitor;
	cout << "if statement <line: " << location.line << ", col: " << location.col << "> " << endl;
    condition->accept(dvisitor);
    for (auto statementNode: body) {
    	statementNode->accept(dvisitor);
    }
    if (!body_of_else.empty()) {
    	tab(tabcount);
    	cout << "else" << endl;
    	for (auto statementNode: body_of_else) {
    		statementNode->accept(dvisitor);
    	}
    }
    tabcount--;
}

IfNode::~IfNode(){
    ;
}

void IfNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
