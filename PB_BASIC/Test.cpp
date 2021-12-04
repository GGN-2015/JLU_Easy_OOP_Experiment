#include <iomanip>
#include <iostream>

#include "CommentSyntax.h"
#include "ErrorMgr.h"
#include "MemberMap.h"
#include "NameSyntax.h"
#include "NumicSyntax.h"
#include "OperatorSyntax.h"
#include "StringStream.h"
#include "SyntaxChecker.h"
#include "TypeMgr.h"
#include "VarType.h"
#include "Test.h"

void Test::testVarType() {
    MemberMap memberMap;
    
    memberMap.addMemberMessage("chi", VarType({"VAR"}));
    memberMap.addMemberMessage("eng", VarType({"VAR"}));
    memberMap.addMemberMessage("mat", VarType({"VAR"}));
    
    TypeMgr::getInstance().createNewType("Student", memberMap);
    VarType vt1({"PTR", "PTR", "VAR"});
    VarType::isType({"PTR", "PTR", "TYPE", "Student", "ARM"}); // 试一些类型 
    
    ErrorMgr::getInstance().show(1);
}

void Test::testSyntaxChecker(bool output) {
    int rowCnt = 0;
    while(true) {
        SyntaxChecker& sc = SyntaxChecker::getInstance();
        
        std::string line;
        std::getline(std::cin, line); // 从标准输入流输入一行内容 
        
        SyntaxWordList slist {};
        sc.syntaxCheck(line, slist, rowCnt);
        
        if(output) { // 将分析结果输出到屏幕 
            Test::outputSyntaxWordList(slist);
        }
        
        if(!ErrorMgr::getInstance().checkEmpty()) {
            ErrorMgr::getInstance().show(rowCnt); // 显示错误信息 
            ErrorMgr::getInstance().clear();
            
            system("pause"); // 程序出错则停止词法分析 
            exit(0);
        }
        
        rowCnt ++;
    }
}

void Test::outputSyntaxWordList(const SyntaxWordList& slist) { // 输出文法符号序列 
    int maxlen = 0;
    for(auto pr: slist) {
        maxlen = std::max(maxlen, (int)pr.rawString.length());
    }
    for(auto pr: slist) {
        std::cout << "[" << std::setw(maxlen) << pr.rawString << "]: " << pr.typeName << std::endl;
    }
    std::cout << std::endl;
}

void Test::testOperatorSyntax() {
    OperatorSyntax os;
    StringStream ss("1 = 3");
    if(os.check(ss)) {
        std::cout << os.match(ss) << std::endl;
    }else {
        std::cout << "[Not Match]" << std::endl;
    }
}

void Test::testCommentSyntax() {
    CommentSyntax cs;
    StringStream ss("// hello world!");
    if(cs.check(ss)) {
        std::string prefix = cs.match(ss);
        std::cout << prefix << std::endl;
    }else {
        std::cout << "[Not Match]" << std::endl;
    }
}

void Test::testStringStream() { // StringStream 的测试代码 
    StringStream ss("hello world!");
    while(!ss.empty()) {
        std::cout << (int)ss.front() << " : {" << ss.front() << "}" << std::endl;
        ss.popFront();
    }
}

void Test::testNumicSyntax() { // 数值识别 
    NumicSyntax numicSyntax;
    StringStream ss("0x7fffffff-0x6fffff");
    if(numicSyntax.check(ss)) {
        std::string prefix = numicSyntax.match(ss);
        std::cout << prefix << std::endl;
    }else {
        std::cout << "[Not Match]" << std::endl;
    }
}

void Test::testNameSyntax() {
    NameSyntax nameSyntax;
    StringStream ss("a123-0x6fffff");
    if(nameSyntax.check(ss)) {
        std::string prefix = nameSyntax.match(ss);
        std::cout << prefix << std::endl;
    }else {
        std::cout << "[Not Match]" << std::endl;
    }
}

