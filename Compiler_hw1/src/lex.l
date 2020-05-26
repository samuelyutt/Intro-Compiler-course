%{
#define LIST               strcat(buf, yytext)
#define token(t)           {LIST; if (Opt_T) printf("<%s>\n", #t);}
#define tokenChar(t)       {LIST; if (Opt_T) printf("<%c>\n", (t));}
#define tokenInteger(t, i) {LIST; if (Opt_T) printf("<%s: %s>\n", #t, (i));}
#define tokenString(s)     {LIST; if (Opt_T) {printf("<string: "); for (int i=1; s[i]!='"'; i++) printf("%c", (s[i])); printf(">\n");}}
// Define your token macros here
//  for example :
//    #define tokenScientific(t, s)   <definition>
//    #define tokenFloat(ts)          <definition>
//    #define <any other macros you needed>
#define tokenKeyword(k)		{LIST; if (Opt_T) printf("<KW%s>\n", (k));}
#define tokenId(id)			{LIST; if (Opt_T) printf("<id: %s>\n", (id));}
#define tokenFloat(f) 		{LIST; if (Opt_T) printf("<float: %s>\n", (f));}
#define tokenScientific(s) 	{LIST; if (Opt_T) printf("<scientific: %s>\n", (s));}



#define MAX_LINE_LENG      256

int Opt_S = 1;
int Opt_T = 1;
int linenum = 1;
char buf[MAX_LINE_LENG];
%}

%Start COMMENT

space		[ \t]+
keyword 	array|begin|boolean|def|do|else|end|false|for|integer|if|of|print|read|real|string|then|to|true|return|var|while
decint		0|([1-9][0-9]*)
float		(0|([1-9][0-9]*))[.][0-9]*[1-9]

%%

<COMMENT>"*/"			{ LIST; BEGIN INITIAL; }
<COMMENT>"\n" 			{
    						LIST;
    						if (Opt_S)
    						printf("%d: %s", linenum, buf);
    						linenum++;
    						buf[0] = '\0'; }
<COMMENT>.       		LIST;

<INITIAL>{space}		LIST;
<INITIAL>"/*"			{ LIST; BEGIN COMMENT; }
<INITIAL>"//&S+".*$		{ LIST; Opt_S = 1; }
<INITIAL>"//&S-".*$		{ LIST; Opt_S = 0; }
<INITIAL>"//&T+".*$		{ LIST; Opt_T = 1; }
<INITIAL>"//&T-".*$		{ LIST; Opt_T = 0; }
<INITIAL>"//".*$		LIST;
<INITIAL>{keyword}		{ tokenKeyword(yytext); }
<INITIAL>","     		{ tokenChar(','); }
<INITIAL>";"     		{ tokenChar(';'); }
<INITIAL>":="     		{ token(:=); }
<INITIAL>":"     		{ tokenChar(':'); }
<INITIAL>"("     		{ tokenChar('('); }
<INITIAL>")"     		{ tokenChar(')'); }
<INITIAL>"["     		{ tokenChar('['); }
<INITIAL>"]"     		{ tokenChar(']'); }
<INITIAL>"+"     		{ tokenChar('+'); }
<INITIAL>"-"     		{ tokenChar('-'); }
<INITIAL>"*"     		{ tokenChar('*'); }
<INITIAL>"/"     		{ tokenChar('/'); }
<INITIAL>"mod"     		{ token(mod); }
<INITIAL>"<"     		{ tokenChar('<'); }
<INITIAL>"<="     		{ token(<=); }
<INITIAL>"<>"     		{ token(<>); }
<INITIAL>">="     		{ token(>=); }
<INITIAL>">"     		{ tokenChar('>'); }
<INITIAL>"="     		{ tokenChar('='); }
<INITIAL>"and"     		{ token(and); }
<INITIAL>"or"     		{ token(or); }
<INITIAL>"not"     		{ token(not); }

<INITIAL>["].*["]								{ tokenString(yytext); }
<INITIAL>[a-zA-Z]([a-zA-Z0-9])* 				{ tokenId(yytext); }
<INITIAL>({decint}|{float})[Ee][+-]?{decint}	{ tokenScientific(yytext); }	
<INITIAL>{float}								{ tokenFloat(yytext); }
<INITIAL>{decint}								{ tokenInteger(integer, yytext); }
<INITIAL>0[0-7]+								{ tokenInteger(oct_integer, yytext); }

<INITIAL>"\n" 			{
    						LIST;
    						if (Opt_S)
    						printf("%d: %s", linenum, buf);
    						linenum++;
    						buf[0] = '\0'; }
<INITIAL>.       		{
    						/* error */
    						printf("Error at line %d: bad character \"%s\"\n", linenum, yytext );
    						exit(-1); }
%%
int main( int argc, char **argv )
{
  if( argc != 2 ) {
    fprintf( stderr, "Usage: ./scanner [filename]\n" );
    exit(0);
  }
	
  FILE *fp = fopen( argv[1], "r" );
  if( fp == NULL ) {
    fprintf( stderr, "Open file error\n" );
    exit(-1);
  }
	
  yyin = fp;

  yylex();

  exit(0);
}
