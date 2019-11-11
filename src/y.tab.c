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
#define STRING 262
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
#define THEN 286
#define TO 287
#define TRUE 288
#define RETURN 289
#define VAR 290
#define WHILE 291
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    4,    4,    2,    2,    7,   10,   10,
    9,    9,    9,    9,    6,    6,   12,   12,   12,   12,
   13,    8,    8,   15,   16,   17,   17,    5,    5,   18,
   11,    6,   19,   19,   19,   19,   19,   19,   19,    3,
   20,   20,   21,   21,   21,   21,   22,   22,   24,   25,
   25,   26,   27,   27,   28,   28,   23,   23,   29,   29,
   29,   31,   31,   31,   31,   30,   30,   30,   30,   30,
   30,   14,   32,   33,   34,   35,   35,   36,   36,   36,
   36,   36,   36,   37,   37,   37,   38,   38,   39,   40,
   41,   41,   42,   42,   43,   44,   45,
};
static const short yylen[] = {                            2,
    7,    2,    0,    1,    1,    2,    0,   10,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    2,    2,    0,    3,    2,    3,    0,    5,    1,    5,
    6,    5,    1,    1,    1,    1,    1,    1,    1,    4,
    2,    0,    4,    3,    3,    3,    1,    1,    2,    4,
    0,    2,    3,    0,    2,    0,    4,    1,    3,    3,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    8,    6,    6,   10,
    1,    1,    1,    1,    2,    3,    5,
};
static const short yydefred[] = {                         0,
    0,    0,    0,   17,   18,   19,   20,   72,    0,    0,
    0,    4,    5,   15,   16,    0,   29,    0,    0,    0,
    0,    0,    2,   21,    0,   25,    0,    0,    0,    0,
    6,    0,   33,   34,   35,   36,   13,    0,   14,   39,
   11,   12,   38,    0,    0,    0,    0,    0,    0,    0,
    0,   26,    0,   28,   30,   32,    0,   22,    0,    0,
    0,    0,    0,    0,    0,   48,    1,    0,    0,   13,
    9,   24,   10,    0,   49,    0,   65,    0,   64,   63,
    0,   62,    0,    0,    0,   61,    0,   40,   41,    0,
    0,    0,    0,    0,    0,    0,    0,   44,   45,   73,
   74,   75,   76,   77,   78,   79,   80,   81,   82,   83,
   84,   85,   86,    0,   66,   67,   68,   69,   70,   71,
   46,    0,    0,    0,    0,    0,   59,    0,    0,   43,
   31,    0,   50,   57,   37,    0,    8,
};
static const short yydgoto[] = {                          2,
   10,   21,   30,   11,   12,   82,   22,   47,   71,   72,
   73,   14,   15,   16,   48,   49,   26,   17,   46,   63,
   64,   65,   84,   66,   75,    0,    0,    0,   85,  114,
   86,  115,  116,  117,  118,  119,  120,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const short yysindex[] = {                      -241,
  -42,    0,  -19,    0,    0,    0,    0,    0, -232, -227,
  -19,    0,    0,    0,    0, -239,    0,    1,    6,   18,
 -198, -227,    0,    0, -185,    0, -180, -232,  -19, -192,
    0,    1,    0,    0,    0,    0,    0, -171,    0,    0,
    0,    0,    0,   40,   43,   45,   66, -232,   51, -228,
 -146,    0, -173,    0,    0,    0,   58,    0, -170,   26,
  -40, -138, -157, -228, -143,    0,    0, -136, -167,    0,
    0,    0,    0,  -34,    0,  -88,    0,  -27,    0,    0,
 -232,    0,   64,   65,   28,    0,   67,    0,    0,  -34,
 -155,   69, -139,   37,  -27,   -1,   71,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -27,    0,    0,    0,    0,    0,    0,
    0,   72, -170, -198,   26,    7,    0, -225,   28,    0,
    0, -145,    0,    0,    0, -124,    0,
};
static const short yyrindex[] = {                         0,
    0,    0, -249,    0,    0,    0,    0,    0,    0, -137,
 -245,    0,    0,    0,    0,    0,    0,    6,    0,    0,
    0, -137,    0,    0,    0,    0,    0,   93, -200,    0,
    0,    6,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   93,    0, -141,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -58,
    0,    0,    0, -141,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   78,    0,    0,    0,    0,
    0,    0,    0,    0,  -45,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -57,    0,    0,    0,  -31,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
   36,  116,   15,    0,    0,   83,    0,   92,  -18,   19,
  114,  127,    0,    0,    0,   -5,  112,    0,    0,   81,
    0,   35,  -59,    0,   21,    0,    0,    0,  -71,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 298
static const short yytable[] = {                         78,
   47,   51,   74,   19,    8,   78,   96,    3,   44,   60,
    8,    3,   78,   58,   94,    1,    3,    8,    4,    5,
    6,    7,    3,  126,   18,    8,    3,   60,   60,   20,
  122,    3,   33,   34,   35,   36,  135,    3,    3,  127,
  102,  100,  129,  101,   25,  103,   23,   58,  102,  100,
   92,  101,   40,  103,   61,   62,    3,   28,  105,  110,
  109,   60,   43,   27,   50,  134,  105,  110,  109,  102,
  100,   32,  101,   29,  103,   97,    3,   33,   34,   35,
   36,   37,    3,    3,   51,   13,   53,  105,  110,  109,
   38,   70,   39,   13,   70,   83,   87,   40,   54,   41,
   38,   55,   39,   56,   42,   39,   57,   43,   59,   41,
   67,   13,   41,   68,   42,   69,   74,   42,   60,   88,
   90,   91,   98,   99,   95,  121,  123,  124,  128,  125,
  130,  136,  137,   23,    7,   42,   47,   31,  132,   58,
   45,  131,   24,   52,   89,  133,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   95,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   47,   51,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   76,    4,    5,    6,
    7,   77,   93,    4,    5,    6,    7,   77,    0,    0,
    4,    5,    6,    7,   77,    0,    0,   79,    4,    5,
    6,    7,    0,   79,    0,    0,    0,   80,    0,   81,
   79,    0,    0,   80,    0,   81,    0,    0,    0,    0,
   80,  104,   81,  106,  107,  108,  111,  112,  113,  104,
    9,  106,  107,  108,  111,  112,  113,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  104,    0,  106,  107,  108,  111,  112,  113,
};
static const short yycheck[] = {                         40,
   59,   59,   91,    9,   45,   40,   78,  257,   27,   41,
   45,  257,   40,   59,   74,  257,   59,   45,  258,  259,
  260,  261,  272,   95,  257,   45,  272,   59,  257,  257,
   90,  277,  258,  259,  260,  261,  262,  283,  284,   41,
   42,   43,  114,   45,   44,   47,   11,   93,   42,   43,
   69,   45,  278,   47,  283,  284,  257,   40,   60,   61,
   62,   93,  288,   58,   29,   59,   60,   61,   62,   42,
   43,  257,   45,  272,   47,   81,  277,  258,  259,  260,
  261,  262,  283,  284,  277,    3,  258,   60,   61,   62,
  271,  262,  273,   11,  262,   61,   62,  278,   59,  280,
  271,   59,  273,   59,  285,  273,   41,  288,   58,  280,
  257,   29,  280,  287,  285,   58,   91,  285,  257,  277,
  264,  258,   59,   59,  264,   59,  282,   59,   58,   93,
   59,  277,  257,   41,  272,  277,   59,   22,  124,   48,
   27,  123,   16,   32,   64,  125,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  264,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  264,  264,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
  261,  262,  257,  258,  259,  260,  261,  262,   -1,   -1,
  258,  259,  260,  261,  262,   -1,   -1,  278,  258,  259,
  260,  261,   -1,  278,   -1,   -1,   -1,  288,   -1,  290,
  278,   -1,   -1,  288,   -1,  290,   -1,   -1,   -1,   -1,
  288,  263,  290,  265,  266,  267,  268,  269,  270,  263,
  290,  265,  266,  267,  268,  269,  270,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  263,   -1,  265,  266,  267,  268,  269,  270,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 291
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,
0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID","INT","OCTINT","FLOAT","SCI","STRING","MOD",
"ASSIGN","LE","NE","GE","AND","OR","NOT","ARRAY","BGN","BOOLEAN","DEF","DO",
"ELSE","END","FALSE","FOR","INTEGER","IF","OF","PRINT","READ","REAL","THEN",
"TO","TRUE","RETURN","VAR","WHILE",
};
static const char *yyrule[] = {
"$accept : program",
"program : ID ';' vars_consts_ functions_ compound_statment END ID",
"vars_consts_ : var_const vars_consts_",
"vars_consts_ :",
"var_const : variable",
"var_const : constant",
"functions_ : function functions_",
"functions_ :",
"function : ID '(' formal_args_ ')' ':' scalar_type ';' compound_statment END ID",
"type : scalar_type",
"type : arr",
"scalar_type : INTEGER",
"scalar_type : REAL",
"scalar_type : STRING",
"scalar_type : BOOLEAN",
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
"variable : VAR idlist ':' scalar_type ';'",
"variable : vararr",
"vararr : VAR idlist ':' arr ';'",
"arr : ARRAY INT TO INT OF type",
"constant : VAR idlist ':' literal_constant ';'",
"literal_constant : INT",
"literal_constant : OCTINT",
"literal_constant : FLOAT",
"literal_constant : SCI",
"literal_constant : STRING",
"literal_constant : TRUE",
"literal_constant : FALSE",
"compound_statment : BGN vars_consts_ statements_ END",
"statements_ : statement statements_",
"statements_ :",
"statement : var_ref ASSIGN expr ';'",
"statement : PRINT var_ref ';'",
"statement : PRINT expr ';'",
"statement : READ var_ref ';'",
"var_ref : ID",
"var_ref : arr_ref",
"arr_ref : ID exprbs_",
"exprbs_ : '[' expr ']' exprbs_",
"exprbs_ :",
"exprcs : expr exprcs_",
"exprcs_ : ',' expr exprcs_",
"exprcs_ :",
"exprs_ : expr exprs_",
"exprs_ :",
"expr : ID ASSIGN items ';'",
"expr : items",
"items : '(' items ')'",
"items : items operator items",
"items : item",
"item : constant",
"item : TRUE",
"item : FALSE",
"item : STRING",
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
"rtrn : RETURN expr ';'",
"procedure : ID '(' exprcs ')' ';'",

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
#line 121 "parser.y"

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
#line 444 "y.tab.c"

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
