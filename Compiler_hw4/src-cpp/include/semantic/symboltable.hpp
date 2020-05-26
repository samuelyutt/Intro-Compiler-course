#pragma once
#include <vector>
#include <stack>
#include <cstring>

class SymbolEntry {
public:
    string name;
    string kind;
    int level;
    string type;
    string attribute;
};

class SymbolTable {
public:
    void addSymbol(SymbolEntry s){
        entries.push_back(s);
    }
    // other methods
public:
    std::vector<SymbolEntry> entries;
};

class SymbolManager {
public:
    // Pass-by-value is slow and has unnecessary object construction,
    // but otherwise the implementation is simpler.
    // For efficientcy, you may try to learn how to use rvalue reference
    void pushScope(SymbolTable new_scope){
        tables.push(new_scope);
    }
    void popScope(){
        tables.pop();
    }
    // other methods
public:
    std::stack <SymbolTable> tables;
};