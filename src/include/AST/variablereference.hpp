#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/expression.hpp"

class ASTNodeVisitorBase;

class VariableReferenceNode : public ExpressionNode
{
public:
  std::string name;
  std::vector<ExpressionNode*> v_expressionNode;

  VariableReferenceNode(uint32_t line, uint32_t col);
  void printNode();
  ~VariableReferenceNode();
  void accept(ASTNodeVisitorBase &v);
};