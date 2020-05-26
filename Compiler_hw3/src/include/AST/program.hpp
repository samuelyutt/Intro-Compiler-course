#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/programbody.hpp"
#include "AST/declaration.hpp"

class ASTNodeVisitorBase;

class ProgramNode : public ASTNodeBase
{
public:
  std::string name;
  ProgramBodyNode* programBodyNode;

  ProgramNode(uint32_t line, uint32_t col);
  void printNode();
  ~ProgramNode();
  void accept(ASTNodeVisitorBase &v);
};