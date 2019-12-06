#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/declaration.hpp"

class ASTNodeVisitorBase;

class ProgramBodyNode : public ASTNodeBase
{
public:
  std::vector<DeclarationNode*> v_declarationNode;

  ProgramBodyNode(uint32_t line, uint32_t col);
  void printNode();
  ~ProgramBodyNode();
  void accept(ASTNodeVisitorBase &v);
};