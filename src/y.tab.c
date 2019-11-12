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
   30,   31,   31,   32,   32,   22,   22,   22,   34,   34,
   34,   33,   33,   33,   33,   33,   33,   17,   35,   36,
   37,   38,   38,   39,   39,   39,   39,   39,   39,   40,
   40,   40,   24,   24,   25,   26,   41,   41,   42,   42,
   43,   28,   27,
};
static const short yylen[] = {                            2,
    7,    2,    0,    1,    1,    5,    1,    1,    1,    1,
    1,    1,    6,    5,    1,    1,    1,    1,    2,    0,
   10,    8,    1,    1,    1,    1,    1,    1,    2,    2,
    0,    3,    2,    3,    0,    4,    2,    0,    3,    3,
    1,    1,    1,    1,    4,    2,    2,    2,    1,    4,
    0,    2,    0,    3,    0,    3,    3,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    8,    6,    6,   10,    1,    1,    1,    1,
    2,    2,    4,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    4,    5,    0,    0,
    0,    0,    0,    2,    0,   33,    0,    0,    0,    0,
   19,    0,   25,   26,   27,   28,   16,   68,    0,   12,
   18,    9,   10,   11,   17,    0,    7,    8,    0,   15,
   23,   24,    0,    0,    0,    0,    0,    0,   34,    0,
    6,   14,   29,    0,    0,   30,    0,    0,    0,    0,
    0,    0,    0,   41,    0,    0,    0,   42,   43,   44,
    0,    0,    1,    0,   32,    0,    0,    0,    0,   48,
   49,    0,    0,   61,    0,   59,   60,   58,    0,    0,
    0,    0,    0,   36,   37,    0,   46,   47,    0,    0,
    0,    0,    0,    0,    0,    0,   69,   70,   71,   72,
   73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
    0,    0,   62,   63,   64,   65,   66,   67,   39,   40,
    0,    0,    0,    0,    0,    0,   52,   93,    0,   89,
   90,    0,    0,   87,   88,   56,    0,    0,    0,   45,
   13,   22,    0,    0,   50,   91,    0,    0,    0,    0,
    0,   54,    0,    0,   84,   85,   21,    0,    0,    0,
   83,    0,   86,
};
static const short yydgoto[] = {                          2,
    5,   12,   64,    6,    7,    8,   44,   36,   37,   38,
   84,   40,   13,   45,   41,   42,   43,   46,   16,   65,
   66,   85,   86,   68,   69,   70,   87,   72,   80,   81,
  103,  137,  122,   88,  123,  124,  125,  126,  127,  128,
  143,  144,  145,
};
static const short yysindex[] = {                      -237,
  -20,    0, -250, -213, -205, -250,    0,    0,   13,    2,
   19, -211, -205,    0, -193,    0,    6, -213, -250, -209,
    0,   13,    0,    0,    0,    0,    0,    0, -192,    0,
    0,    0,    0,    0,    0,   11,    0,    0,   12,    0,
    0,    0, -111,   22,   36, -213,  -79, -171,    0, -200,
    0,    0,    0, -252,  -55,    0,  -22, -167,  -40,  -40,
 -161,  -40,  -40,    0, -179,  -79, -164,    0,    0,    0,
   58,   62,    0, -157,    0, -211, -243,  -40,  -40,    0,
    0, -136,  -40,    0,   -7,    0,    0,    0,   52,   51,
   92,   94,   31,    0,    0,  -40,    0,    0, -130, -124,
   98,   63,  117,   73,  -44,   42,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -79,  -40,    0,    0,    0,    0,    0,    0,    0,    0,
  -79,   84, -252,  -97, -211,  -40,    0,    0,   51,    0,
    0, -236, -126,    0,    0,    0, -230,   94, -112,    0,
    0,    0, -107,   63,    0,    0,  -44,  -79, -110, -103,
  -84,    0, -101, -102,    0,    0,    0,  -79, -105,  -96,
    0,  -93,    0,
};
static const short yyrindex[] = {                         0,
    0,    0, -241,    0,  -87,  -89,    0,    0,  128,    0,
    0,    0,  -87,    0,    0,    0,    0,  146,  -89,    0,
    0,  128,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  146,  -88,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -35,    0,    0,    0,
    0,    0,    0,    0,    0, -227,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  150,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   11,
    0,  137,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   36,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -227,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -88,    0,    0,    0,    0,    0,    0,    0,  -35,    0,
    0,    0,    0,    0,    0,    0,    0,  -30,    0,    0,
    0,    0,    0,   36,    0,    0,    0,  -88,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -88,    0,    0,
    0,    0,    0,
};
static const short yygindex[] = {                         0,
   26,  185,    3,    0,    0,    0,  195,  -52,  129,    0,
  190,    0,    0,  162,  166,    0,  -92,    0,  188,  -49,
    0,  101,    1,    0,    0,    0,    9,    0,    0,   77,
    0,   70,    0,    0,    0,    0,    0,    0,    0,    0,
   55,   83,    0,
};
#define YYTABLESIZE 364
static const short yytable[] = {                         83,
   28,   75,   77,   76,   28,   51,   51,   51,   51,   51,
   57,   51,  142,   57,   20,    3,   95,   78,   29,    1,
   30,  140,  141,   51,   51,   51,   51,   32,   57,   30,
    3,   14,   33,   34,  109,  107,   32,  108,    3,  110,
    4,   33,   34,    9,   47,  158,  159,   67,   38,   38,
   28,   11,  112,  117,  116,   71,   15,   51,   18,   17,
   19,   91,   57,   22,  142,   50,   67,   48,   79,   51,
   52,  147,  109,  107,   71,  108,   55,  110,  100,   54,
  151,  149,  146,  109,  107,   73,  108,   74,  110,   82,
  112,  117,  116,  109,  107,   90,  108,   94,  110,   96,
   99,  112,  117,  116,  109,  107,  136,  108,  164,  110,
  129,  112,  117,  116,  109,  107,   97,  108,  170,  110,
   98,   67,  112,  117,  116,  109,  107,  105,  108,   71,
  110,   67,  112,  117,  116,  109,  107,  153,  108,   71,
  110,   79,  150,  112,  117,  116,   23,   24,   25,   26,
  130,  133,  134,  112,  117,  116,  135,  138,   67,  152,
   89,  157,   92,   93,  160,  139,   71,    3,   67,  161,
  165,  166,  167,  168,  169,  171,   71,   57,  102,  104,
  172,  173,    3,  106,   20,   35,   31,    3,   38,    3,
   53,    3,   19,    3,    3,   92,  132,   21,   10,   58,
    3,   59,    3,   60,   61,  101,   39,   56,   53,   49,
   62,  163,   63,  140,  141,  155,   57,   23,   24,   25,
   26,   27,  148,  162,  156,    0,    0,   51,   51,   51,
   51,   51,   51,   51,   51,    0,  154,   31,    0,   51,
    0,    0,    0,    0,   57,    0,    0,    0,   35,    0,
    0,   51,    0,    0,    0,  111,   57,  113,  114,  115,
  118,  119,  120,   23,   24,   25,   26,   27,    0,    0,
    0,    0,    0,    0,    0,    0,   29,    0,   30,  121,
    0,    0,    0,   31,    0,   32,    0,    0,    0,    0,
   33,   34,    0,  111,   35,  113,  114,  115,  118,  119,
  120,    0,    0,    0,  111,  131,  113,  114,  115,  118,
  119,  120,    0,    0,  111,    0,  113,  114,  115,  118,
  119,  120,    0,    0,    0,  111,    0,  113,  114,  115,
  118,  119,  120,    0,    0,  111,    0,  113,  114,  115,
  118,  119,  120,    0,    0,    0,  111,    0,  113,  114,
  115,  118,  119,  120,    0,    0,  111,    0,  113,  114,
  115,  118,  119,  120,
};
static const short yycheck[] = {                         40,
   45,   54,   58,   59,   45,   41,   42,   43,   44,   45,
   41,   47,  105,   44,   12,  257,   66,   40,  271,  257,
  273,  258,  259,   59,   60,   61,   62,  280,   59,  273,
  272,    6,  285,  286,   42,   43,  280,   45,   59,   47,
  291,  285,  286,  257,   19,  276,  277,   47,  276,  277,
   45,  257,   60,   61,   62,   47,   44,   93,   40,   58,
  272,   61,   93,  257,  157,  258,   66,  277,   91,   59,
   59,  121,   42,   43,   66,   45,   41,   47,   76,   58,
  133,  131,   41,   42,   43,  257,   45,  288,   47,  257,
   60,   61,   62,   42,   43,  257,   45,  277,   47,  264,
  258,   60,   61,   62,   42,   43,   44,   45,  158,   47,
   59,   60,   61,   62,   42,   43,   59,   45,  168,   47,
   59,  121,   60,   61,   62,   42,   43,  264,   45,  121,
   47,  131,   60,   61,   62,   42,   43,  135,   45,  131,
   47,   91,   59,   60,   61,   62,  258,  259,  260,  261,
   59,  282,  277,   60,   61,   62,   59,   41,  158,  257,
   60,  288,   62,   63,  277,   93,  158,  257,  168,  277,
  281,  275,  257,  275,  277,  281,  168,  257,   78,   79,
  277,  275,  272,   83,  272,   58,   41,  277,  277,  279,
   41,  281,  272,  283,  284,   59,   96,   13,    4,  279,
  290,  281,  292,  283,  284,   77,   17,   46,   43,   22,
  290,  157,  292,  258,  259,  139,  257,  258,  259,  260,
  261,  262,  122,  154,  142,   -1,   -1,  263,  264,  265,
  266,  267,  268,  269,  270,   -1,  136,  278,   -1,  275,
   -1,   -1,   -1,   -1,  275,   -1,   -1,   -1,  289,   -1,
   -1,  287,   -1,   -1,   -1,  263,  287,  265,  266,  267,
  268,  269,  270,  258,  259,  260,  261,  262,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  271,   -1,  273,  287,
   -1,   -1,   -1,  278,   -1,  280,   -1,   -1,   -1,   -1,
  285,  286,   -1,  263,  289,  265,  266,  267,  268,  269,
  270,   -1,   -1,   -1,  263,  275,  265,  266,  267,  268,
  269,  270,   -1,   -1,  263,   -1,  265,  266,  267,  268,
  269,  270,   -1,   -1,   -1,  263,   -1,  265,  266,  267,
  268,  269,  270,   -1,   -1,  263,   -1,  265,  266,  267,
  268,  269,  270,   -1,   -1,   -1,  263,   -1,  265,  266,
  267,  268,  269,  270,   -1,   -1,  263,   -1,  265,  266,
  267,  268,  269,  270,
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
"expr : '(' expr ')'",
"expr : expr operator expr",
"expr : item",
"item : var_ref",
"item : procedure",
"item : literal_const",
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
"log : NOT",
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
#line 102 "parser.y"

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
#line 467 "y.tab.c"

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
