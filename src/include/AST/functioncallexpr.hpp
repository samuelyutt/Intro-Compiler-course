#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/expression.hpp"

class ASTNodeVisitorBase;

class FunctionCallExprNode : public ExpressionNode
{
public:
  std::string name;
  std::vector<ExpressionNode*> v_expressionNode;

  FunctionCallExprNode(uint32_t line, uint32_t col);
  void printNode();
  ~FunctionCallExprNode();
  void accept(ASTNodeVisitorBase &v);
};