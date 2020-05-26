#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/expression.hpp"

class ASTNodeVisitorBase;

class BinaryOperatorNode : public ExpressionNode
{
public:
  std::string op;
  ExpressionNode* leftOperand;
  ExpressionNode* rightOperand;

  BinaryOperatorNode(uint32_t line, uint32_t col);
  void printNode();
  ~BinaryOperatorNode();
  void accept(ASTNodeVisitorBase &v);
};