#include <iostream>
#include "AST/arrtype.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
ArrTypeNode::ArrTypeNode(uint32_t line, uint32_t col): ASTNodeBase(line,col){
}

void ArrTypeNode::printNode(){
    DumpVisitor dvisitor;
	for (auto arrdeclarationNode: v_arrdeclarationNode) {
    	arrdeclarationNode->accept(dvisitor);
    }
}

ArrTypeNode::~ArrTypeNode(){
    ;
}

void ArrTypeNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
