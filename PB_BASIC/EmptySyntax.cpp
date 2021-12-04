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

bool EmptySyntax::availableChar(char c) const { // �ն��ļ��ֿհ��ַ� 
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}

EmptySyntax* EmptySyntax::getInstance() {
    static EmptySyntax es;
    return &es;
}

bool EmptySyntax::vital() {
    return false; // �հ��ַ��ǲ���Ҫ�� 
}

std::string EmptySyntax::getSyntaxName() const {
    return "EmptySyntax";
}

