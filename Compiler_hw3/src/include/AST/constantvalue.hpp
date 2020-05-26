#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/expression.hpp"

class ASTNodeVisitorBase;

class ConstantValueNode : public ExpressionNode
{
public:
  std::string constant_value;
  std::string type;
  ConstantValueNode(uint32_t line, uint32_t col);
  void printNode();
  ~ConstantValueNode();
  void accept(ASTNodeVisitorBase &v);
};