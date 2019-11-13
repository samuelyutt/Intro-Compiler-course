%{
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "error.h"

extern int32_t LineNum;   /* declared in scanner.l */
extern char Buffer[512];  /* declared in scanner.l */
extern FILE *yyin;        /* declared by lex */
extern char *yytext;      /* declared by lex */

extern int yylex(void); 
static void yyerror(const char *msg);
%}

%token ID INT OCTINT FLOAT SCI STR
%token ',' ';' ':' '(' ')' '[' ']'
%left '+' '-' '*' '/' MOD ASSIGN '<' LE NE GE '>' '=' AND OR NOT
%token ARRAY BGN BOOLEAN DEF DO ELSE END FALSE FOR INTEGER IF OF PRINT READ REAL STRING THEN TO TRUE RETURN VAR WHILE

%%
program         : ID ';' dec_vars_consts_ functions_ compound_stmt END ID;

dec_vars_consts_: dec_var_const dec_vars_consts_ |;
dec_var_const   : dec_var | dec_varconst;

dec_var         : VAR idlist ':' type ';';

type            : scalar_type | arr_type;
scalar_type     : INTEGER | REAL | STRING | BOOLEAN;
arr_type        : ARRAY INT TO INT OF type;

dec_varconst    : VAR idlist ':' literal_const ';';
literal_const   : const | STR | TRUE | FALSE;

functions_      : function functions_ |;
function        : ID '(' formal_args_ ')' ':' scalar_type ';' compound_stmt END ID
                | ID '(' formal_args_ ')' ';' compound_stmt END ID;

const           : pos_const | neg_const;
pos_const       : INT | OCTINT | FLOAT | SCI;
neg_const       : neg pos_const;

formal_args_    : formal_arg formal_args_ |;
formal_arg      : idlist ':' type;

idlist          : ID ids_;
ids_            : ',' ID ids_ |;

compound_stmt   : BGN dec_vars_consts_ stmts_ END;
stmts_          : stmt stmts_ |;
stmt            : PRINT expr ';'
                | READ var_ref ';'
                | compound_stmt
                | condition
                | whileloop
                | forloop
                | var_ref ASSIGN expr ';'
                | procedure ';'
                | rtrn ';';

var_ref         : ID arr_ref;

arr_ref         : exprbs_;

exprbs_         : '[' expr ']' exprbs_ |;

exprcs_         : expr exprcs |;
exprcs          : ',' expr exprcs |;

expr            : not_neg_ '(' expr ')'
                | expr operator expr
                | not_neg_ item
                | not_ TRUE | FALSE
                | const
                | STR;

item            : var_ref | procedure;

operator        : add | sub | mul | div | rel | log;
neg             : '-';
add             : '+';
sub             : '-';
mul             : '*';
div             : '/' | MOD;
rel             : '<' | LE | NE | GE | '>' | '=';
log             : AND | OR;
not_            : NOT |;
not_neg_        : '-' | not_;

condition       : IF expr THEN stmts_ ELSE stmts_ END IF
                | IF expr THEN stmts_ END IF;

whileloop       : WHILE expr DO stmts_ END DO;

forloop         : FOR ID ASSIGN int_const TO int_const DO stmts_ END DO;
int_const       : pos_int | neg_int;
pos_int         : INT | OCTINT;
neg_int         : neg pos_int;

rtrn            : RETURN expr;

procedure       : ID '(' exprcs_ ')';

%%

void yyerror(const char *msg) {
    fprintf(stderr,
            "\n"
            "|-----------------------------------------------------------------"
            "---------\n"
            "| Error found in Line #%d: %s\n"
            "|\n"
            "| Unmatched token: %s\n"
            "|-----------------------------------------------------------------"
            "---------\n",
            LineNum, Buffer, yytext);
    exit(-1);
}

int main(int argc, const char *argv[]) {
    CHECK(argc == 2, "Usage: ./parser <filename>\n");

    FILE *fp = fopen(argv[1], "r");

    CHECK(fp != NULL, "fopen() fails.\n");
    yyin = fp;
    yyparse();

    printf("\n"
           "|--------------------------------|\n"
           "|  There is no syntactic error!  |\n"
           "|--------------------------------|\n");
    return 0;
}
