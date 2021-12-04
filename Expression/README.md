# 构建表达式分析树 Expression

给出一个表达式，这个表达式中可能有双目运算符，可能有函数调用，最终要求得到一个表达式树。

给出一种递归处理的思路，先将所有括号和函数调用进行抽象，成为抽象符号，然后再对新的序列使用栈进行中缀表达式构建表达式树。

```
f ( x , y ) + ( 3 - 5 * 2 ) * g ( p , q )

抽象：
[A1] + [A2] * [A3]

其中：
[A1] : f ( x , y )
[A2] : ( 3 - 5 * 2 )
[A3] : g ( p , q )
```



# 可能会用到的接口

## Expression 表达式树

```cpp
class Expression {
public:
    Expression(std::string name); // 记录函数名，或运算名
    void addSonNode(Expression*); // 为表达式树添加儿子节点
    void show() const;            // 用于调试时显示表达式树
    
    const std::vector<Expression*>& getSonList(); // 获得所有子树的根信息
};
```



## ExpressionErrorMgr 错误管理器

```cpp
class ExpressionErrorMgr { // 表达式错误管理器
public:
    static ExpressionErrorMgr& getInstance(); // 静态单例
    
    void appendError(std::string who, int where, std::string why); // 新增一个错误
    bool checkErrorExist() const;                                  // 检测当前错误序列中是否有错误
    void clearError();                                             // 清空错误信息列表

private:
    ExpressionErrorMgr(); // 初始化一个空的错误管理器
    // 同时要禁止拷贝和构造
};
```



## IMatcher 抽象匹配器

```cpp
class TokenStream;
class IMatcher { // 匹配器
public:
    bool matchPre(TokenStream&); // 试图根据符号流的前几个字符推断是否符合当前匹配器的匹配方式
    Expression* process();       // 如果 matchPre 已经返回了 true，那么就可以进行匹配并且返回一个 Expression 树
    // 如果在匹配过程中发生了错误，那么我们认为输入的表达式是不合法的，返回 nullptr 并将错误信息传给 ErrorMgr
};

// 抽象匹配器将要派生出四种匹配器
//   I. 函数调用匹配器，匹配 'IDENT', '('
//  II. 括号匹配器，匹配 '('
// III. 单值匹配器，匹配 'IDENT', not '('
//  IV. 双目算符匹配器，匹配 '+', '-', '*', '/', '%'
// 如果所有匹配器都不能匹配，则报错
```



## ExpressionMatcher 整体匹配器

```cpp
class TokenStream;
class ExpressionMatcher {
public:
    static ExpressionMatcher& getInstance(); // 静态单例
    Expression* match(TokenStream&); // 将 TokenStream 中的全部信息匹配出一个表达式
    
    // 核心算法都在 match 函数中实现，先递归处理得到 vetror<Expression*>
    // 再对这个 vector 中的元素 使用 栈 处理得到一个完整的 Expression 树
};
```



## TokenStream 符号流管理

```cpp
class TokenStream { // Token 流，用于管理一个 Token 序列
public:
    TokenStream(const std::vector<std::string>&); // 使用 vector<string> 传入一个符号序列
    
    bool isEmpty() const;         // 检测 Token 流是否已经为空
    std::string getFront() const; // 获取当前 Token 流中的第一个 Token，如果已经没有符号，返回空串
    int getPosition() const;      // 获取当前 Token 流的首指针位置
    int getRestCount() const;     // 返回当前 Token 流还能读出几个字符
};
```

