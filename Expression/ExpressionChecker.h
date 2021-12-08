#pragma once

#include <vector>

class Expression; // 记录表达式树 
class SyntaxWord; // 词法单元 
class IMatcher;   // 抽象匹配器 

class ExpressionChecker { // 表达式树生成器 
public:
    static ExpressionChecker& getInstance(); // 获取单例 
    static void release();                   // 释放内存空间 
    
    void addIMatcher(IMatcher*); // 新增一个匹配器 
    Expression* build(SyntaxWord** syntaxWordArray, int length, int& posNow); 
    
private:
    std::vector<IMatcher*> mMatchers; // 所有匹配器 
    static ExpressionChecker* spChecker;     // 指针单例 
    
    ExpressionChecker() {}
    ~ExpressionChecker() {}
    ExpressionChecker(const ExpressionChecker&) = delete;
    ExpressionChecker& operator= (const ExpressionChecker&) = delete;
};

