#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/statement.hpp"
#include "AST/declaration.hpp"

class ASTNodeVisitorBase;

class CompoundStmtNode : public StatementNode
{
public:
  std::string name;
  std::vector<DeclarationNode*> v_declarationNode;
  std::vector<StatementNode*> v_statementNode;

  CompoundStmtNode(uint32_t line, uint32_t col);
  void printNode();
  ~CompoundStmtNode();
  void accept(ASTNodeVisitorBase &v);
};