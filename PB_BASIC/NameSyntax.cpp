#include <assert.h>
#include <string>

#include "NameSyntax.h"
#include "StringStream.h"

bool NameSyntax::check(StringStream& ss) {
    if(ss.empty()) {
        return false; // 空字符串不能匹配绝大多数语法成分 
    }else {
        return isalpha(ss.front()) || ss.front() == '_'; // 字母或者下划线 
    }
}

std::string NameSyntax::match(StringStream& ss) {
    assert(check(ss));
    
    std::string ans = "";
    while(!ss.empty() && availableChar(ss.front())) {
        ans += ss.front();
        ss.popFront();
    }
    return ans;
}

bool NameSyntax::availableChar(char c) const {
    return isdigit(c) || isalpha(c) || c == '_'; // 字母数字或者下划线 
}

NameSyntax* NameSyntax::getInstance() {
    static NameSyntax ns;
    return &ns;
}

bool NameSyntax::vital() {
    return true; // 标识符是重要的 
}

std::string NameSyntax::getSyntaxName() const {
    return "NameSyntax";
}

