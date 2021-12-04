#ifndef IGRAMMAR_H
#define IGRAMMAR_H

#include "SyntaxChecker.h"

class IGrammar { // 抽象类 
public:
    virtual bool check(const SyntaxWordList&) = 0;   // 检测是否符合语法规范 
    virtual void operate(const SyntaxWordList&) = 0; // 执行对应的语句内容 
};

#endif

