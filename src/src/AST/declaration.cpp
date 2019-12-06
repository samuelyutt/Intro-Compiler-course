#include <iostream>
#include "AST/declaration.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
DeclarationNode::DeclarationNode(uint32_t line, uint32_t col): ASTNodeBase(line,col){
}

void DeclarationNode::printNode(){
    DumpVisitor dvisitor;
	cout << "declaration <line: " << location.line << ", col: " << location.col << ">" << endl;	
    for (auto variableNode: v_variableNode) {
    	variableNode->accept(dvisitor);
    }
}

DeclarationNode::~DeclarationNode(){
    ;
}

void DeclarationNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
