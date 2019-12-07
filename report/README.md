Introduction to Compiler Design
Project Assignment 3 - Constructing Abstract Syntax Trees
===
學生：游騰德
學號：0616026

This assignment is to extend the parser to construct an abstract syntax tree (AST) for a given program written in `P` language and to serialize this AST into the designated format.
**Note: I used visitor pattern in ths assignment**

Changes I made
===
scanner.l
--
Add `yylval.str=strdup(yytext);` to each token.

parser.y
--
- Include all `.hpp` files
- Define types for each token
- Create each node when parsing
- Construct an AST
- Accept the root after the AST is constructed
- Calculate how many `tab`s are required when printing

Abilities of my AST
===
- My AST contains following nodes
    1. ProgramNode
        ```cpp=
        string name;
        ProgramBodyNode* programBodyNode;
        ```
    2. DeclarationNode
        ```cpp=
        string name;
        vector<VariableNode*> v_variableNode;
        ```
    3. ConstantValueNode
        ```cpp=
        string constant_value;
        string type;
        ```
    4. VariableNode
        ```cpp=
        string name;
        string type;
        ConstantValueNode* constantValueNode;
        ArrTypeNode* arrTypeNode;
        ```
    5. ProgramBodyNode
        ```cpp=
        vector<DeclarationNode*> v_declarationNode;
        vector<FunctionNode*> v_functionNode;
        CompoundStmtNode* compoundStmtNode;
        ```
    6. ExpressionNode
    7. VariableReferenceNode
        ```cpp=
        string name;
        vector<ExpressionNode*> v_expressionNode;
        ```
    8. BinaryOperatorNode
        ```cpp=
        string op;
        ExpressionNode* leftOperand;
        ExpressionNode* rightOperand;
        ```
    9. UnaryOperatorNode
        ```cpp=
        string op;
        ExpressionNode* operand;
        ```
    10. FunctionCallExprNode
        ```cpp=
        string name;
        vector<ExpressionNode*> v_expressionNode;
        ```
    12. CompoundStmtNode
        ```cpp=
        string name;
        vector<DeclarationNode*> v_declarationNode;
        vector<StatementNode*> v_statementNode;
        ```
    13. ArrTypeNode
        ```cpp=
        string type;
        vector<ArrDeclarationNode*> v_arrdeclarationNode;
        ```
    14. ArrDeclarationNode
        ```cpp=
        string bgn;
        string end;
        ```
    15. AssignmentNode
        ```cpp=
        VariableReferenceNode* lvalue;
        ExpressionNode* expression;
        ```
    16. PrintNode
        ```cpp=
        ExpressionNode* target;
        ```
    17. ReadNode
        ```cpp=
        ExpressionNode* target;
        ```
    18. ReturnNode
        ```cpp=
        ExpressionNode* return_value;
        ```
    19. WhileNode
        ```cpp=
        ExpressionNode* condition;
        vector<StatementNode*> body;
        ```
    20. IfNode
        ```cpp=
        ExpressionNode* condition;
        vector<StatementNode*> body;
        vector<StatementNode*> body_of_else;
        ```
    21. ForNode
        ```cpp=
        DeclarationNode* loop_var_decl;
        AssignmentNode* init_assignment;
        ExpressionNode* condition;
        vector<StatementNode*> body;
        ```
    22. FunctionNode
        ```cpp=
        string name;
        vector<DeclarationNode*> parameters;
        string return_type;
        CompoundStmtNode* body;
        string end_name;
        ```
    23. FunctionInvokationNode
        ```cpp=
        string name;
        vector<ExpressionNode*> v_expressionNode;
        ```

- When a node is visited, the node printed its own required format and accept all of its child.


Result
===
```clike=
[yutt026@linux2 test]$ python3 test.py
Running test case: program  ==>  Pass!
Running test case: function  ==>  Pass!
Running test case: declaration  ==>  Pass!
Running test case: variable  ==>  Pass!
Running test case: ConstantValue  ==>  Pass!
Running test case: simple  ==>  Pass!
Running test case: expression  ==>  Pass!
Running test case: control  ==>  Pass!
Running test case: invocation  ==>  Pass!
```

###### tags: `NCTU` `Compiler` `project3` `Constructing Abstract Syntax Trees`