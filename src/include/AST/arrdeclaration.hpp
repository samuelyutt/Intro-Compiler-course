#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"

class ASTNodeVisitorBase;

class ArrDeclarationNode : public ASTNodeBase
{
public:
  std::string bgn;
  std::string end;

  ArrDeclarationNode(uint32_t line, uint32_t col);
  void printNode();
  ~ArrDeclarationNode();
  void accept(ASTNodeVisitorBase &v);
};