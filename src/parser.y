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

%token ID INT OCTINT FLOAT SCI STRING
%token ',' ';' ':' '(' ')' '[' ']'
%left '+' '-' '*' '/' MOD ASSIGN '<' LE NE GE '>' '=' AND OR NOT
%token ARRAY BGN BOOLEAN DEF DO ELSE END FALSE FOR INTEGER IF OF PRINT READ REAL STRING THEN TO TRUE RETURN VAR WHILE
%token "\n"

%%
//program     : ID ';';

program         : ID ';' vars_consts_ functions_ compound_statment END ID;

vars_consts_    : var_const vars_consts_
                |;
var_const       : variable
                | constant;

functions_      : function functions_
                |;
function        : ID '(' formal_args_ ')' ':' scalar_type ';' compound_statment END ID;

type            : scalar_type | arr;
scalar_type     : INTEGER | REAL | STRING | BOOLEAN;

constant        : pos_constant | neg_constant;
pos_constant    : INT | OCTINT | FLOAT | SCI;
neg_constant    : neg pos_constant;

formal_args_    : formal_arg formal_args_
                |;
formal_arg      : idlist ':' type;

idlist          : ID ids_;
ids_            : ',' ID ids_
                |;

variable        : VAR idlist ':' scalar_type ';'
                | vararr;

vararr          : VAR idlist ':' arr ';';

arr             : ARRAY INT TO INT OF type;

constant        : VAR idlist ':' literal_constant ';';

literal_constant    : INT
                    | OCTINT
                    | FLOAT
                    | SCI
                    | STRING
                    | TRUE
                    | FALSE;

compound_statment   : BGN vars_consts_ statements_ END;
statements_         : statement statements_
                    |;
statement           : var_ref ASSIGN expr ';'
                    | PRINT var_ref ';'
                    | PRINT expr ';'
                    | READ var_ref ';';

var_ref         : ID | arr_ref;

arr_ref         : ID exprbs_;

exprbs_         : '[' expr ']' exprbs_
                |;

exprcs          : expr exprcs_;
exprcs_         : ',' expr exprcs_
                |;

exprs_          : expr exprs_
                |;
expr            : ID ASSIGN items ';'
                | items;
items           : '(' items ')'
                | items operator items
                | item;
item            : constant | TRUE | FALSE | STRING;

operator        : add | sub | mul | div | rel | log;
neg             : '-';
add             : '+';
sub             : '-';
mul             : '*';
div             : '/' | MOD;
rel             : '<' | LE | NE | GE | '>' | '=';
log             : AND | OR | NOT;

condition       : IF expr THEN statements_ ELSE statements_ END IF
                | IF expr THEN statements_ END IF;

whileloop       : WHILE expr DO statements_ END DO;

forloop         : FOR ID ASSIGN int_const TO int_const DO statements_ END DO;
int_const       : pos_int | neg_int;
pos_int         : INT | OCTINT;
neg_int         : neg pos_int;

rtrn            : RETURN expr ';';

procedure       : ID '(' exprcs ')' ';';

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
