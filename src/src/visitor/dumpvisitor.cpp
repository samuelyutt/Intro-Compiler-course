#include "visitor/dumpvisitor.hpp"

void DumpVisitor::visit(ProgramNode *e)
{
    e->printNode();
}