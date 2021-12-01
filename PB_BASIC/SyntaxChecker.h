#ifndef SYNTAXCHECKER_H
#define SYNTAXCHECKER_H

#include <vector>
#include "ISyntax.h"

typedef std::pair<std::string, ISyntax*> SyntaxWord; // 一个词法模块 
typedef std::vector<SyntaxWord> SyntaxWordList; // 一个词法模块序列 

class SyntaxChecker { // 语法检查器 
public:
    SyntaxChecker();
    ~SyntaxChecker();
    
    int syntaxCheck(std::string sline, SyntaxWordList& syntaxList) const;
    // 返回值返回 -1 表示分析成功, 返回 >= 0 的值表示在该位置无法匹配 
    
private:
    std::vector<ISyntax*> mAllSyntax; // 记录所有可能出现的语法 
};

#endif

