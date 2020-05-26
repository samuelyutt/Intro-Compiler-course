#include <iostream>
#include "AST/declaration.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
DeclarationNode::DeclarationNode(uint32_t line, uint32_t col): ASTNodeBase(line,col){
}

void DeclarationNode::printNode(){
	tabcount++;
    tab(tabcount);
    DumpVisitor dvisitor;
	cout << "declaration <line: " << location.line << ", col: " << location.col << ">" << endl;	
    for (auto variableNode: v_variableNode) {
    	variableNode->accept(dvisitor);
    }
	tabcount--;
}

DeclarationNode::~DeclarationNode(){
    ;
}

void DeclarationNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
