#pragma once
#include <string>
using namespace std;
//#include "semantic/SemanticAnalyzer.hpp"
//#include "semantic/SymbolTable.hpp"

void test1(int a);
void gen_program_start(string program_name);
void gen_main_start();
void gen_main_end();
void gen_global_decl(string name);
void gen_global_decl_const(string name, int value);
void gen_load_int(int leftRight, int value);
void gen_assign(string name);
void gen_local_decl(string name, int value);
void gen_binary(int op);
void gen_load_word(string name);