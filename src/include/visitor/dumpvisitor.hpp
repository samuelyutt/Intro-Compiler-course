#pragma once
#include "visitor/visitor.hpp"

class DumpVisitor : public ASTNodeVisitorBase
{
public:
    void visit(ProgramNode *e) override;
    void visit(DeclarationNode *e) override;
    void visit(ConstantValueNode *e) override;
    void visit(VariableNode *e) override;
    void visit(ProgramBodyNode *e) override;
    void visit(ExpressionNode *e) override;
    void visit(VariableReferenceNode *e) override;
    void visit(BinaryOperatorNode *e) override;
    void visit(UnaryOperatorNode *e) override;
    void visit(FunctionCallExprNode *e) override;
    void visit(StatementNode *e) override;
    void visit(CompoundStmtNode *e) override;
    void visit(ArrTypeNode *e) override;
    void visit(ArrDeclarationNode *e) override;
    void visit(AssignmentNode *e) override;
    void visit(PrintNode *e) override;
    void visit(ReadNode *e) override;
    void visit(ReturnNode *e) override;
    void visit(WhileNode *e) override;
    void visit(IfNode *e) override;
};