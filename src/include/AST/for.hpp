#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/statement.hpp"
#include "AST/declaration.hpp"
#include "AST/assignment.hpp"
#include "AST/expression.hpp"

class ASTNodeVisitorBase;

class ForNode : public StatementNode
{
public:
  DeclarationNode* loop_var_decl;
  AssignmentNode* init_assignment;
  ExpressionNode* condition;
  std::vector<StatementNode*> body;

  ForNode(uint32_t line, uint32_t col);
  void printNode();
  ~ForNode();
  void accept(ASTNodeVisitorBase &v);
};