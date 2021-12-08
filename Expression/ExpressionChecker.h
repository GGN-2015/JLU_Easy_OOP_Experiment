#pragma once

#include <vector>

class Expression; // ��¼���ʽ�� 
class SyntaxWord; // �ʷ���Ԫ 
class IMatcher;   // ����ƥ���� 

class ExpressionChecker { // ���ʽ�������� 
public:
    static ExpressionChecker& getInstance(); // ��ȡ���� 
    static void release();                   // �ͷ��ڴ�ռ� 
    
    void addIMatcher(IMatcher*); // ����һ��ƥ���� 
    Expression* build(SyntaxWord** syntaxWordArray, int length, int& posNow); 
    
private:
    std::vector<IMatcher*> mMatchers; // ����ƥ���� 
    static ExpressionChecker* spChecker;     // ָ�뵥�� 
    
    ExpressionChecker() {}
    ~ExpressionChecker() {}
    ExpressionChecker(const ExpressionChecker&) = delete;
    ExpressionChecker& operator= (const ExpressionChecker&) = delete;
};

