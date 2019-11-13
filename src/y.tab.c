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
   49,    0,    0,   85,   59,    0,    0,    0,    0,    0,
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
   39,   85,   13,   45,   41,   42,   43,   46,   16,   65,
   66,   86,   67,   68,   69,   70,   71,   72,   80,   81,
  102,  141,   87,  119,  132,  120,  121,  122,  123,  124,
  125,  147,  148,  149,
};
static const short yysindex[] = {                      -235,
  -35,    0, -263, -215, -212, -263,    0,    0,    9,    1,
   20, -201, -212,    0, -182,    0,   18, -215, -263, -195,
    0,    9,    0,    0,    0,    0,    0,    0, -174,    0,
    0,    0,    0,    0,    0,   38,    0,    0,   41,    0,
    0,    0, -165,   46,   71, -215, -207, -143,    0, -167,
    0,    0,    0, -118,  -33,    0,  -22, -134,   57,   57,
 -124,   57,   57,    0, -142, -207, -128,    0,    0,    0,
   85,   91,    0, -104,    0, -201,  -97,   57,   57,    0,
    0, -112,    0,    0,    0,   19,  -32,   56,   65,  102,
   98,   45,    0,    0,   57,    0,    0, -125, -114,  105,
   66,  124,   77,  -44,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -207,   57,    0,
    0,    0,    0,    0,    0,    0,   57,    0,    0,    0,
    0,    0,    0,    0, -207,   87, -118,  -85, -201,   57,
    0,    0,   65,    0,    0, -226, -109,    0,    0, -229,
   98,  -26, -103,    0,    0,    0,  -96,   66,    0,    0,
  -44, -207,  -99,    0,  -90,  -70,    0,  -84,  -87,    0,
    0,    0, -207,  -89,  -83,    0,  -82,    0,
};
static const short yyrindex[] = {                         0,
    0,    0, -245,    0,  -77, -106,    0,    0,  138,    0,
    0,    0,  -77,    0,    0,    0,    0,  156, -106,    0,
    0,  138,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  156,  -79,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   -4,    0,  -31,  -31,
    0,  -31,  -31,    0,    0, -225,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -34,  -31,    0,
    0,    0,  -40,    0,    0,    0,    0,    0,   38,    0,
   91,    0,    0,    0,  -31,    0,    0,    0,    0,    0,
   71,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -225,  -31,    0,
    0,    0,    0,    0,    0,    0,  -31,    0,    0,    0,
    0,    0,    0,    0,  -79,    0,    0,    0,    0,  -31,
    0,    0,   -4,    0,    0,    0,    0,    0,    0,    0,
  -39,    0,    0,    0,    0,    0,    0,   71,    0,    0,
    0,  -79,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -79,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
   25,  186,   -8,    0,    0,    0,  196,  -51,  125,    0,
    0,  184,    0,  157,  161,    0,  -94,    0,  183,    7,
    0,  -49,  -38,    0,    0,    0,  119,    0,    0,   64,
    0,   50,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   48,   67,    0,
};
#define YYTABLESIZE 367
static const short yytable[] = {                         86,
   28,   57,   75,   20,   57,   87,   53,  127,   87,  146,
   88,    3,   91,   92,  164,  107,  105,   78,  106,   57,
  108,    1,   90,    3,   77,   76,    3,    4,  101,  103,
   14,  144,  145,  110,  115,  114,   51,   51,   51,   51,
   51,    9,   51,   47,   11,  136,  162,  163,  130,   57,
   38,   38,   15,   57,   51,   51,   51,   51,   17,   18,
  107,  105,   28,  106,   19,  108,  146,   99,   79,  151,
   19,   58,   94,   59,   22,   60,   61,  152,  110,  115,
  114,   48,   62,   50,   63,  155,  107,  105,   51,  106,
  158,  108,   23,   24,   25,   26,   51,  107,  105,   52,
  106,   83,  108,   54,  110,  115,  114,  107,  105,  140,
  106,   55,  108,   73,  133,  110,  115,  114,  107,  105,
   74,  106,   82,  108,  150,  110,  115,  114,  107,  105,
  157,  106,   89,  108,   93,   95,  110,  115,  114,  107,
  105,  153,  106,   96,  108,  154,  110,  115,  114,   97,
    3,  104,   29,   98,   30,   79,  137,  110,  115,  114,
  134,   32,  138,  139,  142,    3,   33,   34,  169,  143,
    3,  156,    3,  165,    3,   30,    3,    3,  161,  175,
  166,  170,   32,    3,  171,    3,  172,   33,   34,  174,
  173,  176,  178,  177,   20,   35,   31,   38,   21,   10,
   40,  100,   56,   53,   49,  131,  159,  167,  168,    0,
    0,    0,  160,  144,  145,    0,   86,   71,   71,   71,
   71,   86,   87,    0,   57,   87,    0,   87,    0,  126,
   87,    0,    0,    0,    0,   57,  109,   86,  111,  112,
  113,  116,  117,   87,    0,  128,   87,   57,   86,    0,
    0,    0,    0,    0,   87,    0,  129,   87,   51,   51,
   51,   51,   51,   51,   51,    0,    0,    0,    0,    0,
   51,    0,    0,    0,    0,   23,   24,   25,   26,   27,
    0,  109,   51,  111,  112,  113,  116,  117,   29,    0,
   30,    0,    0,    0,    0,   31,    0,   32,    0,    0,
    0,    0,   33,   34,    0,  118,   35,  109,    0,  111,
  112,  113,  116,  117,   23,   24,   25,   26,  109,  135,
  111,  112,  113,  116,  117,    0,   84,    0,  109,    0,
  111,  112,  113,  116,  117,    0,    0,    0,    0,  109,
    0,  111,  112,  113,  116,  117,    0,    0,    0,  109,
    0,  111,  112,  113,  116,  117,    0,    0,    0,    0,
  109,    0,  111,  112,  113,  116,  117,
};
static const short yycheck[] = {                         40,
   45,   41,   54,   12,   44,   40,   41,   40,   40,  104,
   60,  257,   62,   63,   41,   42,   43,   40,   45,   59,
   47,  257,   61,   59,   58,   59,  272,  291,   78,   79,
    6,  258,  259,   60,   61,   62,   41,   42,   43,   44,
   45,  257,   47,   19,  257,   95,  276,  277,   87,  257,
  276,  277,   44,   93,   59,   60,   61,   62,   58,   40,
   42,   43,   45,   45,  272,   47,  161,   76,   91,  119,
  272,  279,   66,  281,  257,  283,  284,  127,   60,   61,
   62,  277,  290,  258,  292,  137,   42,   43,   93,   45,
  140,   47,  258,  259,  260,  261,   59,   42,   43,   59,
   45,   45,   47,   58,   60,   61,   62,   42,   43,   44,
   45,   41,   47,  257,   59,   60,   61,   62,   42,   43,
  288,   45,  257,   47,  118,   60,   61,   62,   42,   43,
  139,   45,  257,   47,  277,  264,   60,   61,   62,   42,
   43,  135,   45,   59,   47,   59,   60,   61,   62,   59,
  257,  264,  271,  258,  273,   91,  282,   60,   61,   62,
   59,  280,  277,   59,   41,  272,  285,  286,  162,   93,
  277,  257,  279,  277,  281,  273,  283,  284,  288,  173,
  277,  281,  280,  290,  275,  292,  257,  285,  286,  277,
  275,  281,  275,  277,  272,   58,   41,  277,   13,    4,
   17,   77,   46,   43,   22,   87,  143,  158,  161,   -1,
   -1,   -1,  146,  258,  259,   -1,  257,  258,  259,  260,
  261,  262,  257,   -1,  257,  257,   -1,  262,   -1,  262,
  262,   -1,   -1,   -1,   -1,  275,  263,  278,  265,  266,
  267,  268,  269,  278,   -1,  278,  278,  287,  289,   -1,
   -1,   -1,   -1,   -1,  289,   -1,  289,  289,  263,  264,
  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,
  275,   -1,   -1,   -1,   -1,  258,  259,  260,  261,  262,
   -1,  263,  287,  265,  266,  267,  268,  269,  271,   -1,
  273,   -1,   -1,   -1,   -1,  278,   -1,  280,   -1,   -1,
   -1,   -1,  285,  286,   -1,  287,  289,  263,   -1,  265,
  266,  267,  268,  269,  258,  259,  260,  261,  263,  275,
  265,  266,  267,  268,  269,   -1,  270,   -1,  263,   -1,
  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,  263,
   -1,  265,  266,  267,  268,  269,   -1,   -1,   -1,  263,
   -1,  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,
  263,   -1,  265,  266,  267,  268,  269,
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
"not_neg_ : '-'",
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
