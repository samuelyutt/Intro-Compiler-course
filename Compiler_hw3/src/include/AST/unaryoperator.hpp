#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/expression.hpp"

class ASTNodeVisitorBase;

class UnaryOperatorNode : public ExpressionNode
{
public:
  std::string op;
  ExpressionNode* operand;

  UnaryOperatorNode(uint32_t line, uint32_t col);
  void printNode();
  ~UnaryOperatorNode();
  void accept(ASTNodeVisitorBase &v);
};