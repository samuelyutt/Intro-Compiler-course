#pragma once
#include "visitor/visitor.hpp"

class DumpVisitor : public ASTNodeVisitorBase
{
public:
    void visit(ProgramNode *e) override;
};