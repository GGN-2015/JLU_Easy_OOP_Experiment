#pragma once

class Expression;

class IMatcher { // ����ƥ���� 
public:
    virtual bool check(SyntaxWord**, int length, int posNow);         // ����ܷ�ƥ�� 
    virtual Expression* match(SyntaxWord**, int length, int& posNow); // ����ƥ�� 
};

