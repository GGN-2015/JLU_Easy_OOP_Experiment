#ifndef IGRAMMAR_H
#define IGRAMMAR_H

#include "SyntaxChecker.h"

class IGrammar { // ������ 
public:
    virtual bool check(const SyntaxWordList&) = 0;   // ����Ƿ�����﷨�淶 
    virtual void operate(const SyntaxWordList&) = 0; // ִ�ж�Ӧ��������� 
};

#endif

