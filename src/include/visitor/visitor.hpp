#pragma once
#include "AST/ast.hpp"
#include "AST/program.hpp"
#include "AST/declaration.hpp"
#include "AST/constantvalue.hpp"
#include "AST/variable.hpp"
#include "AST/programbody.hpp"
#include "AST/expression.hpp"
#include "AST/variablereference.hpp"
#include "AST/binaryoperator.hpp"

class ASTNodeVisitorBase
{
public:
    virtual void visit(ProgramNode *e) = 0;
    virtual void visit(DeclarationNode *e) = 0;
    virtual void visit(ConstantValueNode *e) = 0;
    virtual void visit(VariableNode *e) = 0;
    virtual void visit(ProgramBodyNode *e) = 0;
    virtual void visit(ExpressionNode *e) = 0;
    virtual void visit(VariableReferenceNode *e) = 0;
    virtual void visit(BinaryOperatorNode *e) = 0;
};