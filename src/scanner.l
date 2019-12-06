%{
#include <stdint.h>

#include "include/core/error.h"
#include "parser.h"

#define YY_USER_ACTION                                                         \
  yylloc.first_line = LineNum;                                                \
  yylloc.first_column = ColNum;                                               \
  ColNum += yyleng;

extern "C" int yylex();

#define LIST                strCat(yytext)
#define TOKEN(t)            {LIST; if (OptTok) printf("<%s>\n", #t);}
#define TOKEN_CHAR(t)       {LIST; if (OptTok) printf("<%c>\n", (t));}
#define TOKEN_STRING(t, s)  {LIST; if (OptTok) printf("<%s: %s>\n", #t, (s));}
#define MAX_LINE_LENG       512

uint32_t LineNum = 1;
uint32_t ColNum = 1;
char Buffer[MAX_LINE_LENG];

static int32_t OptSrc = 1;
static int32_t OptTok = 1;
static char StringLiteral[MAX_LINE_LENG];
static char *BufferPtr = Buffer;

static void strCat(const char *Text);

%}

integer 0|[1-9][0-9]*
float {integer}\.(0|[0-9]*[1-9])

%x CCOMMENT

%%
    /* Delimiter */
"," { TOKEN_CHAR(','); yylval.str=strdup(yytext); return COMMA; }
";" { TOKEN_CHAR(';'); yylval.str=strdup(yytext); return SEMICOLON; }
":" { TOKEN_CHAR(':'); yylval.str=strdup(yytext); return COLON; }
"(" { TOKEN_CHAR('('); yylval.str=strdup(yytext); return L_PARENTHESIS; }
")" { TOKEN_CHAR(')'); yylval.str=strdup(yytext); return R_PARENTHESIS; }
"[" { TOKEN_CHAR('['); yylval.str=strdup(yytext); return L_BRACKET; }
"]" { TOKEN_CHAR(']'); yylval.str=strdup(yytext); return R_BRACKET; }

    /* Operator */
"+"   { TOKEN_CHAR('+'); yylval.str=strdup(yytext); return PLUS; }
"-"   { TOKEN_CHAR('-'); yylval.str=strdup(yytext); return MINUS; }
"*"   { TOKEN_CHAR('*'); yylval.str=strdup(yytext); return MULTIPLY; }
"/"   { TOKEN_CHAR('/'); yylval.str=strdup(yytext); return DIVIDE; }
"mod" { TOKEN(mod);      yylval.str=strdup(yytext); return MOD; }
":="  { TOKEN(:=);       yylval.str=strdup(yytext); return ASSIGN; }
"<"   { TOKEN_CHAR('<'); yylval.str=strdup(yytext); return LESS; }
"<="  { TOKEN(<=);       yylval.str=strdup(yytext); return LESS_OR_EQUAL; }
"<>"  { TOKEN(<>);       yylval.str=strdup(yytext); return NOT_EQUAL; }
">="  { TOKEN(>=);       yylval.str=strdup(yytext); return GREATER_OR_EQUAL; }
">"   { TOKEN_CHAR('>'); yylval.str=strdup(yytext); return GREATER; }
"="   { TOKEN_CHAR('='); yylval.str=strdup(yytext); return EQUAL; }
"and" { TOKEN(and);      yylval.str=strdup(yytext); return AND; }
"or"  { TOKEN(or);       yylval.str=strdup(yytext); return OR; }
"not" { TOKEN(not);      yylval.str=strdup(yytext); return NOT; }

    /* Keyword */
