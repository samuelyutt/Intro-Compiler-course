#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/statement.hpp"
#include "AST/expression.hpp"

class ASTNodeVisitorBase;

class PrintNode : public StatementNode
{
public:
  ExpressionNode* target;

  PrintNode(uint32_t line, uint32_t col);
  void printNode();
  ~PrintNode();
  void accept(ASTNodeVisitorBase &v);
};