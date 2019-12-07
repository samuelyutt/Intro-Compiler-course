#include <iostream>
#include "AST/programbody.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
ProgramBodyNode::ProgramBodyNode(uint32_t line, uint32_t col): ASTNodeBase(line,col){
}

void ProgramBodyNode::printNode(){
	//cout << "program <line: " << location.line << ", col: " << location.col << "> " << name << " void" << endl;
    DumpVisitor dvisitor;
	for (auto declarationNode: v_declarationNode) {
    	declarationNode->accept(dvisitor);
    }
    // for (auto declarationNode: v_declarationNode) {
    // 	declarationNode->accept(dvisitor);
    // }
    if (compoundStmtNode != NULL) {
	    compoundStmtNode->accept(dvisitor);
	}
}

ProgramBodyNode::~ProgramBodyNode(){
    ;
}

void ProgramBodyNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
