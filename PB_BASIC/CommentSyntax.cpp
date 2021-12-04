#include <assert.h>
#include <iostream>
#include <string>

#include "CommentSyntax.h"
#include "StringStream.h"

bool CommentSyntax::check(StringStream& ss) {
    if(ss.size() < 2) {
        return false; // ע�͵��﷨��������б��Ȼ�����������ɸ��ַ� 
    }else {
        std::string stmp = ss.front(2); // front ���һ�������д���� 
        return stmp == "//";
    }
}

std::string CommentSyntax::match(StringStream& ss) {
    assert(check(ss));
    
    std::string ans = "";
    while(!ss.empty()) {
        ans += ss.front();
        ss.popFront();
    }
    return ans;
}

CommentSyntax* CommentSyntax::getInstance() {
    static CommentSyntax cs;
    return &cs;
}

bool CommentSyntax::vital() {
    return false; // ע���ǲ���Ҫ�� 
}

std::string CommentSyntax::getSyntaxName() const {
    return "CommentSyntax";
}

