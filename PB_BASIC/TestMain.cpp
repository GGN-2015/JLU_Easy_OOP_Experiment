#include <iostream>
#include <string>
#include <typeinfo>

#include "CommentSyntax.h"
#include "NameSyntax.h"
#include "NumicSyntax.h"
#include "OperatorSyntax.h"
#include "StringStream.h"
#include "SyntaxChecker.h"

void testStringStream();
void testNumicSyntax();
void testNameSyntax();
void testCommentSyntax();
void testOperatorSyntax();
void testSyntaxChecker();

int main(int argc, char** argv) {
    testSyntaxChecker();
	return 0;
}

// -------------------------------------------------------------------- //

void testSyntaxChecker() {
    SyntaxChecker sc;
    std::cout << "Input a Line:";
    
    std::string line;
    std::getline(std::cin, line);
    
    SyntaxWordList slist;
    sc.syntaxCheck(line, slist);
    
    for(auto pr: slist) {
        std::cout << "[" << pr.first << "]\t: " << typeid(*pr.second).name() << std::endl;
    }
}

void testOperatorSyntax() {
    OperatorSyntax os;
    StringStream ss("1 = 3");
    if(os.check(ss)) {
        std::cout << os.match(ss) << std::endl;
    }else {
        std::cout << "[Not Match]" << std::endl;
    }
}

void testCommentSyntax() {
    CommentSyntax cs;
    StringStream ss("// hello world!");
    if(cs.check(ss)) {
        std::string prefix = cs.match(ss);
        std::cout << prefix << std::endl;
    }else {
        std::cout << "[Not Match]" << std::endl;
    }
}

void testStringStream() { // StringStream 的测试代码 
    StringStream ss("hello world!");
    while(!ss.empty()) {
        std::cout << (int)ss.front() << " : {" << ss.front() << "}" << std::endl;
        ss.popFront();
    }
}

void testNumicSyntax() { // 数值识别 
    NumicSyntax numicSyntax;
    StringStream ss("0x7fffffff-0x6fffff");
    if(numicSyntax.check(ss)) {
        std::string prefix = numicSyntax.match(ss);
        std::cout << prefix << std::endl;
    }else {
        std::cout << "[Not Match]" << std::endl;
    }
}

void testNameSyntax() {
    NameSyntax nameSyntax;
    StringStream ss("a123-0x6fffff");
    if(nameSyntax.check(ss)) {
        std::string prefix = nameSyntax.match(ss);
        std::cout << prefix << std::endl;
    }else {
        std::cout << "[Not Match]" << std::endl;
    }
}

