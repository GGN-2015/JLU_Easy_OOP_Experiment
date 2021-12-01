#include <assert.h>

#include "QuoteSyntax.h"
#include "StringStream.h"

bool QuoteSyntax::check(StringStream& ss) {
    return !ss.empty() && ss.front() == 34;
}

std::string QuoteSyntax::match(StringStream& ss) {
    assert(check(ss));
    
    std::string ans = "";
    ans += ss.front();
    ss.popFront();
    while(!ss.empty()) {
        ans += ss.front();
        if(ss.front() == 34) { // 读到双引号结束 
            ss.popFront();
            break;
        }else {
            ss.popFront();
        }
    }
    return ans;
}

QuoteSyntax* QuoteSyntax::getInstance() {
    static QuoteSyntax qs;
    return &qs;
}

bool QuoteSyntax::vital() {
    return true; // 字符串常量是重要的 
}

