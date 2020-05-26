#include <string>
#include "gen/codegen.hpp"
using namespace std;

extern FILE *ofp;

string gb_decl[100];
int gb_decl_i = 0;

string lc_decl[100][100];
int lc_decl_i[100] = {0};
int stack_i = 0;

int param_count = 0, label_count = 1, cdn_count = 0, tp_i;


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

void increase_tp_i() {
    tp_i++;
    if (tp_i > 6) {
        int idx = lc_decl_i[ stack_i ];
        lc_decl[ stack_i ][ idx ] = "preserved_for_spilled_tmprys" + to_string(tp_i%7);
        fprintf(ofp, "    sw t%d, %d(s0)\n", tp_i%7, -20-idx*4);
        lc_decl_i[ stack_i ] = ++idx;
    }
}

void decrease_tp_i() {
    if (tp_i > 6) {
        int seq;
        string tp_name = "preserved_for_spilled_tmprys" + to_string(tp_i%7);
        seq = find_lc_decl(tp_name);
        if (seq != -1) {
            fprintf(ofp, "    lw t%d, %d(s0)\n", tp_i%7, -20-seq*4);
        }    
    }
    tp_i--;
}

void reset_tp_i() {
    tp_i = 0;
}

int get_tp_i(int offset) {
    return (tp_i + offset)%7;
}

int get_label_count(int add) {
    int ret = label_count;
    label_count += add;
    return ret;
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
    gen_load_int(value);
    gen_assign(name);
}

void gen_load_int(int value) {
    fprintf(ofp, "    li t%d, %d\n", get_tp_i(0), value);
    increase_tp_i();
}


void gen_for_idx_add(string name) {
    gen_load_word(name);
    fprintf(ofp, "    addi t%d, t%d, 1\n", get_tp_i(-1), get_tp_i(-1));
    decrease_tp_i();
    gen_store_word(name);
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
    fprintf(ofp, "    %s t%d, t%d, t%d\n", op_instr.c_str(), get_tp_i(-2), get_tp_i(-2), get_tp_i(-1));
    decrease_tp_i();
}

void gen_condition(int cdn_type, int label_num, int op) {
    string op_instr;
    if (cdn_type == 1) {
        switch (op) {
            case 5: op_instr = "bge"; break;
            case 6: op_instr = "bgt"; break;
            case 7: op_instr = "bne"; break;
            case 8: op_instr = "ble"; break;
            case 9: op_instr = "blt"; break;
            case 10: op_instr = "beq"; break;
        }
    } else if (cdn_type == 2) {
        switch (op) {
            case 5: op_instr = "blt"; break;
            case 6: op_instr = "ble"; break;
            case 7: op_instr = "beq"; break;
            case 8: op_instr = "bgt"; break;
            case 9: op_instr = "bge"; break;
            case 10: op_instr = "bne"; break;
        }
    } else if (cdn_type == 3) {
        op_instr = "bge";
    }
    fprintf(ofp, "    %s t%d, t%d, L%d\n", op_instr.c_str(), get_tp_i(-2), get_tp_i(-1), label_num);
    decrease_tp_i();
    decrease_tp_i();
}

void gen_unary(int op) {
    string op_instr;
    switch (op) {
        case 0: op_instr = "muli"; break;
    }
    fprintf(ofp, "    %s t%d, t%d, -1\n", op_instr.c_str(), get_tp_i(-1), get_tp_i(-1));
}

void gen_load_word(string name) {
    int seq;
    seq = find_lc_decl(name);
    if (seq != -1) {
        fprintf(ofp, "    lw t%d, %d(s0)\n", get_tp_i(0), -20-seq*4);
        increase_tp_i();
        return;
    }    
    seq = find_gb_decl(name);
    if (seq != -1) {
        fprintf(ofp, "    la t%d, %s\n",get_tp_i(0) , name.c_str());
        fprintf(ofp, "    lw t%d, 0(t%d)\n", get_tp_i(0), get_tp_i(0));
        increase_tp_i();
        return;
    }
}

void gen_store_word(string name) {
    int seq;
    seq = find_lc_decl(name);
    if (seq != -1) {
        fprintf(ofp, "    sw t%d, %d(s0)\n",get_tp_i(0), -20-seq*4);
        return;
    }    
    seq = find_gb_decl(name);
    if (seq != -1) {
        fprintf(ofp, "    la t%d, %s\n",get_tp_i(0) , name.c_str());
        fprintf(ofp, "    sw t%d, 0(t%d)\n", get_tp_i(0), get_tp_i(0));
        return;
    }
}

