#pragma once
#include "AST/ast.hpp"
#include "AST/program.hpp"

class ASTNodeVisitorBase
{
public:
    virtual void visit(ProgramNode *e) = 0;
};