"array"   { TOKEN(KWarray);   yylval.str=strdup(yytext); return ARRAY; }
"begin"   { TOKEN(KWbegin);   yylval.str=strdup(yytext); return BEGIN_; }
"boolean" { TOKEN(KWboolean); yylval.str=strdup(yytext); return BOOLEAN; }
"def"     { TOKEN(KWdef);     yylval.str=strdup(yytext); return DEF; }
"do"      { TOKEN(KWdo);      yylval.str=strdup(yytext); return DO; }
"else"    { TOKEN(KWelse);    yylval.str=strdup(yytext); return ELSE; }
"end"     { TOKEN(KWend);     yylval.str=strdup(yytext); return END; }
"false"   { TOKEN(KWfalse);   yylval.str=strdup(yytext); return FALSE; }
"for"     { TOKEN(KWfor);     yylval.str=strdup(yytext); return FOR; }
"integer" { TOKEN(KWinteger); yylval.str=strdup(yytext); return INTEGER; }
"if"      { TOKEN(KWif);      yylval.str=strdup(yytext); return IF; }
"of"      { TOKEN(KWof);      yylval.str=strdup(yytext); return OF; }
"print"   { TOKEN(KWprint);   yylval.str=strdup(yytext); return PRINT; }
"read"    { TOKEN(KWread);    yylval.str=strdup(yytext); return READ; }
"real"    { TOKEN(KWreal);    yylval.str=strdup(yytext); return REAL; }
"string"  { TOKEN(KWstring);  yylval.str=strdup(yytext); return STRING; }
"then"    { TOKEN(KWthen);    yylval.str=strdup(yytext); return THEN; }
"to"      { TOKEN(KWto);      yylval.str=strdup(yytext); return TO; }
"true"    { TOKEN(KWtrue);    yylval.str=strdup(yytext); return TRUE; }
"return"  { TOKEN(KWreturn);  yylval.str=strdup(yytext); return RETURN; }
"var"     { TOKEN(KWvar);     yylval.str=strdup(yytext); return VAR; }
"while"   { TOKEN(KWwhile);   yylval.str=strdup(yytext); return WHILE; }

    /* Identifier */
[a-zA-Z][a-zA-Z0-9]* { TOKEN_STRING(id, yytext); yylval.str=strdup(yytext); return ID; }

    /* Integer (decimal/octal) */
{integer} { TOKEN_STRING(integer, yytext);     yylval.str=strdup(yytext); return INT_LITERAL; }
0[0-7]+   { TOKEN_STRING(oct_integer, yytext); yylval.str=strdup(yytext); return INT_LITERAL; }

    /* Floating-Point */
{float} { TOKEN_STRING(float, yytext); yylval.str=strdup(yytext); return REAL_LITERAL; }

    /* Scientific Notation [Ee][+-]?[0-9]+ */
({integer}|{float})[Ee][+-]?({integer}) {
    TOKEN_STRING(scientific, yytext);
    yylval.str=strdup(yytext);
    return REAL_LITERAL;
}

    /* String */
\"([^"\n]|\"\")*\" {
    char *YytextPtr = yytext;
    char *StrPtr = StringLiteral;

    /* Condition guard of the end of string literal
       Check only when *YytextPtr == '"' */
    while (*(YytextPtr + 1) != '\0') {
        ++YytextPtr;

        /* Handle the situation of double quotes */
        if (*YytextPtr == '"' && *(YytextPtr + 1) != '\0')
            *StrPtr++ = *YytextPtr++;

        while (*YytextPtr != '"')
            *StrPtr++ = *YytextPtr++;
    }
    *StrPtr = '\0';
    TOKEN_STRING(string, StringLiteral);
    yylval.str=strdup(yytext);
    return STRING_LITERAL;
}
    /* Whitespace */
[ \t]+ { LIST; }

    /* Pseudocomment */
"//&"[ST][+-].* {
    LIST;
    char option = yytext[3];
    switch (option) {
    case 'S':
        OptSrc = (yytext[4] == '+') ? 1 : 0;
        break;
    case 'T':
        OptTok = (yytext[4] == '+') ? 1 : 0;
        break;
    }
}

    /* C++ Style Comment */
"//".* { LIST; }

    /* C Style Comment */
"/*"           { LIST; BEGIN(CCOMMENT); }
<CCOMMENT>"*/" { LIST; BEGIN(INITIAL); }
<CCOMMENT>.    { LIST; }

    /* Newline */
<INITIAL,CCOMMENT>\n {
    if (OptSrc)
        printf("%d: %s\n", LineNum, Buffer);
    ++LineNum;
    ColNum = 1;
    Buffer[0] = '\0';
    BufferPtr = Buffer;
}

    /* Catch the character which is not accepted by rules above */
. {
    printf("Error at line %d: bad character \"%s\"\n", LineNum, yytext);
    exit(-1);
}

%%

static void strCat(const char *Text) {
    while (*Text) {
        *BufferPtr++ = *Text++;
    }
    *BufferPtr = '\0';
}
