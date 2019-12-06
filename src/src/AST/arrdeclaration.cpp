#include <iostream>
#include "AST/arrdeclaration.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
ArrDeclarationNode::ArrDeclarationNode(uint32_t line, uint32_t col): ASTNodeBase(line,col){
}

void ArrDeclarationNode::printNode(){
    DumpVisitor dvisitor;
	cout << "[" << bgn << "..." << end << "]";
}

ArrDeclarationNode::~ArrDeclarationNode(){
    ;
}

void ArrDeclarationNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
