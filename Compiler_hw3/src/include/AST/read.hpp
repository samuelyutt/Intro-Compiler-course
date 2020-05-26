#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/statement.hpp"
#include "AST/expression.hpp"

class ASTNodeVisitorBase;

class ReadNode : public StatementNode
{
public:
  ExpressionNode* target;

  ReadNode(uint32_t line, uint32_t col);
  void printNode();
  ~ReadNode();
  void accept(ASTNodeVisitorBase &v);
};