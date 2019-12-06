#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/statement.hpp"
#include "AST/arrdeclaration.hpp"

class ASTNodeVisitorBase;

class ArrTypeNode : public ASTNodeBase
{
public:
  std::string type;
  std::vector<ArrDeclarationNode*> v_arrdeclarationNode;

  ArrTypeNode(uint32_t line, uint32_t col);
  void printNode();
  ~ArrTypeNode();
  void accept(ASTNodeVisitorBase &v);
};