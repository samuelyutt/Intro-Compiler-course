#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/statement.hpp"
#include "AST/expression.hpp"

class ASTNodeVisitorBase;

class IfNode : public StatementNode
{
public:
  ExpressionNode* condition;
  std::vector<StatementNode*> body;
  std::vector<StatementNode*> body_of_else;

  IfNode(uint32_t line, uint32_t col);
  void printNode();
  ~IfNode();
  void accept(ASTNodeVisitorBase &v);
};