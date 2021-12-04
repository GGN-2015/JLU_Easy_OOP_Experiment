#include <assert.h>
#include <iostream>
#include <string>

#include "CommentSyntax.h"
#include "StringStream.h"

bool CommentSyntax::check(StringStream& ss) {
    if(ss.size() < 2) {
        return false; // 注释的语法是两个左斜线然后后面跟着若干个字符 
    }else {
        std::string stmp = ss.front(2); // front 语句一定不会改写内容 
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
    return false; // 注释是不重要的 
}

std::string CommentSyntax::getSyntaxName() const {
    return "CommentSyntax";
}

