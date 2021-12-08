#pragma once

#include <vector>

class SyntaxWord;

class Expression {
public:
    enum ExpressionType {
        EXP_LABEL = 0,
        EXP_FUNCTION,
        EXP_OPERATION // 二元代数运算 
    };
    Expression(SyntaxWord*, ExpressionType); // 设置根节点的信息 
    void addSon(Expression*);
    SyntaxWord* getSyntaxWord(); // 得到根节点对应的数据 
    
    const std::vector<Expression*>&
    getSonList() const; // 获取儿子序列 
    
    bool isOperator() const; // 是否是双目运算符 
    int degree() const;      // 运算优先级 
    
private:
    SyntaxWord* mSyntaxWord;
    ExpressionType mExpressionType;
    std::vector<Expression*> mSonList; // 儿子序列 
};

