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
   21,   21,   21,   21,   21,   21,   21,   23,   28,   29,
   29,   30,   30,   31,   31,   22,   22,   32,   32,   32,
   34,   34,   34,   33,   33,   33,   33,   33,   33,   17,
   36,   37,   38,   39,   39,   40,   40,   40,   40,   40,
   40,   41,   41,   41,   24,   24,   25,   26,   42,   42,
   43,   43,   44,   27,   35,
};
static const short yylen[] = {                            2,
    7,    2,    0,    1,    1,    5,    5,    1,    1,    1,
    1,    1,    1,    6,    5,    1,    1,    1,    1,    2,
    0,   10,    8,    1,    1,    1,    1,    1,    1,    2,
    2,    0,    3,    2,    3,    0,    4,    2,    0,    3,
    3,    1,    1,    1,    1,    2,    2,    2,    1,    4,
    0,    2,    0,    3,    0,    1,    3,    3,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    8,    6,    6,   10,    1,    1,
    1,    1,    2,    2,    4,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    4,    5,    0,    0,
    0,    0,    0,    2,    0,   34,    0,    0,    0,    0,
   20,    0,   26,   27,   28,   29,   17,   70,    0,   13,
   19,   10,   11,   12,   18,    0,    0,    0,   16,   24,
   25,    0,    0,    0,    0,    0,    0,   35,    0,    6,
    7,   15,   30,    0,    0,   31,    0,    0,    0,    0,
    0,    0,    0,    0,   42,   63,    0,    0,    0,    0,
   43,   44,   45,    0,    0,   60,   62,    1,    0,    8,
    9,   33,    0,    0,    0,    0,   48,   49,   61,    0,
    0,    0,    0,    0,    0,   94,    0,   37,   38,   46,
    0,   47,   71,   72,   73,   74,   75,   76,   77,   78,
   79,   80,   81,   82,   83,   84,    0,   64,   65,   66,
   67,   68,   69,    0,    0,    0,    0,    0,    0,   58,
    0,    0,   40,   41,    0,    0,    0,    0,    0,    0,
    0,   52,   95,    0,   91,   92,    0,    0,   89,   90,
    0,    0,   14,   23,    0,    0,   50,   93,    0,    0,
    0,    0,    0,   54,    0,    0,   86,   87,   22,    0,
    0,    0,   85,    0,   88,
};
static const short yydgoto[] = {                          2,
    5,   12,   65,    6,    7,    8,   43,   80,   81,   82,
   66,   39,   13,   44,   40,   41,   42,   45,   16,   67,
   68,   69,   70,   71,   72,   73,   74,   87,   88,  128,
  142,   75,  117,   76,   77,  118,  119,  120,  121,  122,
  123,  148,  149,  150,
};
static const short yysindex[] = {                      -237,
  -24,    0, -246, -210, -208, -246,    0,    0,    7,   -2,
   20, -205, -208,    0, -177,    0,   60, -210, -246, -190,
    0,    7,    0,    0,    0,    0,    0,    0, -165,    0,
    0,    0,    0,    0,    0,   40,   49,   50,    0,    0,
    0, -221,   53,   71, -210,   -4, -142,    0, -172,    0,
    0,    0,    0, -227,  -41,    0,  -30,    3, -140,    3,
    3, -139,    3,    3,    0,    0, -158,   -4,   61, -143,
    0,    0,    0,   63,   90,    0,    0,    0, -134,    0,
    0,    0, -205, -216,    3,    3,    0,    0,    0,  -39,
 -138, -162,   68,   38,   69,    0, -144,    0,    0,    0,
    3,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,    0,    0,    0,
    0,    0,    0, -146, -137,   79,   95,  100,   51,    0,
  -44,   -4,    0,    0,   -4,   90,   90, -227, -115, -205,
    3,    0,    0,   38,    0,    0, -234, -145,    0,    0,
 -214, -132,    0,    0, -131,   95,    0,    0,  -44,   -4,
 -133, -126, -104,    0, -120, -121,    0,    0,    0,   -4,
 -124, -119,    0, -116,    0,
};
static const short yyrindex[] = {                         0,
    0,    0, -238,    0, -112,  -40,    0,    0,  103,    0,
    0,    0, -112,    0,    0,    0,    0,  121,  -40,    0,
    0,  103,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  121, -114,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   30,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -170,    0,   41,
    0,    0,    0,    0,  -28,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  123,    0,    0,    0,    0,    0,
    0,    0,    0,   49,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   71,    0,    0,    0,
    0, -170,    0,    0, -114,   37,   54,    0,    0,    0,
    0,    0,    0,   30,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   71,    0,    0,    0, -114,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -114,
    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    9,  152,   14,    0,    0,    0,  162,   10,  150,   31,
  151,    0,    0,  125,  129,    0, -117,    0,  153,  -56,
    0,  -31,  -51,    0,    0,    0,    0,    0,   28,    0,
   17,  -49,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   15,   29,    0,
};
#define YYTABLESIZE 360
static const short yytable[] = {                          3,
   28,  130,  105,  103,    3,  104,   89,  106,   90,   85,
   95,   99,   56,  147,   14,   56,   84,   83,    3,    1,
  108,  113,  112,  145,  146,   20,   36,   46,   92,   93,
   56,   96,   97,    3,    3,   58,   23,   24,   25,   26,
   28,  147,   58,   29,    4,   30,    9,   28,   11,   89,
   15,  136,   32,  127,  129,   17,   30,   33,   34,   18,
   86,  160,  161,   32,   56,   89,   19,  137,   33,   34,
   51,   51,   51,   51,   51,  151,   51,   57,  152,   22,
   57,   61,   61,   61,   61,   61,   47,   61,   51,   51,
   51,   51,   49,  126,   59,   57,  125,   59,   50,   61,
   61,   61,   61,  166,   28,   39,   39,   51,   52,  156,
   54,   55,   59,  172,   78,   79,   91,   94,   98,  100,
  101,  102,   51,  124,  132,  131,  133,  134,   86,   57,
  135,  105,  103,   61,  104,  138,  106,  140,  141,  139,
  143,  154,  159,  144,  162,  163,   59,  167,  168,  108,
  113,  112,  169,  155,  170,  171,  173,  174,  175,   21,
   36,   32,   39,   53,   21,   10,   37,   38,  153,   56,
   53,  157,  164,  165,   48,  158,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  145,  146,    0,    3,    3,    3,    3,
    3,    3,    0,  107,    0,  109,  110,  111,  114,  115,
  116,    3,    0,    0,    0,    0,    3,    3,    3,    0,
    3,    0,    3,    3,    0,    0,   56,    0,    3,    3,
    0,    3,   57,   23,   24,   25,   26,   27,   56,   57,
   23,   24,   25,   26,   27,    0,    0,   19,    0,    0,
    0,    0,    0,   31,   59,    0,   60,    0,   61,   62,
   31,    0,    0,    0,   35,   63,    0,   64,    0,    0,
    0,   35,   51,   51,   51,   51,   51,   51,   51,   51,
    0,    0,    0,   61,   51,   61,   61,   61,   61,   61,
   61,   57,    0,    0,    0,   61,   51,   23,   24,   25,
   26,   27,    0,   57,    0,    0,    0,   61,   59,    0,
   29,    0,   30,    0,    0,    0,    0,   31,    0,   32,
   59,    0,    0,    0,   33,   34,    0,    0,   35,    0,
    0,    0,  107,    0,  109,  110,  111,  114,  115,  116,
};
static const short yycheck[] = {                         40,
   45,   41,   42,   43,   45,   45,   58,   47,   58,   40,
   62,   68,   41,  131,    6,   44,   58,   59,  257,  257,
   60,   61,   62,  258,  259,   12,   17,   19,   60,   61,
   59,   63,   64,  272,   59,   40,  258,  259,  260,  261,
   45,  159,   40,  271,  291,  273,  257,   45,  257,  101,
   44,  101,  280,   85,   86,   58,  273,  285,  286,   40,
   91,  276,  277,  280,   93,  117,  272,  117,  285,  286,
   41,   42,   43,   44,   45,  132,   47,   41,  135,  257,
   44,   41,   42,   43,   44,   45,  277,   47,   59,   60,
   61,   62,  258,   84,   41,   59,   83,   44,   59,   59,
   60,   61,   62,  160,   45,  276,  277,   59,   59,  141,
   58,   41,   59,  170,  257,  288,  257,  257,  277,   59,
  264,   59,   93,  258,  287,  264,   59,   59,   91,   93,
  275,   42,   43,   93,   45,  282,   47,   59,   44,  277,
   41,  257,  288,   93,  277,  277,   93,  281,  275,   60,
   61,   62,  257,  140,  275,  277,  281,  277,  275,  272,
   58,   41,  277,   41,   13,    4,   17,   17,  138,   45,
   42,  144,  156,  159,   22,  147,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  258,  259,   -1,  257,  258,  259,  260,
  261,  262,   -1,  263,   -1,  265,  266,  267,  268,  269,
  270,  272,   -1,   -1,   -1,   -1,  277,  278,  279,   -1,
  281,   -1,  283,  284,   -1,   -1,  275,   -1,  289,  290,
   -1,  292,  257,  258,  259,  260,  261,  262,  287,  257,
  258,  259,  260,  261,  262,   -1,   -1,  272,   -1,   -1,
   -1,   -1,   -1,  278,  279,   -1,  281,   -1,  283,  284,
  278,   -1,   -1,   -1,  289,  290,   -1,  292,   -1,   -1,
   -1,  289,  263,  264,  265,  266,  267,  268,  269,  270,
   -1,   -1,   -1,  263,  275,  265,  266,  267,  268,  269,
  270,  275,   -1,   -1,   -1,  275,  287,  258,  259,  260,
  261,  262,   -1,  287,   -1,   -1,   -1,  287,  275,   -1,
  271,   -1,  273,   -1,   -1,   -1,   -1,  278,   -1,  280,
  287,   -1,   -1,   -1,  285,  286,   -1,   -1,  289,   -1,
   -1,   -1,  263,   -1,  265,  266,  267,  268,  269,  270,
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
"program : ID ';' vars_consts_ functions_ compound_statment END ID",
"vars_consts_ : var_const vars_consts_",
"vars_consts_ :",
"var_const : variable",
"var_const : varconstant",
"variable : VAR idlist ':' scalar_type ';'",
"variable : VAR idlist ':' arr_type ';'",
"type : scalar_type",
"type : arr_type",
"scalar_type : INTEGER",
"scalar_type : REAL",
"scalar_type : STRING",
"scalar_type : BOOLEAN",
"arr_type : ARRAY INT TO INT OF type",
"varconstant : VAR idlist ':' literal_constant ';'",
"literal_constant : constant",
"literal_constant : STR",
"literal_constant : TRUE",
"literal_constant : FALSE",
"functions_ : function functions_",
"functions_ :",
"function : ID '(' formal_args_ ')' ':' scalar_type ';' compound_statment END ID",
"function : ID '(' formal_args_ ')' ';' compound_statment END ID",
"constant : pos_constant",
"constant : neg_constant",
"pos_constant : INT",
"pos_constant : OCTINT",
"pos_constant : FLOAT",
"pos_constant : SCI",
"neg_constant : neg pos_constant",
"formal_args_ : formal_arg formal_args_",
"formal_args_ :",
"formal_arg : idlist ':' type",
"idlist : ID ids_",
"ids_ : ',' ID ids_",
"ids_ :",
"compound_statment : BGN vars_consts_ statements_ END",
"statements_ : statement statements_",
"statements_ :",
"statement : PRINT expr ';'",
"statement : READ var_ref ';'",
"statement : compound_statment",
"statement : condition",
"statement : whileloop",
"statement : forloop",
"statement : expr ';'",
"statement : rtrn ';'",
"var_ref : ID arr_ref",
"arr_ref : exprbs_",
"exprbs_ : '[' expr ']' exprbs_",
"exprbs_ :",
"exprcs_ : expr exprcs",
"exprcs_ :",
"exprcs : ',' expr exprcs",
"exprcs :",
"expr : items",
"expr : var_ref ASSIGN items",
"items : '(' items ')'",
"items : items operator items",
"items : item",
"item : var_ref",
"item : procedure",
"item : literal_constant",
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
"condition : IF expr THEN statements_ ELSE statements_ END IF",
"condition : IF expr THEN statements_ END IF",
"whileloop : WHILE expr DO statements_ END DO",
"forloop : FOR ID ASSIGN int_const TO int_const DO statements_ END DO",
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
#line 118 "parser.y"

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
