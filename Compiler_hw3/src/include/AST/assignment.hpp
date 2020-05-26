#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/statement.hpp"
#include "AST/variablereference.hpp"
#include "AST/expression.hpp"

class ASTNodeVisitorBase;

class AssignmentNode : public StatementNode
{
public:
  VariableReferenceNode* lvalue;
  ExpressionNode* expression;

  AssignmentNode(uint32_t line, uint32_t col);
  void printNode();
  ~AssignmentNode();
  void accept(ASTNodeVisitorBase &v);
};