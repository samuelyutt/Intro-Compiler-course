Introduction to Compiler Design
Project Assignment 4 - Semantic Definitions
===
學生：游騰德
學號：0616026

This assignment is to perform semantic analyses for a `P` program. In the previous project, you have constructed an abstract syntax tree (AST). This assignment requires to do some simple checking of semantic correctness. Code generation will be performed in the last phase of the project.
**Note: I used visitor pattern in ths assignment**

Changes I made
===
Makefile
--
- Add path `src/semantic/` to source
    ```clike=
    SEMANTICDIR = src/semantic/
    SEMANTIC := $(shell find $(SEMANTICDIR) -name '*.cpp')

    SRC := $(AST) \
           $(VISITOR) \
           $(SEMANTIC)
    ```

scanner.l
--
- Add `OptDmp` and modified Pseudocomment section
    ```clike=
        /* Pseudocomment */
    "//&"[STD][+-].* {
        LIST;
        char option = yytext[3];
        switch (option) {
        case 'S':
            OptSrc = (yytext[4] == '+') ? 1 : 0;
            break;
        case 'T':
            OptTok = (yytext[4] == '+') ? 1 : 0;
            break;
        case 'D':
            OptDmp = (yytext[4] == '+') ? 1 : 0;
            break;
        }
    }
    ```

parser.y
--
- Visit each node of the AST via semanticAnalyzer
    ```cpp=
    semanticAnalyzer(AST);
    ```
- Modify outputs when no semantic error
    ```cpp=
    if (!semErr)
        printf("\n"
            "|---------------------------------------------|\n"
            "|  There is no syntactic and semantic error!  |\n"
            "|---------------------------------------------|\n");
    ```

- Add `symboltable.hpp` and modify `SematicAnalyzer.cpp`

Abilities of my Sematic Analyzer
===
- Push symbols into symbol table in the following nodes
    1. ProgramNode
    2. DeclarationNode
    3. VariableNode
    4. ForNode
    5. FunctionNode

- Dump the symbol table if required
    ```cpp=
    void dumpSymbolTable() {
        if (OptDmp) {
            SymbolTable tmpTable = curManager->tables.top();
            dumpDemarcation('=');
            printf("%-33s%-11s%-11s%-17s%-11s\n", "Name", "Kind", "Level", "Type", "Attribute");
            dumpDemarcation('-');
            for (uint i=0; i< tmpTable.entries.size(); i++) {
                printf("%-33s", tmpTable.entries[i].name.c_str());
                printf("%-11s", tmpTable.entries[i].kind.c_str());
                printf("%d%-10s", tmpTable.entries[i].level, tmpTable.entries[i].level==0?"(global)":"(local)");
                printf("%-17s", tmpTable.entries[i].type.c_str());
                printf("%-11s", tmpTable.entries[i].attribute.c_str());
                puts("");
            }
            dumpDemarcation('-');
        }
    }
    ```

- Check for sematic error in the following nodes
    1. ProgramNode 
    2. DeclarationNode 
    3. VariableNode 
    4. ConstantValueNode 
    5. FunctionNode 
    6. AssignmentNode 
    7. PrintNode 
    8. ReadNode 
    9. VariableReferenceNode 
    10. BinaryOperatorNode 
    11. UnaryOperatorNode 
    12. IfNode 
    13. WhileNode 
    14. ForNode 
    15. ReturnNode 
    16. FunctionCallNode

- Dump the sematic error to standard error
    ```cpp=
    void dumpErr(int line, int col, int errnum, string param1, string param2, string param3) {
        fprintf(stderr, "<Error> Found in line %d, column %d: ", line, col);
        switch (errnum) {
            case 0: fprintf(stderr, "symbol '%s' is redeclared\n", param1.substr(0, 32).c_str());break;
            case 1: fprintf(stderr, "program name must be the same as filename\n");break;
            case 2: fprintf(stderr, "identifier at the end of program must be the same as identifier at the beginning of program\n");break;
            case 3: fprintf(stderr, "identifier at the end of function must be the same as identifier at the beginning of function\n");break;
            case 4: fprintf(stderr, "'%s' declared as an array with a lower bound greater or equal to upper bound\n", param1.c_str());break;
            case 5: fprintf(stderr, "use of undeclared identifier '%s'\n", param1.c_str());break;
            case 6: fprintf(stderr, "index of array reference must be an integer\n");break;
            case 7: fprintf(stderr, "there is an over array subscript\n");break;
            case 8: fprintf(stderr, "invalid operands to binary operation '%s' ('%s' and '%s')\n", param1.c_str(), param2.c_str(), param3.c_str());break;
            case 9: fprintf(stderr, "invalid operand to unary operation '%s' ('%s')\n", param1.c_str(), param2.c_str());break;
            case 10: fprintf(stderr, "program/procedure should not return a value\n");break;
            case 11: fprintf(stderr, "return '%s' from a function with return type '%s'\n", param1.c_str(), param2.c_str());break;
            case 12: fprintf(stderr, "cannot assign to variable '%s' which is a constant\n", param1.c_str());break;
            case 13: fprintf(stderr, "the value of loop variable cannot be modified inside the loop\n");break;
            case 14: fprintf(stderr, "array assignment is not allowed\n");break;
            case 15: fprintf(stderr, "assigning to '%s' from incompatible type '%s'\n", param1.c_str(), param2.c_str());break;
            case 16: fprintf(stderr, "variable reference of print statement must be scalar type\n");break;
            case 17: fprintf(stderr, "variable reference of read statement cannot be a constant variable reference\n");break;
            case 18: fprintf(stderr, "the value of loop variable cannot be modified inside the loop\n");break;
            case 19: fprintf(stderr, "variable reference of read statement must be scalar type\n");break;
            case 20: fprintf(stderr, "the expression of condition must be boolean type\n");break;
            case 21: fprintf(stderr, "the lower bound of iteration count must be smaller than or equal to the upper bound\n");break;
            case 22: fprintf(stderr, "used of undeclared function '%s'\n", param1.c_str());break;
            case 23: fprintf(stderr, "too few/much arguments to function invocation\n");break;
            case 24: fprintf(stderr, "incompatible types passing '%s' to parameter of type '%s'\n", param1.c_str(), param2.c_str());break;

        }
    }
    ```


Result
===
```clike=
[yutt026@linux2 test]$ python3 test.py
Running test case: basic  ==>  Pass!
Running test case: error  ==>  Pass!
Running test case: test  ==>  Pass!
Running test case: Assignment  ==>  Pass!
Running test case: BinaryOperator  ==>  Pass!
Running test case: condition  ==>  Pass!
Running test case: ForLoop  ==>  Pass!
Running test case: function  ==>  Pass!
Running test case: PrintStatement  ==>  Pass!
Running test case: program  ==>  Pass!
Running test case: ReadStatement  ==>  Pass!
Running test case: ret  ==>  Pass!
Running test case: UnaryOperator  ==>  Pass!
Running test case: variable  ==>  Pass!
Running test case: VariableReference  ==>  Pass!
```

###### tags: `NCTU` `Compiler` `project4` `Semantic Definitions`