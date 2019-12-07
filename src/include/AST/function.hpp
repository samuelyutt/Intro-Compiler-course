#pragma once
#include <string>
#include <vector>
#include "AST/ast.hpp"
#include "AST/declaration.hpp"
#include "AST/compoundstmt.hpp"
#include "AST/variable.hpp"

class ASTNodeVisitorBase;

class FunctionNode : public ASTNodeBase
{
public:
  std::string name;
  std::vector<DeclarationNode*> parameters;
  std::string return_type;
  CompoundStmtNode* body;
  std::string end_name;

  FunctionNode(uint32_t line, uint32_t col);
  void printNode();
  ~FunctionNode();
  void accept(ASTNodeVisitorBase &v);
};