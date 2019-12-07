#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/statement.hpp"
#include "AST/expression.hpp"

class ASTNodeVisitorBase;

class ReturnNode : public StatementNode
{
public:
  ExpressionNode* return_value;

  ReturnNode(uint32_t line, uint32_t col);
  void printNode();
  ~ReturnNode();
  void accept(ASTNodeVisitorBase &v);
};