#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/statement.hpp"
#include "AST/expression.hpp"

class ASTNodeVisitorBase;

class FunctionInvokationNode : public StatementNode
{
public:
  std::string name;
  std::vector<ExpressionNode*> v_expressionNode;

  FunctionInvokationNode(uint32_t line, uint32_t col);
  void printNode();
  ~FunctionInvokationNode();
  void accept(ASTNodeVisitorBase &v);
};