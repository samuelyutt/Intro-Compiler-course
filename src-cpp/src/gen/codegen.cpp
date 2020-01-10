#include <string>
//#include "semantic/SemanticAnalyzer.hpp"
#include "gen/codegen.hpp"
using namespace std;

extern FILE *ofp;

int tp_i = 0;

string gb_decl[100];
int gb_decl_i = 0;

string lc_decl[100][100];
int lc_decl_i[100] = {0};
int stack_i = 0;

int find_lc_decl(string name) {
	for (int i = 0; i < lc_decl_i[ stack_i ]; i++) {
		if (lc_decl[ stack_i ][i] == name)
			return i;
	}
	return -1;
}

int find_gb_decl(string name) {
	for (int i = 0; i < gb_decl_i; i++) {
		if (gb_decl[i] == name)
			return i;
	}
	return -1;
}


void test1(int a) {
	fprintf(ofp, "%d\n", a);
}

void gen_program_start(string program_name) {
	fprintf(ofp, "    .file \"%s.p\"\n", program_name.c_str());
	fprintf(ofp, "    .option nopic\n");
}

void gen_main_start() {
	fprintf(ofp, ".text\n");
	fprintf(ofp, "    .align 2\n");
	fprintf(ofp, "    .global main\n");
	fprintf(ofp, "    .type main, @function\n");
	fprintf(ofp, "main:\n");
	fprintf(ofp, "    addi sp, sp, -64\n");
	fprintf(ofp, "    sd ra, 56(sp)\n");
	fprintf(ofp, "    sd s0, 48(sp)\n");
	fprintf(ofp, "    addi s0, sp, 64\n");
}

void gen_main_end() {
	fprintf(ofp, "    ld ra, 56(sp)\n");
	fprintf(ofp, "    ld s0, 48(sp)\n");
	fprintf(ofp, "    addi sp, sp, 64\n");
	fprintf(ofp, "    jr ra\n");
	fprintf(ofp, "    .size main, .-main\n");
}


void gen_global_decl(string name) {
	fprintf(ofp, ".bss\n");
	fprintf(ofp, "%s:\n", name.c_str());
	fprintf(ofp, "    .word 0\n");

	gb_decl[ gb_decl_i++ ] = name;
}

void gen_global_decl_const(string name, int value) {
	fprintf(ofp, ".text\n");
	fprintf(ofp, "%s:\n", name.c_str());
	fprintf(ofp, "    .word %d\n", value);

	gb_decl[ gb_decl_i++ ] = name;
}

void gen_local_decl(string name, int value) {
	int idx = lc_decl_i[ stack_i ];
	lc_decl[ stack_i ][ idx++ ] = name;
	lc_decl_i[ stack_i ] = idx;
}

void gen_load_int(int leftRight, int value) {
	fprintf(ofp, "    li t%d, %d\n", tp_i, value);
	tp_i++;
}

void gen_binary(int op) {
	string op_instr;
	switch (op) {
		case 0: op_instr = "addw"; break;
		case 1: op_instr = "subw"; break;
		case 2: op_instr = "mulw"; break;
		case 3: op_instr = "divw"; break;
		case 4: op_instr = "remw"; break;
	}
	fprintf(ofp, "    %s t%d, t%d, t%d\n", op_instr.c_str(), tp_i-2, tp_i-2, tp_i-1);
	tp_i--;
}

void gen_load_word(string name) {
	int seq;
	seq = find_lc_decl(name);
	if (seq != -1) {
		fprintf(ofp, "    lw t%d, %d(s0)\n",tp_i, -20-seq*4);
		tp_i++;
		return;
	}	
	seq = find_gb_decl(name);
	if (seq != -1) {
		fprintf(ofp, "    la t%d, %s\n",tp_i+1 , name.c_str());
		fprintf(ofp, "    lw t%d, 0(t%d)\n", tp_i, tp_i+1);
		tp_i++;
		return;
	}
}

void gen_assign(string name) {
	int seq;
	seq = find_lc_decl(name);
	tp_i--;
	if (seq != -1) {
		fprintf(ofp, "    sw t0, %d(s0)\n", -20-seq*4);
		return;
	}	
	seq = find_gb_decl(name);
	if (seq != -1) {
		fprintf(ofp, "    la t1, %s\n", name.c_str());
		fprintf(ofp, "    sw t0, 0(t1)\n");
		return;
	}
}