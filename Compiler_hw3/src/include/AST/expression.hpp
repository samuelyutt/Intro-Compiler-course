#pragma once
#include <cstdint>
#include "AST/ast.hpp"
class ASTNodeVisitorBase;


class ExpressionNode : public ASTNodeBase
{
public:
  ExpressionNode(uint32_t line, uint32_t col);
  void printNode();
  ~ExpressionNode();
  void accept(ASTNodeVisitorBase &v);
};
