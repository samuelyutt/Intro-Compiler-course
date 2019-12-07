#include <iostream>
#include "AST/functioninvokation.hpp"
#include "visitor/visitor.hpp"
#include "visitor/dumpvisitor.hpp"

using namespace std;
extern int tabcount;
extern void tab(int count);
FunctionInvokationNode::FunctionInvokationNode(uint32_t line, uint32_t col): StatementNode(line,col){
}

void FunctionInvokationNode::printNode(){
	tabcount++;
    tab(tabcount);
    DumpVisitor dvisitor;
	cout << "function call statement <line: " << location.line << ", col: " << location.col << "> " << 
	name << endl;
    for (auto expressionNode: v_expressionNode) {
    	expressionNode->accept(dvisitor);
    }
	tabcount--;
}

FunctionInvokationNode::~FunctionInvokationNode(){
    ;
}

void FunctionInvokationNode::accept(ASTNodeVisitorBase &v){
    v.visit(this);
}
