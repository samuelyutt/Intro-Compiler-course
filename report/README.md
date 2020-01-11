Introduction to Compiler Design
Project Assignment 5 - Code Generation
===
學生：游騰德
學號：0616026

This assignment is to generate `RISC-V` instructions for the `P` language based on the `AST` and `symbol table` that have been built in the previous assignments. The generated code will then be executed on a RISC-V simulator, called `Spike`.

Changes I made
===
Makefile
--
- Add path `src/gen/` to source
    ```clike=
    GENDIR = src/gen/
    GEN := $(shell find $(GENDIR) -name '*.cpp')

    SRC := $(AST) \
           $(VISITOR) \
           $(GEN)
    ```
codegen.cpp
--
- Generate `RISC-V` instructions
    ```c=
    void gen_program_start(string program_name);
    void gen_main_start();
    void gen_main_end();
    void gen_global_decl(string name);
    void gen_global_decl_const(string name, int value);
    void gen_load_int(int value);
    void gen_assign(string name);
    void gen_local_decl(string name, int value);
    void gen_binary(int op);
    void gen_unary(int op);
    void gen_load_word(string name);
    void gen_store_word(string name);
    void gen_func_start(string name);
    void gen_func_end(string name);
    void gen_param_decl(string name);
    void gen_return();
    void gen_func_args(int count);
    void gen_func_call(string name);
    void gen_print(string name);
    void gen_read(string name);
    void gen_label(int label_num);
    void gen_condition(int cdn_type, int label_num, int op);
    void gen_jump(int label_num);
    void gen_for_idx_add(string name);
    ```


Result
===
```clike=
[yutt026@linux2 test]$ python3 test.py

|---------------------------------------------|
|  There is no syntactic and semantic error!  |
|---------------------------------------------|
Running test case: variableConstant  ==>  Pass!

|---------------------------------------------|
|  There is no syntactic and semantic error!  |
|---------------------------------------------|
Running test case: expression  ==>  Pass!

|---------------------------------------------|
|  There is no syntactic and semantic error!  |
|---------------------------------------------|
Running test case: function  ==>  Pass!

|---------------------------------------------|
|  There is no syntactic and semantic error!  |
|---------------------------------------------|
Running test case: specExample  ==>  Pass!

|---------------------------------------------|
|  There is no syntactic and semantic error!  |
|---------------------------------------------|
Running test case: condition  ==>  Pass!

|---------------------------------------------|
|  There is no syntactic and semantic error!  |
|---------------------------------------------|
Running test case: loop  ==>  Pass!
```
Assignment 5 Feedback
===
1. 首先很感謝助教spec寫得很多很詳細，基本上需要用到的重點都已經包含在spec中了！！
3. 但是這份作業還是很難，花了將近三天的時間，原本以為很簡單的說:(
4. 其實主要是難在不知道從何下手，因為上一次的作業並不是全對，所以我不敢用我自己的上一份作業來當initial，只好用助教給的`.cpp`範例，但是代價就是要先看懂別人寫的code，再來想辦法找出下手的地方
5. 其實我這次作業是在`SemanticAnalyzer.cpp`中去呼叫`gencode.cpp`中的函式來generate code，我相信這不是正規的作法，**但是基於我沒有時間去完全看懂別人的`.cpp`是怎麼traverse整棵樹的，因此也很難靠自己寫出可以完整traverse AST的`codegen.cpp`**
6. 看不懂別人的`.cpp`的最大原因是因為他的AST寫得實在是太高級啦！！我的資結沒學好qq我很抱歉，資結太爛來寫這個作業真的母湯，不過我有努力儘量看懂><
7. 寫完作業看到test case all pass的時候還是那麼的感動，雖然可能還是有很多bug，而且code optimization的部分是完全沒有（其實產生的很多assembly是可以不用的），但我覺得對於code generate的部分我還是有很大收穫的！！:)
8. 投票是一定要的啦！謝謝助教～

Feedback for the whole semester
===
1. Compiler的每個作業真的都很有挑戰性
2. 真的看得出來助教們都很認真的在幫助我們，例如spec的詳細程度、課堂上作業的講解、錄製影片教學、github上對於每個問題的回答等等，助教讚讚！！
3. 基本上每個作業對應到一個compiler的環節（lexical analysis -> syntactic analysis -> ast -> sematic analysis -> code generate），跟課堂上老師講解相呼應，很不錯！
4. 我個人每次寫作業的流程（基本上從作業三開始都是這樣）
    1. 看懂別人的code（1～2天）
    2. 找到從何下手（2～3天）
    3. 開始寫 + debug（2～3天）
    4. 寫Report（20～30分鐘）
5. 一個作業真的都要一星期跑不掉，真的是 #撕心裂肺虐我的肝！！！！！
6. 個人認為，spec已經很好了（是我自己太廢），但如果可以增加一部分，用來說明作業應該**從何下手**，例如怎麼建置第一個ast的node，怎麼印出第一行sematic錯誤訊息等等，對我們的幫助應該會很大
7. 還有一點就是，有時候作業給我們發會的空間有點大（可以這樣寫也可以那樣寫，像是visitor pattern可以用也可以不用），雖然原本目的可能是想增加彈性，但是有時候覺得這樣會讓我變得真的完全不知道從何下手，也不知道挑哪個方法相對的代價是什麼
8. 最後還是再一次深深感謝助教跟老師的用心，然後我終於寫完了><



###### tags: `NCTU` `Compiler` `project5` `Code Generation`