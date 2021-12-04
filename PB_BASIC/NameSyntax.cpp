#include <assert.h>
#include <string>

#include "NameSyntax.h"
#include "StringStream.h"

bool NameSyntax::check(StringStream& ss) {
    if(ss.empty()) {
        return false; // ���ַ�������ƥ���������﷨�ɷ� 
    }else {
        return isalpha(ss.front()) || ss.front() == '_'; // ��ĸ�����»��� 
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
    return isdigit(c) || isalpha(c) || c == '_'; // ��ĸ���ֻ����»��� 
}

NameSyntax* NameSyntax::getInstance() {
    static NameSyntax ns;
    return &ns;
}

bool NameSyntax::vital() {
    return true; // ��ʶ������Ҫ�� 
}

std::string NameSyntax::getSyntaxName() const {
    return "NameSyntax";
}

