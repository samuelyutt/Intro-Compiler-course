#include "visitor/dumpvisitor.hpp"

void DumpVisitor::visit(ProgramNode *e)
{
    e->printNode();
}

void DumpVisitor::visit(DeclarationNode *e)
{
    e->printNode();
}

void DumpVisitor::visit(ConstantValueNode *e)
{
    e->printNode();
}

void DumpVisitor::visit(VariableNode *e)
{
    e->printNode();
}

void DumpVisitor::visit(ProgramBodyNode *e)
{
    e->printNode();
}

void DumpVisitor::visit(ExpressionNode *e)
{
    e->printNode();
}

void DumpVisitor::visit(VariableReferenceNode *e)
{
    e->printNode();
}

void DumpVisitor::visit(BinaryOperatorNode *e)
{
    e->printNode();
}

void DumpVisitor::visit(UnaryOperatorNode *e)
{
    e->printNode();
}

void DumpVisitor::visit(FunctionCallExprNode *e)
{
    e->printNode();
}