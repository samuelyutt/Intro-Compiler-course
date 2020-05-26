#include <iostream>
#include "AST/for.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
ForNode::ForNode(uint32_t line, uint32_t col): StatementNode(line,col){
}

void ForNode::printNode(){
    tabcount++;
    tab(tabcount);
    DumpVisitor dvisitor;
	cout << "for statement <line: " << location.line << ", col: " << location.col << "> " << endl;
    loop_var_decl->accept(dvisitor);
    init_assignment->accept(dvisitor);
    condition->accept(dvisitor);
    for (auto statementNode: body) {
    	statementNode->accept(dvisitor);
    }
    tabcount--;
}

ForNode::~ForNode(){
    ;
}

void ForNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
