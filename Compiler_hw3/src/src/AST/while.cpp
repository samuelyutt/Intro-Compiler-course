#include <iostream>
#include "AST/while.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
WhileNode::WhileNode(uint32_t line, uint32_t col): StatementNode(line,col){
}

void WhileNode::printNode(){
	tabcount++;
    tab(tabcount);
    DumpVisitor dvisitor;
	cout << "while statement <line: " << location.line << ", col: " << location.col << "> " << endl;
    condition->accept(dvisitor);
    for (auto statementNode: body) {
    	statementNode->accept(dvisitor);
    }
	tabcount--;
}

WhileNode::~WhileNode(){
    ;
}

void WhileNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
