#pragma once
#include <cstdint>
class ASTNodeVisitorBase;

struct Location
{
  uint32_t line;
  uint32_t col;
  Location(uint32_t line, uint32_t col) : line(col), col(col){};
};

class ASTNodeBase
{
public:
  Location location;
  ASTNodeBase(int32_t line, int32_t col) : location(line, col){};

  virtual ~ASTNodeBase(){};
  virtual void printNode();
  virtual void accept(ASTNodeVisitorBase &v) = 0;
};
