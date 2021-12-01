#include <assert.h>

#include "CommaSyntax.h"
#include "StringStream.h"

bool CommaSyntax::check(StringStream& ss) {
    return !ss.empty() && ss.front() == ',';
}

std::string CommaSyntax::match(StringStream& ss) {
    assert(check(ss));
    
    std::string ans = "";
    ans += ss.front(); // ֻ����һ������ 
    ss.popFront();
    return ans;
}

CommaSyntax* CommaSyntax::getInstance() {
    static CommaSyntax cs;
    return &cs;
}

bool CommaSyntax::vital() {
    return true; // ��������Ҫ�� 
}

