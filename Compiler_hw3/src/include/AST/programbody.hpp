#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/declaration.hpp"
#include "AST/function.hpp"
#include "AST/compoundstmt.hpp"

class ASTNodeVisitorBase;

class ProgramBodyNode : public ASTNodeBase
{
public:
  std::vector<DeclarationNode*> v_declarationNode;
  std::vector<FunctionNode*> v_functionNode;
  CompoundStmtNode* compoundStmtNode;

  ProgramBodyNode(uint32_t line, uint32_t col);
  void printNode();
  ~ProgramBodyNode();
  void accept(ASTNodeVisitorBase &v);
};