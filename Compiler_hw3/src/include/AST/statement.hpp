#pragma once
#include <cstdint>
#include "AST/ast.hpp"
class ASTNodeVisitorBase;


class StatementNode : public ASTNodeBase
{
public:
  StatementNode(uint32_t line, uint32_t col);
  void printNode();
  ~StatementNode();
  void accept(ASTNodeVisitorBase &v);
};
