#include <iostream>
#include "AST/compoundstmt.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
CompoundStmtNode::CompoundStmtNode(uint32_t line, uint32_t col): StatementNode(line,col){
}

void CompoundStmtNode::printNode(){
    DumpVisitor dvisitor;
    tabcount++;
    tab(tabcount);
	cout << "compound statement <line: " << location.line << ", col: " << location.col << "> " << endl;
	for (auto declarationNode: v_declarationNode) {
    	declarationNode->accept(dvisitor);
    }
    for (auto statementNode: v_statementNode) {
    	statementNode->accept(dvisitor);
    }
    tabcount--;
}

CompoundStmtNode::~CompoundStmtNode(){
    ;
}

void CompoundStmtNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
