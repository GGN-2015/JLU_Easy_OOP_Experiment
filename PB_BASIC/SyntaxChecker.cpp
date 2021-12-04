#include <iostream>
#include <typeinfo>

#include "BraceSyntax.h"
#include "CommaSyntax.h"
#include "CommentSyntax.h"
#include "EmptySyntax.h"
#include "ErrorMgr.h"
#include "NameSyntax.h"
#include "NumicSyntax.h"
#include "OperatorSyntax.h"
#include "QuoteSyntax.h"

#include "StringStream.h"
#include "SyntaxChecker.h"

SyntaxChecker::SyntaxChecker() {
    mAllSyntax.push_back(CommentSyntax    ::getInstance()); // 注释一定要比运算符优先级高 
    mAllSyntax.push_back(QuoteSyntax      ::getInstance()); // 双引号引用 
    mAllSyntax.push_back(LeftBraceSyntax  ::getInstance()); // 左括号 
    mAllSyntax.push_back(RightBraceSyntax ::getInstance()); // 右括号 
    mAllSyntax.push_back(CommaSyntax      ::getInstance()); // 逗号 
    mAllSyntax.push_back(EmptySyntax      ::getInstance()); // 空白字符 
    mAllSyntax.push_back(NameSyntax       ::getInstance()); // 关键字 或 名字 
    mAllSyntax.push_back(NumicSyntax      ::getInstance()); // 数值 
    mAllSyntax.push_back(OperatorSyntax   ::getInstance()); // 双目运算符 
}

SyntaxChecker::~SyntaxChecker() {
    // 析构时不用释放空间 
}

int SyntaxChecker::syntaxCheck(std::string sline, SyntaxWordList& syntaxList, int lineId) const {
    syntaxList.clear();     // 清空一个 vector 
    StringStream ss(sline); // 构造一个字符流 
    
    while(!ss.empty()) {
        bool fail = true;
        for(auto ptr: mAllSyntax) {
            if(ptr -> check(ss)) { // 成功匹配了一种语法 
                fail = false;
                int colId = ss.position(); // 记录匹配位置的列号 
                
                std::string stmp = ptr -> match(ss);
                if(ptr -> vital()) { // 如果不重要，就不要加入序列中去 
                    syntaxList.push_back({lineId, colId, stmp, ptr -> getSyntaxName()});
                }
                break;
            }
        }
        if(fail) {
            char stmp[15]; sprintf(stmp, "%d", ss.position());
            ErrorMgr::getInstance().push(__FILE__, __LINE__, "在 " + std::string(stmp) + " 列无法进行词法分析"); 
            return ss.position(); // 在 ss.position 位置匹配失败 
        }
    }
    return -1; // 成功完成了词法分析 
}


void SyntaxChecker::inputAndCheckSyntax(SyntaxWordLineList& swll) const {
    int rowCnt = 0;
    swll.clear();
    while(!std::cin.eof()) { // 如果还可以输入的话 
        std::string line;
        std::getline(std::cin, line); // 从标准输入流输入一行内容 
        SyntaxWordList slist {};
        syntaxCheck(line, slist, rowCnt); // 进行语法检查 
        if(!ErrorMgr::getInstance().checkEmpty()) {
            ErrorMgr::getInstance().show(rowCnt); // 显示错误信息 
            ErrorMgr::getInstance().clear();
            system("pause"); exit(0); // 程序出错则停止词法分析 
        }
        rowCnt ++;
        if(!slist.empty()) {
            swll.push_back(slist); // 保证每一行都至少有一个符号，空行会被忽略 
        }
    }
}

SyntaxChecker& SyntaxChecker::getInstance() {
    static SyntaxChecker sc;
    return sc;
}
