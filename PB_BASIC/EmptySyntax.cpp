#include <assert.h>

#include "EmptySyntax.h"
#include "StringStream.h"

bool EmptySyntax::check(StringStream& ss) {
    return !ss.empty() && availableChar(ss.front());
}

std::string EmptySyntax::match(StringStream& ss) {
    assert(check(ss));
    
    std::string ans = "";
    while(!ss.empty() && availableChar(ss.front())) {
        ans += ss.front();
        ss.popFront();
    }
    return ans;
}

bool EmptySyntax::availableChar(char c) const { // 钦定的几种空白字符 
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}

EmptySyntax* EmptySyntax::getInstance() {
    static EmptySyntax es;
    return &es;
}

bool EmptySyntax::vital() {
    return false; // 空白字符是不重要的 
}

std::string EmptySyntax::getSyntaxName() const {
    return "EmptySyntax";
}

