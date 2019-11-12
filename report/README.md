Introduction to Compiler Design
Project Assignment 2 - Syntactic Definitions
===
學生：游騰德
學號：0616026

This assignment is to write an **LALR(1)** parser for the `P` language by writing the grammar and creating a parser using `yacc`.

Changes I made to my scanner
===
Include
--
Add `#include "y.tab.h"`

Return Token
--
**Return each token to the parser.**
The tokens are listed as the following:
`ID` `INT` `OCTINT` `FLOAT` `SCI` `STR` `','` `';'` `':'` `'('` `')'` `'['` `']'` `'+'` `'-'` `'*'` `'/'` `MOD` `ASSIGN` `'<'` `LE` `NE` `GE` `'>'` `'='` `AND` `OR` `NOT` `ARRAY` `BGN` `BOOLEAN` `DEF` `DO` `ELSE` `END` `FALSE` `FOR` `INTEGER` `IF` `OF` `PRINT` `READ` `REAL` `STRING` `THEN` `TO` `TRUE` `RETURN` `VAR` `WHILE`


What can my parser do?
===

Syntactic Definitions
--

### Program Units
#### 1. Program
```c=
program         : ID ';' dec_vars_consts_ functions_ compound_stmt END ID;
```

#### 2. Function
```c=
function        : ID '(' formal_args_ ')' ':' scalar_type ';' compound_stmt END ID
                | ID '(' formal_args_ ')' ';' compound_stmt END ID;
```
### Data Types and Declaration
#### 1. Variable
```c=
dec_var         : VAR idlist ':' type ';';
type            : scalar_type | arr_type;
scalar_type     : INTEGER | REAL | STRING | BOOLEAN;
arr_type        : ARRAY INT TO INT OF type;
```

#### 2. Constant
```c=
dec_varconst    : VAR idlist ':' literal_const ';';
literal_const   : const | STR | TRUE | FALSE;
```

### Statements
#### 1. Compound
```c=
compound_stmt   : BGN dec_vars_consts_ stmts_ END;
```

#### 2. Simple
```c=
stmt            : PRINT expr ';'
                | READ var_ref ';'
                | compound_stmt
                | condition
                | whileloop
                | forloop
                | var_ref ASSIGN expr ';'
                | procedure ';'
                | rtrn ';';
```

#### 3. Expression
```c=
expr            : '(' expr ')'
                | expr operator expr
                | item;
item            : var_ref | procedure | literal_const;
operator        : add | sub | mul | div | rel | log;
neg             : '-';
add             : '+';
sub             : '-';
mul             : '*';
div             : '/' | MOD;
rel             : '<' | LE | NE | GE | '>' | '=';
log             : AND | OR | NOT;
```

#### 4. Conditional
```c=
condition       : IF expr THEN stmts_ ELSE stmts_ END IF
                | IF expr THEN stmts_ END IF;
```

#### 5. While
```c=
whileloop       : WHILE expr DO stmts_ END DO;
```

#### 6. For
```c=
forloop         : FOR ID ASSIGN int_const TO int_const DO stmts_ END DO;
int_const       : pos_int | neg_int;
pos_int         : INT | OCTINT;
neg_int         : neg pos_int;
```

#### 7. Return
```c=
rtrn            : RETURN expr;
```

#### 8. Function invocation
```c=
procedure       : ID '(' exprcs_ ')';
```

Listing Information
--
The parser lists information according to `Opt_S` and `Opt_T` options.
If the input file is syntactically correct, print
```=
|--------------------------------|
|  There is no syntactic error!  |
|--------------------------------|
```
Once the parser encounters a syntactic error, print an error message in the form of
```=
|--------------------------------------------------------------------------
| Error found in Line #[ line number where the error occurs ]: [ source code of that line ]
|
| Unmatched token: [ the token that is not recognized ] 
|-------------------------------------------------------------------------- 
```


Result
===
```clike=
[yutt026@linux1 test]$ python3 test.py
Running test case: 1_decl  ==>  Pass!
Running test case: 2_expr  ==>  Pass!
Running test case: 3_statement  ==>  Pass!
Running test case: 4_general_1  ==>  Pass!
Running test case: 5_general_2  ==>  Pass!
Running test case: 6_err_1  ==>  Pass!
Running test case: 7_err_2  ==>  Pass!
Running test case: 8_err_3  ==>  Pass!
Running test case: 9_err_4  ==>  Pass!
Running test case: 10_err_5  ==>  Pass!
```
###### tags: `NCTU` `Compiler` `project2` `Syntactic Definitions`
