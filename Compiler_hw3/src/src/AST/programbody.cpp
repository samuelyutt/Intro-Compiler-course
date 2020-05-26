#include <iostream>
#include "AST/programbody.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
ProgramBodyNode::ProgramBodyNode(uint32_t line, uint32_t col): ASTNodeBase(line,col){
}

void ProgramBodyNode::printNode(){
    DumpVisitor dvisitor;
	for (auto declarationNode: v_declarationNode) {
    	declarationNode->accept(dvisitor);
    }
    for (auto functionNode: v_functionNode) {
    	functionNode->accept(dvisitor);
    }
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