void gen_assign(string name) {
    int seq;
    seq = find_lc_decl(name);
    decrease_tp_i();
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

void gen_func_start(string name) {
    fprintf(ofp, ".text\n");
    fprintf(ofp, "    .align 2\n");
    fprintf(ofp, "    .global %s\n", name.c_str());
    fprintf(ofp, "    .type %s, @function\n", name.c_str());
    fprintf(ofp, "%s:\n", name.c_str());
    fprintf(ofp, "    addi sp, sp, -64\n");
    fprintf(ofp, "    sd ra, 56(sp)\n");
    fprintf(ofp, "    sd s0, 48(sp)\n");
    fprintf(ofp, "    addi s0, sp, 64\n");
    stack_i++;
    lc_decl_i[ stack_i ] = 0;
    param_count = 0;
}

void gen_func_end(string name) {
    fprintf(ofp, "    ld ra, 56(sp)\n");
    fprintf(ofp, "    ld s0, 48(sp)\n");
    fprintf(ofp, "    addi sp, sp, 64\n");
    fprintf(ofp, "    jr ra\n");
    fprintf(ofp, "    .size %s, .-%s\n", name.c_str(), name.c_str());
    stack_i--;
}


void gen_param_decl(string name) {
    int idx = lc_decl_i[ stack_i ];
    lc_decl[ stack_i ][ idx ] = name;
    if (param_count < 8)
        fprintf(ofp, "    sw a%d, %d(s0)\n", param_count, -20-idx*4);
    idx++;
    param_count++;
    lc_decl_i[ stack_i ] = idx;
}


void gen_return() {
    fprintf(ofp, "    mv a0, t0\n");
    decrease_tp_i();
}


void gen_func_args(int count) {
    if (count < 8)
        fprintf(ofp, "    mv a%d, t%d\n", count, get_tp_i(-1));
    else
        fprintf(ofp, "    sw t%d, %d(s0)\n", get_tp_i(-1), -64-20-count*4);
    decrease_tp_i();
}


void gen_func_call(string name) {
    int tmp_tp_i = get_tp_i(0);
    int idx;
    int preserved_count = 0;
    for (int i = 0; i < tmp_tp_i; i++) {
        idx = lc_decl_i[ stack_i ];
        lc_decl[ stack_i ][ idx ] = "preserved_for_tmprys";
        fprintf(ofp, "    sw t%d, %d(s0)\n", i, -20-idx*4);
        lc_decl_i[ stack_i ] = ++idx;
        decrease_tp_i();
        preserved_count++;
    }

    fprintf(ofp, "    jal ra, %s\n", name.c_str());

    reset_tp_i();
    idx = lc_decl_i[ stack_i ];
    for (int i = 0; i < preserved_count; i++) {
        fprintf(ofp, "    lw t%d, %d(s0)\n", i, -20-(idx-preserved_count+i)*4);
        increase_tp_i();
    }

    lc_decl_i[ stack_i ] = idx - preserved_count;
    fprintf(ofp, "    mv t%d, a0\n", get_tp_i(0));
    increase_tp_i();
}

void gen_print(string name) {
    int seq;
    seq = find_lc_decl(name);
    if (seq != -1) {
        fprintf(ofp, "    lw a0, %d(s0)\n", -20-seq*4);
        fprintf(ofp, "    jal ra, print\n");
        return;
    }    
    seq = find_gb_decl(name);
    if (seq != -1) {
        fprintf(ofp, "    la t%d, %s\n",get_tp_i(0) , name.c_str());
        fprintf(ofp, "    lw a0, 0(t%d)\n", get_tp_i(0));
        fprintf(ofp, "    jal ra, print\n");
    return;
    }
}


void gen_read(string name) {
    fprintf(ofp, "    jal ra, read\n");
    int seq;
    seq = find_lc_decl(name);
    if (seq != -1) {
        fprintf(ofp, "    sw a0, %d(s0)\n", -20-seq*4);
        return;
    }    
    seq = find_gb_decl(name);
    if (seq != -1) {
        fprintf(ofp, "    la t%d, %s\n",get_tp_i(0) , name.c_str());
        fprintf(ofp, "    sw a0, 0(t%d)\n", get_tp_i(0));
        return;
    }
}

void gen_label(int label_num) {
    fprintf(ofp, "L%d:\n", label_num);
}

void gen_jump(int label_num) {
    fprintf(ofp, "    j L%d\n", label_num);
}
