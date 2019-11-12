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
    0,    1,    1,    4,    4,    5,    5,   10,   10,    8,
    8,    8,    8,    9,    6,   11,   11,   11,   11,    2,
    2,   13,   13,   12,   12,   15,   15,   15,   15,   16,
   14,   14,   18,    7,   19,   19,    3,   20,   20,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   23,   29,
   30,   30,   31,   31,   32,   32,   22,   22,   22,   34,
   34,   34,   33,   33,   33,   33,   33,   33,   17,   35,
   36,   37,   38,   38,   39,   39,   39,   39,   39,   39,
   40,   40,   40,   24,   24,   25,   26,   41,   41,   42,
   42,   43,   28,   27,
};
static const short yylen[] = {                            2,
    7,    2,    0,    1,    1,    5,    5,    1,    1,    1,
    1,    1,    1,    6,    5,    1,    1,    1,    1,    2,
    0,   10,    8,    1,    1,    1,    1,    1,    1,    2,
    2,    0,    3,    2,    3,    0,    4,    2,    0,    3,
    3,    1,    1,    1,    1,    4,    2,    2,    2,    1,
    4,    0,    2,    0,    3,    0,    3,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    8,    6,    6,   10,    1,    1,    1,
    1,    2,    2,    4,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    4,    5,    0,    0,
    0,    0,    0,    2,    0,   34,    0,    0,    0,    0,
   20,    0,   26,   27,   28,   29,   17,   69,    0,   13,
   19,   10,   11,   12,   18,    0,    0,    0,   16,   24,
   25,    0,    0,    0,    0,    0,    0,   35,    0,    6,
    7,   15,   30,    0,    0,   31,    0,    0,    0,    0,
    0,    0,    0,   42,    0,    0,    0,   43,   44,   45,
    0,    0,    1,    0,    8,    9,   33,    0,    0,    0,
    0,   49,   50,    0,    0,   62,    0,   60,   61,   59,
    0,    0,    0,    0,    0,   37,   38,    0,   47,   48,
    0,    0,    0,    0,    0,    0,    0,    0,   70,   71,
   72,   73,   74,   75,   76,   77,   78,   79,   80,   81,
   82,   83,    0,    0,   63,   64,   65,   66,   67,   68,
   40,   41,    0,    0,    0,    0,    0,    0,   53,   94,
    0,   90,   91,    0,    0,   88,   89,   57,    0,    0,
    0,   46,   14,   23,    0,    0,   51,   92,    0,    0,
    0,    0,    0,   55,    0,    0,   85,   86,   22,    0,
    0,    0,   84,    0,   87,
};
static const short yydgoto[] = {                          2,
    5,   12,   64,    6,    7,    8,   43,   75,   76,   77,
   86,   39,   13,   44,   40,   41,   42,   45,   16,   65,
   66,   87,   88,   68,   69,   70,   89,   72,   82,   83,
  105,  139,  124,   90,  125,  126,  127,  128,  129,  130,
  145,  146,  147,
};
static const short yysindex[] = {                      -244,
  -41,    0, -271, -227, -215, -271,    0,    0,   13,    1,
   26, -204, -215,    0, -182,    0,    6, -227, -271, -200,
    0,   13,    0,    0,    0,    0,    0,    0, -172,    0,
    0,    0,    0,    0,    0,   29,   37,   39,    0,    0,
    0,  -88,   32,   59, -227,  -92, -156,    0, -171,    0,
    0,    0,    0, -252,  -36,    0,  -24, -136,  -40,  -40,
 -127,  -40,  -40,    0, -135,  -92, -115,    0,    0,    0,
   91,   92,    0, -101,    0,    0,    0, -204, -133,  -40,
  -40,    0,    0, -106,  -40,    0,   -7,    0,    0,    0,
   52,   69,  103,   94,   31,    0,    0,  -40,    0,    0,
 -114, -110,  115,   63,  135,   73,  -44,   42,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -92,  -40,    0,    0,    0,    0,    0,    0,
    0,    0,  -92,   84, -252,  -80, -204,  -40,    0,    0,
   69,    0,    0, -211, -109,    0,    0,    0, -206,   94,
  -99,    0,    0,    0,  -94,   63,    0,    0,  -44,  -92,
  -97,  -87,  -67,    0,  -82,  -83,    0,    0,    0,  -92,
  -86,  -81,    0,  -78,    0,
};
static const short yyrindex[] = {                         0,
    0,    0, -226,    0,  -71, -240,    0,    0,  144,    0,
    0,    0,  -71,    0,    0,    0,    0,  162, -240,    0,
    0,  144,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  162,  -73,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -35,    0,    0,    0,
    0,    0,    0,    0,    0, -197,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  164,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   39,    0,  147,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  166,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -197,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -73,    0,    0,    0,    0,    0,    0,    0,
  -35,    0,    0,    0,    0,    0,    0,    0,    0,  -30,
    0,    0,    0,    0,    0,  166,    0,    0,    0,  -73,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -73,
    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
   43,  195,   -9,    0,    0,    0,  205,  -15,  193,   76,
  196,    0,    0,  167,  174,    0, -103,    0,  201,  -51,
    0,  101,   -1,    0,    0,    0,   15,    0,    0,   83,
    0,   70,    0,    0,    0,    0,    0,    0,    0,    0,
   68,   93,    0,
};
#define YYTABLESIZE 364
static const short yytable[] = {                         85,
   28,   36,   20,  144,   28,   52,   52,   52,   52,   52,
   58,   52,    1,   58,   97,   80,    3,    3,   29,    4,
   30,   79,   78,   52,   52,   52,   52,   32,   58,    9,
    3,    3,   33,   34,  111,  109,    3,  110,    3,  112,
    3,   11,    3,    3,   67,    3,  142,  143,   14,    3,
   28,    3,  114,  119,  118,  144,   15,   52,   17,   93,
   71,   46,   58,  103,   67,   18,   81,   19,  102,  160,
  161,  149,  111,  109,   22,  110,   47,  112,   39,   39,
   71,  151,  148,  111,  109,   49,  110,   50,  112,   54,
  114,  119,  118,  111,  109,   51,  110,   52,  112,   55,
   73,  114,  119,  118,  111,  109,  138,  110,  166,  112,
  131,  114,  119,  118,  111,  109,   74,  110,  172,  112,
   84,   67,  114,  119,  118,  111,  109,  155,  110,   92,
  112,   67,  114,  119,  118,  111,  109,   71,  110,   30,
  112,   96,  152,  114,  119,  118,   32,   71,   98,   99,
  100,   33,   34,  114,  119,  118,  101,  107,   67,   81,
   91,  132,   94,   95,   57,  141,  136,  135,   67,   23,
   24,   25,   26,  137,   71,  140,  154,  162,  159,   19,
  104,  106,  163,  167,   71,  108,   58,  168,   59,  169,
   60,   61,  170,  171,  173,  174,  175,   62,  134,   63,
   21,   36,   32,   39,   54,   93,   56,   21,   10,   37,
  153,   56,   38,  142,  143,   53,   57,   23,   24,   25,
   26,   27,   48,  157,  150,  164,  165,   52,   52,   52,
   52,   52,   52,   52,   52,    0,  158,   31,  156,   52,
    0,    0,    0,    0,   58,    0,    0,    0,   35,    0,
    0,   52,    0,    0,    0,  113,   58,  115,  116,  117,
  120,  121,  122,   23,   24,   25,   26,   27,    0,    0,
    0,    0,    0,    0,    0,    0,   29,    0,   30,  123,
    0,    0,    0,   31,    0,   32,    0,    0,    0,    0,
   33,   34,    0,  113,   35,  115,  116,  117,  120,  121,
  122,    0,    0,    0,  113,  133,  115,  116,  117,  120,
  121,  122,    0,    0,  113,    0,  115,  116,  117,  120,
  121,  122,    0,    0,    0,  113,    0,  115,  116,  117,
  120,  121,  122,    0,    0,  113,    0,  115,  116,  117,
  120,  121,  122,    0,    0,    0,  113,    0,  115,  116,
  117,  120,  121,  122,    0,    0,  113,    0,  115,  116,
  117,  120,  121,  122,
};
static const short yycheck[] = {                         40,
   45,   17,   12,  107,   45,   41,   42,   43,   44,   45,
   41,   47,  257,   44,   66,   40,  257,   59,  271,  291,
  273,   58,   59,   59,   60,   61,   62,  280,   59,  257,
  257,  272,  285,  286,   42,   43,  277,   45,  279,   47,
  281,  257,  283,  284,   46,  272,  258,  259,    6,  290,
   45,  292,   60,   61,   62,  159,   44,   93,   58,   61,
   46,   19,   93,   79,   66,   40,   91,  272,   78,  276,
  277,  123,   42,   43,  257,   45,  277,   47,  276,  277,
   66,  133,   41,   42,   43,  258,   45,   59,   47,   58,
   60,   61,   62,   42,   43,   59,   45,   59,   47,   41,
  257,   60,   61,   62,   42,   43,   44,   45,  160,   47,
   59,   60,   61,   62,   42,   43,  288,   45,  170,   47,
  257,  123,   60,   61,   62,   42,   43,  137,   45,  257,
   47,  133,   60,   61,   62,   42,   43,  123,   45,  273,
   47,  277,   59,   60,   61,   62,  280,  133,  264,   59,
   59,  285,  286,   60,   61,   62,  258,  264,  160,   91,
   60,   59,   62,   63,  257,   93,  277,  282,  170,  258,
  259,  260,  261,   59,  160,   41,  257,  277,  288,  272,
   80,   81,  277,  281,  170,   85,  279,  275,  281,  257,
  283,  284,  275,  277,  281,  277,  275,  290,   98,  292,
  272,   58,   41,  277,   41,   59,   41,   13,    4,   17,
  135,   45,   17,  258,  259,   42,  257,  258,  259,  260,
  261,  262,   22,  141,  124,  156,  159,  263,  264,  265,
  266,  267,  268,  269,  270,   -1,  144,  278,  138,  275,
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

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,
0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID","INT","OCTINT","FLOAT","SCI","STR","MOD",
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
"dec_var : VAR idlist ':' scalar_type ';'",
"dec_var : VAR idlist ':' arr_type ';'",
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
#line 468 "y.tab.c"

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
