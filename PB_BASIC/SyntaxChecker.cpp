#include <iostream>
#include <typeinfo>

#include "BraceSyntax.h"
#include "CommaSyntax.h"
#include "CommentSyntax.h"
#include "EmptySyntax.h"
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

int SyntaxChecker::syntaxCheck(std::string sline, SyntaxWordList& syntaxList) const {
    syntaxList.clear();     // 清空一个 vector 
    StringStream ss(sline); // 构造一个字符流 
    
    while(!ss.empty()) {
        bool fail = true;
        for(auto ptr: mAllSyntax) {
            if(ptr -> check(ss)) { // 成功匹配了一种语法 
                fail = false;
                
                std::string stmp = ptr -> match(ss);
                if(ptr -> vital()) { // 如果不重要，就不要加入序列中去 
                    syntaxList.push_back(SyntaxWord(stmp, ptr));
                }
                break;
            }
        }
        if(fail) {
            return ss.position(); // 在 ss.position 位置匹配失败 
        }
    }
    return -1; // 成功完成了词法分析 
}

