#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/statement.hpp"
#include "AST/expression.hpp"

class ASTNodeVisitorBase;

class WhileNode : public StatementNode
{
public:
  ExpressionNode* condition;
  std::vector<StatementNode*> body;

  WhileNode(uint32_t line, uint32_t col);
  void printNode();
  ~WhileNode();
  void accept(ASTNodeVisitorBase &v);
};