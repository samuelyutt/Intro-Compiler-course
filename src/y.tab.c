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
   17,   37,   38,   39,   40,   40,   41,   41,   41,   41,
   41,   41,   42,   42,   36,   36,   33,   33,   24,   24,
   25,   26,   43,   43,   44,   44,   45,   28,   27,
};
static const short yylen[] = {                            2,
    7,    2,    0,    1,    1,    5,    1,    1,    1,    1,
    1,    1,    6,    5,    1,    1,    1,    1,    2,    0,
   10,    8,    1,    1,    1,    1,    1,    1,    2,    2,
    0,    3,    2,    3,    0,    4,    2,    0,    3,    3,
    1,    1,    1,    1,    4,    2,    2,    2,    1,    4,
    0,    2,    0,    3,    0,    4,    3,    2,    2,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    0,    1,    1,    8,    6,
    6,   10,    1,    1,    1,    1,    2,    2,    4,
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
   49,    0,   62,    0,   85,   60,   61,    0,    0,    0,
    0,    0,    0,    0,    0,   36,   37,    0,   46,   47,
    0,    0,    0,    0,    0,    0,    0,   72,   73,   74,
   75,   76,   77,   78,   79,   80,   81,   82,   83,   84,
    0,    0,   65,   66,   67,   68,   69,   70,    0,   63,
   64,   58,   59,   39,   40,    0,    0,    0,    0,    0,
    0,   52,   99,    0,   95,   96,    0,    0,   93,   94,
    0,    0,    0,    0,   45,   13,   22,    0,    0,   50,
   97,    0,    0,    0,   56,    0,    0,   54,    0,    0,
   90,   91,   21,    0,    0,    0,   89,    0,   92,
};
static const short yydgoto[] = {                          2,
    5,   12,   64,    6,    7,    8,   44,   36,   37,   38,
   39,   87,   13,   45,   41,   42,   43,   46,   16,   65,
   66,   88,   67,   68,   69,   70,   71,   72,   80,   81,
  105,  142,   89,  122,  132,   90,  123,  124,  125,  126,
  127,  128,  148,  149,  150,
};
static const short yysindex[] = {                      -239,
  -22,    0, -270, -218, -215, -270,    0,    0,    2,  -14,
   10, -217, -215,    0, -200,    0,    3, -218, -270, -213,
    0,    2,    0,    0,    0,    0,    0,    0, -184,    0,
    0,    0,    0,    0,    0,   34,    0,    0,   36,    0,
    0,    0, -192,   27,   57, -218, -112, -151,    0, -172,
    0,    0,    0, -245,    4,    0,  -26, -130,  -25,  -25,
 -128,  -25,  -25,    0, -140, -112, -125,    0,    0,    0,
   85,   87,    0, -110,    0, -217, -226,  -25,  -25,    0,
    0, -115,    0,    0,    0,    0,    0,   -9,  -11, -135,
   49,   65,   99,   91,   28,    0,    0,  -25,    0,    0,
 -118, -111,  106,   60,  132,   70,  -34,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -112,  -25,    0,    0,    0,    0,    0,    0,  -25,    0,
    0,    0,    0,    0,    0, -112,   81, -245,  -83, -217,
  -25,    0,    0,   65,    0,    0, -182, -113,    0,    0,
 -198,   91,   39, -101,    0,    0,    0, -100,   60,    0,
    0,  -34, -112, -102,    0,  -94,  -75,    0,  -92,  -93,
    0,    0,    0, -112,  -96,  -91,    0,  -88,    0,
};
static const short yyrindex[] = {                         0,
    0,    0, -241,    0,  -84, -122,    0,    0,  131,    0,
    0,    0,  -84,    0,    0,    0,    0,  149, -122,    0,
    0,  131,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  149,  -86,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -37,    0,  -38,  -38,
    0,  -38,  -38,    0,    0, -158,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -40,  -38,    0,
    0,    0,    0,    9,    0,    0,    0,    0,    0,  -10,
    0,   34,    0,  133,    0,    0,    0,  -38,    0,    0,
    0,    0,    0,   57,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -158,  -38,    0,    0,    0,    0,    0,    0,  -38,    0,
    0,    0,    0,    0,    0,  -86,    0,    0,    0,    0,
  -38,    0,    0,  -37,    0,    0,    0,    0,    0,    0,
    0,  -32,    0,    0,    0,    0,    0,    0,   57,    0,
    0,    0,  -86,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -86,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
   26,  180,    7,    0,    0,    0,  190,  -41,  118,    0,
    0,  179,    0,  151,  155,    0, -104,    0,  177,  -49,
    0,  301,  -46,    0,    0,    0,  111,    0,    0,   58,
    0,   42,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   41,   59,    0,
};
#define YYTABLESIZE 442
static const short yytable[] = {                         86,
   53,   86,  147,   51,   51,   51,   51,   51,   57,   51,
   28,   57,   75,   78,   93,    3,   97,    1,   20,   84,
    4,   51,   51,   51,   51,   29,   57,   30,  129,   88,
    3,   14,  110,  108,   32,  109,    3,  111,    9,   33,
   34,   11,  130,   17,   47,   15,   30,   28,   87,   18,
  113,  118,  117,   32,   19,   51,   22,  147,   33,   34,
   57,   77,   76,   48,   79,   23,   24,   25,   26,  110,
  108,  151,  109,   50,  111,  145,  146,  163,  164,  165,
  110,  108,  102,  109,   54,  111,  154,  113,  118,  117,
  110,  108,   51,  109,   52,  111,  156,   55,  113,  118,
  117,  110,  108,  141,  109,   73,  111,  134,  113,  118,
  117,  110,  108,  170,  109,   74,  111,   38,   38,  113,
  118,  117,  110,  108,  176,  109,   82,  111,   92,  113,
  118,  117,  110,  108,    3,  109,   96,  111,   98,  155,
  113,  118,  117,   99,   57,  100,  158,  101,  107,    3,
  113,  118,  117,  133,    3,   79,    3,  135,    3,   19,
    3,    3,  144,  138,  140,  139,   58,    3,   59,    3,
   60,   61,  143,  157,  162,  166,  167,   62,  171,   63,
  172,  173,  174,  175,  177,  178,  179,   20,   35,   31,
   38,   98,   21,   10,  103,   40,   56,   53,   49,  131,
  168,  160,  169,    0,    0,  161,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   86,    0,   86,    0,
    0,    0,    0,  145,  146,   51,   51,   51,   51,   51,
   51,   51,   23,   24,   25,   26,   83,   51,    0,    0,
    0,    0,   57,    0,   85,   57,   88,    0,   86,   51,
   86,    0,   86,  112,   57,  114,  115,  116,  119,  120,
   23,   24,   25,   26,   27,   87,   71,   71,   71,   71,
    0,    0,    0,   29,    0,   30,    0,  121,    0,    0,
   31,    0,   32,    0,    0,    0,    0,   33,   34,    0,
  112,   35,  114,  115,  116,  119,  120,    0,    0,    0,
    0,  112,  136,  114,  115,  116,  119,  120,    0,    0,
    0,  112,    0,  114,  115,  116,  119,  120,    0,    0,
    0,    0,  112,    0,  114,  115,  116,  119,  120,    0,
    0,    0,  112,    0,  114,  115,  116,  119,  120,    0,
    0,    0,    0,  112,    0,  114,  115,  116,  119,  120,
    0,    0,    0,  112,    0,  114,  115,  116,  119,  120,
   91,    0,   94,   95,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  104,  106,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  137,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  152,    0,    0,    0,    0,    0,    0,  153,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  159,
};
static const short yycheck[] = {                         40,
   41,   40,  107,   41,   42,   43,   44,   45,   41,   47,
   45,   44,   54,   40,   61,  257,   66,  257,   12,   45,
  291,   59,   60,   61,   62,  271,   59,  273,   40,   40,
  272,    6,   42,   43,  280,   45,   59,   47,  257,  285,
  286,  257,   89,   58,   19,   44,  273,   45,   40,   40,
   60,   61,   62,  280,  272,   93,  257,  162,  285,  286,
   93,   58,   59,  277,   91,  258,  259,  260,  261,   42,
   43,  121,   45,  258,   47,  258,  259,  276,  277,   41,
   42,   43,   76,   45,   58,   47,  136,   60,   61,   62,
   42,   43,   59,   45,   59,   47,  138,   41,   60,   61,
   62,   42,   43,   44,   45,  257,   47,   59,   60,   61,
   62,   42,   43,  163,   45,  288,   47,  276,  277,   60,
   61,   62,   42,   43,  174,   45,  257,   47,  257,   60,
   61,   62,   42,   43,  257,   45,  277,   47,  264,   59,
   60,   61,   62,   59,  257,   59,  140,  258,  264,  272,
   60,   61,   62,  289,  277,   91,  279,   59,  281,  272,
  283,  284,   93,  282,   59,  277,  279,  290,  281,  292,
  283,  284,   41,  257,  288,  277,  277,  290,  281,  292,
  275,  257,  275,  277,  281,  277,  275,  272,   58,   41,
  277,   59,   13,    4,   77,   17,   46,   43,   22,   89,
  159,  144,  162,   -1,   -1,  147,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,  257,   -1,
   -1,   -1,   -1,  258,  259,  263,  264,  265,  266,  267,
  268,  269,  258,  259,  260,  261,  262,  275,   -1,   -1,
   -1,   -1,  275,   -1,  270,  257,  257,   -1,  289,  287,
  289,   -1,  278,  263,  287,  265,  266,  267,  268,  269,
  258,  259,  260,  261,  262,  257,  258,  259,  260,  261,
   -1,   -1,   -1,  271,   -1,  273,   -1,  287,   -1,   -1,
  278,   -1,  280,   -1,   -1,   -1,   -1,  285,  286,   -1,
  263,  289,  265,  266,  267,  268,  269,   -1,   -1,   -1,
   -1,  263,  275,  265,  266,  267,  268,  269,   -1,   -1,
   -1,  263,   -1,  265,  266,  267,  268,  269,   -1,   -1,
   -1,   -1,  263,   -1,  265,  266,  267,  268,  269,   -1,
   -1,   -1,  263,   -1,  265,  266,  267,  268,  269,   -1,
   -1,   -1,   -1,  263,   -1,  265,  266,  267,  268,  269,
   -1,   -1,   -1,  263,   -1,  265,  266,  267,  268,  269,
   60,   -1,   62,   63,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   78,   79,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   98,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  122,   -1,   -1,   -1,   -1,   -1,   -1,  129,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  141,
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
"expr : not_ TRUE",
"expr : FALSE",
"expr : const",
"expr : STR",
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
"not_ : NOT",
"not_ :",
"not_neg_ : '-'",
"not_neg_ : not_",
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
#line 489 "y.tab.c"

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
