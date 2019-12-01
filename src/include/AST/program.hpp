#pragma once
#include <string>
#include "AST/ast.hpp"

class ASTNodeVisitorBase;

class ProgramNode : public ASTNodeBase
{
public:
  std::string name;
  ProgramNode(uint32_t line, uint32_t col);
  void printNode();
  ~ProgramNode();
  void accept(ASTNodeVisitorBase &v);
};