#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "variable.hpp"

class ASTNodeVisitorBase;

class DeclarationNode : public ASTNodeBase
{
public:
  std::string name;
  std::vector<VariableNode*> v_variableNode;

  DeclarationNode(uint32_t line, uint32_t col);
  void printNode();
  ~DeclarationNode();
  void accept(ASTNodeVisitorBase &v);
};