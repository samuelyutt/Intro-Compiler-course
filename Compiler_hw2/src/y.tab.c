#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
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
#line 33 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ID 257
#define INT 258
#define OCTINT 259
#define FLOAT 260
#define SCI 261
#define STR 262
#define MOD 263
#define ASSIGN 264
#define LE 265
#define NE 266
#define GE 267
#define AND 268
#define OR 269
#define NOT 270
#define ARRAY 271
#define BGN 272
#define BOOLEAN 273
#define DEF 274
#define DO 275
#define ELSE 276
#define END 277
#define FALSE 278
#define FOR 279
#define INTEGER 280
#define IF 281
#define OF 282
#define PRINT 283
#define READ 284
#define REAL 285
#define STRING 286
#define THEN 287
#define TO 288
#define TRUE 289
#define RETURN 290
#define VAR 291
#define WHILE 292
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    4,    4,    5,    8,    8,    9,    9,
    9,    9,   10,    6,   11,   11,   11,   11,    2,    2,
   13,   13,   12,   12,   15,   15,   15,   15,   16,   14,
   14,   18,    7,   19,   19,    3,   20,   20,   21,   21,
   21,   21,   21,   21,   21,   21,   21,   23,   29,   30,
   30,   31,   31,   32,   32,   22,   22,   22,   22,   22,
   22,   22,   35,   35,   34,   34,   34,   34,   34,   34,
   17,   36,   37,   38,   39,   39,   40,   40,   40,   40,
   40,   40,   41,   41,   33,   33,   33,   24,   24,   25,
   26,   42,   42,   43,   43,   44,   28,   27,
};
static const short yylen[] = {                            2,
    7,    2,    0,    1,    1,    5,    1,    1,    1,    1,
    1,    1,    6,    5,    1,    1,    1,    1,    2,    0,
   10,    8,    1,    1,    1,    1,    1,    1,    2,    2,
    0,    3,    2,    3,    0,    4,    2,    0,    3,    3,
    1,    1,    1,    1,    4,    2,    2,    2,    1,    4,
    0,    2,    0,    3,    0,    4,    3,    2,    1,    2,
    2,    2,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    0,    8,    6,    6,
   10,    1,    1,    1,    1,    2,    2,    4,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    4,    5,    0,    0,
    0,    0,    0,    2,    0,   33,    0,    0,    0,    0,
   19,    0,   25,   26,   27,   28,   16,   71,    0,   12,
   18,    9,   10,   11,   17,    0,    7,    8,    0,   15,
   23,   24,    0,    0,    0,    0,    0,    0,   34,    0,
    6,   14,   29,    0,    0,   30,    0,    0,    0,    0,
    0,    0,    0,   41,    0,    0,    0,   42,   43,   44,
    0,    0,    1,    0,   32,    0,    0,    0,    0,   48,
   49,    0,   85,   59,    0,    0,    0,    0,    0,    0,
    0,    0,   36,   37,    0,   46,   47,    0,    0,    0,
    0,    0,    0,    0,   72,   73,   74,   75,   76,   77,
   78,   79,   80,   81,   82,   83,   84,    0,    0,   65,
   66,   67,   68,   69,   70,   60,    0,   62,   61,   63,
   64,   58,   39,   40,    0,    0,    0,    0,    0,    0,
   52,   98,    0,   94,   95,    0,    0,   92,   93,    0,
    0,    0,    0,   45,   13,   22,    0,    0,   50,   96,
    0,    0,    0,   56,    0,    0,   54,    0,    0,   89,
   90,   21,    0,    0,    0,   88,    0,   91,
};
static const short yydgoto[] = {                          2,
    5,   12,   64,    6,    7,    8,   44,   36,   37,   38,
   39,   84,   13,   45,   41,   42,   85,   46,   16,   65,
   66,   86,   67,   68,   69,   70,   71,   72,   80,   81,
  102,  141,   87,  119,  132,  120,  121,  122,  123,  124,
  125,  147,  148,  149,
};
static const short yysindex[] = {                      -220,
  -11,    0, -246, -205, -198, -246,    0,    0,   21,   10,
   30, -184, -198,    0, -183,    0,    8, -205, -246, -200,
    0,   21,    0,    0,    0,    0,    0,    0, -160,    0,
    0,    0,    0,    0,    0,   41,    0,    0,   60,    0,
    0,    0, -235,   63,   82, -205, -107, -127,    0, -156,
    0,    0,    0, -231,  -23,    0,  -22, -113,  -14,  -14,
 -106,  -14,  -14,    0, -125, -107, -111,    0,    0,    0,
   95,  102,    0,  -95,    0, -184, -213,  -14,  -14,    0,
    0,  -94,    0,    0, -235,   -4,  -38,   54,   78,  112,
   96,   33,    0,    0,  -14,    0,    0, -104,  -98,  121,
   65,  140,   75,  -29,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -107,  -14,    0,
    0,    0,    0,    0,    0,    0,  -14,    0,    0,    0,
    0,    0,    0,    0, -107,   86, -231,  -75, -184,  -14,
    0,    0,   78,    0,    0, -208, -101,    0,    0, -195,
   96,   44,  -93,    0,    0,    0,  -89,   65,    0,    0,
  -29, -107,  -92,    0,  -85,  -66,    0,  -83,  -84,    0,
    0,    0, -107,  -87,  -82,    0,  -79,    0,
};
static const short yyrindex[] = {                         0,
    0,    0, -251,    0,  -74, -117,    0,    0,  141,    0,
    0,    0,  -74,    0,    0,    0,    0,  159, -117,    0,
    0,  141,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  159,  -76,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -32,    0,  -37,  -37,
    0,  -37,  -37,    0,    0, -193,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -40,  -37,    0,
    0,    0,    0,    0,  -36,    0,    0,    0,   41,    0,
  102,    0,    0,    0,  -37,    0,    0,    0,    0,    0,
   82,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -193,  -37,    0,
    0,    0,    0,    0,    0,    0,  -37,    0,    0,    0,
    0,    0,    0,    0,  -76,    0,    0,    0,    0,  -37,
    0,    0,  -32,    0,    0,    0,    0,    0,    0,    0,
  -27,    0,    0,    0,    0,    0,    0,   82,    0,    0,
    0,  -76,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -76,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
   14,  189,   -5,    0,    0,    0,  199,  -35,  127,    0,
    0,  188,    0,  160,  -21,    0,  -12,    0,  185,   24,
    0,  -16,  -53,    0,    0,    0,  122,    0,    0,   67,
    0,   50,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   51,   68,    0,
};
#define YYTABLESIZE 365
static const short yytable[] = {                         87,
   53,  127,   87,   86,   43,    3,   20,   90,   51,   51,
   51,   51,   51,   57,   51,   28,   57,   78,   75,   14,
    3,   53,   23,   24,   25,   26,   51,   51,   51,   51,
   28,   57,   47,  130,   77,   76,    1,  107,  105,   29,
  106,   30,  108,   88,    4,   91,   92,    3,   32,  144,
  145,    9,   28,   33,   34,  110,  115,  114,   11,   30,
   51,  101,  103,   53,   15,   57,   32,   17,   79,   18,
   99,   33,   34,   22,  107,  105,   48,  106,  136,  108,
  162,  163,   38,   38,  164,  107,  105,   19,  106,   94,
  108,  146,  110,  115,  114,  107,  105,   50,  106,   51,
  108,  155,  151,  110,  115,  114,  107,  105,  140,  106,
  152,  108,  133,  110,  115,  114,  107,  105,   52,  106,
   54,  108,   55,  158,  110,  115,  114,  107,  105,   73,
  106,   74,  108,  157,  110,  115,  114,  107,  105,    3,
  106,  150,  108,   82,  154,  110,  115,  114,  146,   57,
   89,   93,   95,   96,    3,  110,  115,  114,  153,    3,
   97,    3,   98,    3,   19,    3,    3,  143,   79,  104,
  134,   58,    3,   59,    3,   60,   61,  137,  138,  139,
  142,  156,   62,  165,   63,  169,  161,  166,  170,  171,
  172,  173,  174,  176,  177,  178,  175,   20,   35,   31,
   38,   21,   10,  100,   40,   56,   49,  167,  131,  159,
    0,  168,    0,  160,    0,    0,   87,    0,   57,   87,
   86,   87,    0,  126,   87,   86,    0,    0,  144,  145,
   51,   51,   51,   51,   51,   51,   51,   87,    0,  128,
   87,   86,   51,   23,   24,   25,   26,   57,   87,    0,
  129,   87,   86,    0,   51,   83,    0,    0,  109,   57,
  111,  112,  113,  116,  117,   23,   24,   25,   26,   27,
    0,    0,    0,    0,    0,    0,    0,    0,   29,    0,
   30,    0,  118,    0,    0,   31,    0,   32,    0,    0,
    0,    0,   33,   34,    0,  109,   35,  111,  112,  113,
  116,  117,    0,    0,    0,    0,  109,  135,  111,  112,
  113,  116,  117,    0,    0,    0,  109,    0,  111,  112,
  113,  116,  117,    0,    0,    0,    0,  109,    0,  111,
  112,  113,  116,  117,    0,    0,    0,  109,    0,  111,
  112,  113,  116,  117,    0,    0,    0,    0,  109,    0,
  111,  112,  113,  116,  117,    0,    0,    0,  109,    0,
  111,  112,  113,  116,  117,
};
static const short yycheck[] = {                         40,
   41,   40,   40,   40,   17,  257,   12,   61,   41,   42,
   43,   44,   45,   41,   47,   45,   44,   40,   54,    6,
  272,   43,  258,  259,  260,  261,   59,   60,   61,   62,
   45,   59,   19,   87,   58,   59,  257,   42,   43,  271,
   45,  273,   47,   60,  291,   62,   63,   59,  280,  258,
  259,  257,   45,  285,  286,   60,   61,   62,  257,  273,
   93,   78,   79,   85,   44,   93,  280,   58,   91,   40,
   76,  285,  286,  257,   42,   43,  277,   45,   95,   47,
  276,  277,  276,  277,   41,   42,   43,  272,   45,   66,
   47,  104,   60,   61,   62,   42,   43,  258,   45,   59,
   47,  137,  119,   60,   61,   62,   42,   43,   44,   45,
  127,   47,   59,   60,   61,   62,   42,   43,   59,   45,
   58,   47,   41,  140,   60,   61,   62,   42,   43,  257,
   45,  288,   47,  139,   60,   61,   62,   42,   43,  257,
   45,  118,   47,  257,   59,   60,   61,   62,  161,  257,
  257,  277,  264,   59,  272,   60,   61,   62,  135,  277,
   59,  279,  258,  281,  272,  283,  284,   93,   91,  264,
   59,  279,  290,  281,  292,  283,  284,  282,  277,   59,
   41,  257,  290,  277,  292,  162,  288,  277,  281,  275,
  257,  275,  277,  281,  277,  275,  173,  272,   58,   41,
  277,   13,    4,   77,   17,   46,   22,  158,   87,  143,
   -1,  161,   -1,  146,   -1,   -1,  257,   -1,  257,  257,
  257,  262,   -1,  262,  262,  262,   -1,   -1,  258,  259,
  263,  264,  265,  266,  267,  268,  269,  278,   -1,  278,
  278,  278,  275,  258,  259,  260,  261,  275,  289,   -1,
  289,  289,  289,   -1,  287,  270,   -1,   -1,  263,  287,
  265,  266,  267,  268,  269,  258,  259,  260,  261,  262,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  271,   -1,
  273,   -1,  287,   -1,   -1,  278,   -1,  280,   -1,   -1,
   -1,   -1,  285,  286,   -1,  263,  289,  265,  266,  267,
  268,  269,   -1,   -1,   -1,   -1,  263,  275,  265,  266,
  267,  268,  269,   -1,   -1,   -1,  263,   -1,  265,  266,
  267,  268,  269,   -1,   -1,   -1,   -1,  263,   -1,  265,
  266,  267,  268,  269,   -1,   -1,   -1,  263,   -1,  265,
  266,  267,  268,  269,   -1,   -1,   -1,   -1,  263,   -1,
  265,  266,  267,  268,  269,   -1,   -1,   -1,  263,   -1,
  265,  266,  267,  268,  269,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 292
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,"ID","INT","OCTINT","FLOAT","SCI","STR","MOD",
"ASSIGN","LE","NE","GE","AND","OR","NOT","ARRAY","BGN","BOOLEAN","DEF","DO",
"ELSE","END","FALSE","FOR","INTEGER","IF","OF","PRINT","READ","REAL","STRING",
"THEN","TO","TRUE","RETURN","VAR","WHILE",
};
static const char *yyrule[] = {
"$accept : program",
"program : ID ';' dec_vars_consts_ functions_ compound_stmt END ID",
"dec_vars_consts_ : dec_var_const dec_vars_consts_",
"dec_vars_consts_ :",
"dec_var_const : dec_var",
"dec_var_const : dec_varconst",
"dec_var : VAR idlist ':' type ';'",
"type : scalar_type",
"type : arr_type",
"scalar_type : INTEGER",
"scalar_type : REAL",
"scalar_type : STRING",
"scalar_type : BOOLEAN",
"arr_type : ARRAY INT TO INT OF type",
"dec_varconst : VAR idlist ':' literal_const ';'",
"literal_const : const",
"literal_const : STR",
"literal_const : TRUE",
"literal_const : FALSE",
"functions_ : function functions_",
"functions_ :",
"function : ID '(' formal_args_ ')' ':' scalar_type ';' compound_stmt END ID",
"function : ID '(' formal_args_ ')' ';' compound_stmt END ID",
"const : pos_const",
"const : neg_const",
"pos_const : INT",
"pos_const : OCTINT",
"pos_const : FLOAT",
"pos_const : SCI",
"neg_const : neg pos_const",
"formal_args_ : formal_arg formal_args_",
"formal_args_ :",
"formal_arg : idlist ':' type",
"idlist : ID ids_",
"ids_ : ',' ID ids_",
"ids_ :",
"compound_stmt : BGN dec_vars_consts_ stmts_ END",
"stmts_ : stmt stmts_",
"stmts_ :",
"stmt : PRINT expr ';'",
"stmt : READ var_ref ';'",
"stmt : compound_stmt",
"stmt : condition",
"stmt : whileloop",
"stmt : forloop",
"stmt : var_ref ASSIGN expr ';'",
"stmt : procedure ';'",
"stmt : rtrn ';'",
"var_ref : ID arr_ref",
"arr_ref : exprbs_",
"exprbs_ : '[' expr ']' exprbs_",
"exprbs_ :",
"exprcs_ : expr exprcs",
"exprcs_ :",
"exprcs : ',' expr exprcs",
"exprcs :",
"expr : not_neg_ '(' expr ')'",
"expr : expr operator expr",
"expr : not_neg_ item",
"expr : const",
"expr : not_neg_ STR",
"expr : not_neg_ TRUE",
"expr : not_neg_ FALSE",
"item : var_ref",
"item : procedure",
"operator : add",
"operator : sub",
"operator : mul",
"operator : div",
"operator : rel",
"operator : log",
"neg : '-'",
"add : '+'",
"sub : '-'",
"mul : '*'",
"div : '/'",
"div : MOD",
"rel : '<'",
"rel : LE",
"rel : NE",
"rel : GE",
"rel : '>'",
"rel : '='",
"log : AND",
"log : OR",
"not_neg_ : NOT",
"not_neg_ : neg",
"not_neg_ :",
"condition : IF expr THEN stmts_ ELSE stmts_ END IF",
"condition : IF expr THEN stmts_ END IF",
"whileloop : WHILE expr DO stmts_ END DO",
"forloop : FOR ID ASSIGN int_const TO int_const DO stmts_ END DO",
"int_const : pos_int",
"int_const : neg_int",
"pos_int : INT",
"pos_int : OCTINT",
"neg_int : neg pos_int",
"rtrn : RETURN expr",
"procedure : ID '(' exprcs_ ')'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 107 "parser.y"

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
#line 472 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
