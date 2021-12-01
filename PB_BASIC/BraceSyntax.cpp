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
    return !ss.empty() && ss.front() == ')'; // 右小括号 
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
    return true; // 括号是重要的 
}

bool RightBraceSyntax::vital() {
    return true; // 括号是重要的 
}

