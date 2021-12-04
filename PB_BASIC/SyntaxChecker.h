#ifndef SYNTAXCHECKER_H
#define SYNTAXCHECKER_H

#include <algorithm>
#include <tuple>
#include <vector>
#include "ISyntax.h"

// 行号, 列号, 原数据, 类型名 
struct SyntaxWord { // 一个词法模块 
    int lineId;
    int columnId;
    std::string rawString;
    std::string typeName;
};

typedef std::vector<SyntaxWord> SyntaxWordList; // 一个词法模块序列 
typedef std::vector<SyntaxWordList> SyntaxWordLineList; // 每个元素都是一行程序 

class SyntaxChecker { // 语法检查器 
public:
    static SyntaxChecker& getInstance(); // 静态单例 
    ~SyntaxChecker();
    
    int syntaxCheck(std::string sline, SyntaxWordList& syntaxList, int lineId) const;
    // 返回值返回 -1 表示分析成功, 返回 >= 0 的值表示在该位置无法匹配 
    
    void inputAndCheckSyntax(SyntaxWordLineList&) const;
    // 输入整个程序并进行语法检查 
    
private:
    SyntaxChecker();
    std::vector<ISyntax*> mAllSyntax; // 记录所有可能出现的语法 
};

#endif

