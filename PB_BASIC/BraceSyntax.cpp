#include <assert.h>

#include "BraceSyntax.h"
#include "StringStream.h"

bool LeftBraceSyntax::check(StringStream& ss) {
    return !ss.empty() && ss.front() == '(';
}

std::string LeftBraceSyntax::match(StringStream& ss) {
    assert(check(ss));
    
    std::string ans = "";
    ans += ss.front();
    ss.popFront();
    return ans;
}

LeftBraceSyntax* LeftBraceSyntax::getInstance() {
    static LeftBraceSyntax lbs;
    return &lbs;
}

bool RightBraceSyntax::check(StringStream& ss) {
    return !ss.empty() && ss.front() == ')'; // ��С���� 
}

std::string RightBraceSyntax::match(StringStream& ss) {
    assert(check(ss));
    
    std::string ans = "";
    ans += ss.front();
    ss.popFront();
    return ans;
}

RightBraceSyntax* RightBraceSyntax::getInstance() {
    static RightBraceSyntax rbs;
    return &rbs;
}

bool LeftBraceSyntax::vital() {
    return true; // ��������Ҫ�� 
}

std::string LeftBraceSyntax::getSyntaxName() const {
    return "LeftBraceSyntax";
}

bool RightBraceSyntax::vital() {
    return true; // ��������Ҫ�� 
}

std::string RightBraceSyntax::getSyntaxName() const {
    return "RightBraceSyntax";
}

