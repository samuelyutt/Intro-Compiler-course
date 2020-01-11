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
void gen_load_int(int value);
void gen_assign(string name);
void gen_local_decl(string name, int value);
void gen_binary(int op);
void gen_unary(int op);
void gen_load_word(string name);
void gen_store_word(string name);
void gen_func_start(string name);
void gen_func_end(string name);
void gen_param_decl(string name);
void gen_return();
void gen_func_args(int count);
void gen_func_call(string name);
void gen_print(string name);
void gen_read(string name);
void gen_label(int label_num);
void gen_condition(int cdn_type, int label_num, int op);
void gen_jump(int label_num);
void gen_for_idx_add(string name);
int get_label_count(int add);