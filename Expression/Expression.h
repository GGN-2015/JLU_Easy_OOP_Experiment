#pragma once

#include <vector>

class SyntaxWord;

class Expression {
public:
    enum ExpressionType {
        EXP_LABEL = 0,
        EXP_FUNCTION,
        EXP_OPERATION // ��Ԫ�������� 
    };
    Expression(SyntaxWord*, ExpressionType); // ���ø��ڵ����Ϣ 
    void addSon(Expression*);
    SyntaxWord* getSyntaxWord(); // �õ����ڵ��Ӧ������ 
    
    const std::vector<Expression*>&
    getSonList() const; // ��ȡ�������� 
    
    bool isOperator() const; // �Ƿ���˫Ŀ����� 
    int degree() const;      // �������ȼ� 
    
private:
    SyntaxWord* mSyntaxWord;
    ExpressionType mExpressionType;
    std::vector<Expression*> mSonList; // �������� 
};

