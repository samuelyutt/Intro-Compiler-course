Introduction to Compiler Design
Project Assignment 1 Report - Lexical Definition
===
學生：游騰德
學號：0616026

This assignment is to write a scanner for the `P` language in `lex`.

What can my scanner do?
===
Token Defining
--
Tokens are divided into two classes: tokens that will be passed to the parser and tokens that will be discarded by the scanner

### Tokens that will be passed to the parser
My scanner defines the following tokens and passes them to the parser

- Delimiter: `,`, `;`, `:`, `(`, `)`, `[`, `]`
- Operators: `+`, `-`, `*`, `/`, `mod`, `:=`, `<`, `<=`, `<>`, `>=`, `>`, `=`, `and`, `or`, `not`
- Keywords: `array`, `begin`, `boolean`, `def`, `do`, `else`, `end`, `false`, `for`, `integer`, `if`, `of`, `print`, `read`, `real`, `string`, `then`, `to`, `true`, `return`, `var`, `while`
- Identifiers: `[a-zA-Z]([a-zA-Z0-9])*`
- Integer Constants: 
    - Decimal: `0|([1-9][0-9]*)`
    - Octal: `0[0-7]+`
- Floating-Point Constants: `(0|([1-9][0-9]*))[.][0-9]*[1-9]`
- Scientific Notations: `({decint}|{float})[Ee][+-]?{decint}`
- String Constants: `["].*["]`
:::info
`{decint}`: Decimal Integer Constants
`{float}`: Floating-Point Constants
:::

### Tokens that will be discarded by the scanner
My scanner defines the following tokens but will not pass them to the parser

- A sequence of blanks (spaces) tabs: `[ \t]+`
- Newlines: `\n`
- Comments
    - `//`
    - text surrounded by `/*` , and `*/`: Switch between `<COMMENT>` and `<INITIAL>`
- Pseudocomments
    - `"//&S+".*$`: Turn `Opt_S` on
    - `"//&S-".*$`: Turn `Opt_S` off
    - `"//&T+".*$`: Turn `Opt_T` on
    - `"//&T-".*$`: Turn `Opt_T` off

`S`: program listing
`T`: token listing

The effect of options starts from current line of code. By default, both options are on.


Token Listing
--

Macro definitions use specific token as input and return an integer value, a character, a string, etc.

### Default C macro definitions
- `token(t)` is used for all other tokens.
- `tokenChar(t)` is used for tokens that return a character as well as a token.
- `tokenInteger(t, i)` is used for tokens that return an integer value as well as a token (e.g., integer constants)
- `tokenString(s)` is used for tokens that return a string as well as a token.

### My C macro definitions
- `tokenKeyword(k)` is used for tokens that return a string as well as a token.
- `tokenId(id)` is used for tokens that return a string as well as a token.
- `tokenFloat(f)` is used for tokens that return a string as well as a token.
- `tokenScientific(s)` is used for tokens that return a string as well as a token.

Result
==
```clike=
[yutt026@linux1 src]$ make test
flex lex.l
gcc  lex.yy.c -o scanner -lfl
./test/test.sh scanner
Running test case: case1  ==>  Pass!
Running test case: case2  ==>  Pass!
Running test case: case3  ==>  Pass!
Running test case: case4  ==>  Pass!
Running test case: case5  ==>  Pass!
Running test case: case6  ==>  Pass!
Running test case: error  ==>  Pass!
```
###### tags: `NCTU` `Compiler` `project1` `Lexical Definition`