#include <assert.h>
#include <cctype>
#include <string>

#include "StringStream.h"
#include "NumicSyntax.h"

bool NumicSyntax::check(StringStream& ss) {
    if(ss.empty()) {
        return false;
    }else {
        return isdigit(ss.front());
    }
}

std::string NumicSyntax::match(StringStream& ss) {
    assert(check(ss));
    
    std::string ans = "";
    while(!ss.empty() && availableChar(ss.front())) {
        ans += ss.front();
        ss.popFront();
    }
    return ans;
}

bool NumicSyntax::availableChar(char c) const {
    return isdigit(c) || isalpha(c) || c == '.';
}

NumicSyntax* NumicSyntax::getInstance() {
    static NumicSyntax ns;
    return &ns;
}

bool NumicSyntax::vital() {
    return true; // 数值类型是重要的 
}

std::string NumicSyntax::getSyntaxName() const {
    return "NumicSyntax";
}

