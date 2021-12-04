#include <assert.h>
#include <string>
#include <vector>

#include "OperatorSyntax.h"
#include "StringStream.h"

bool OperatorSyntax::check(StringStream& ss) {
    if(ss.empty()) {
        return false;
    }else {
        return availableChar(ss.front());
    }
}

std::string OperatorSyntax::match(StringStream& ss) {
    assert(check(ss));
    
    std::string ans = "";
    if(singleChar(ss.front())) { // 单字符运算符 
        ans += ss.front();
        ss.popFront();
    }else {
        while(!ss.empty() && multiChar(ss.front())) {
            ans += ss.front();
            ss.popFront();
        }
    }
    return ans;
}

bool OperatorSyntax::availableChar(char c) const {
    return singleChar(c) || multiChar(c);
}

bool OperatorSyntax::singleChar(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

bool OperatorSyntax::multiChar(char c) const {
    return c == '>' || c == '<' || c == '=';
    // 大于 >, 小于 <, 大于等于 >=, 小于等于 <=, 等于 =, 不等于 <>
}

bool OperatorSyntax::checkSucess(std::string str) const {
    static std::vector<std::string> availableList
    {"+", "-", "*", "/", "<", ">", "<=", ">=", "==", "<>"};
    for(auto stmp: availableList) {
        if(stmp == str) return true; // 找到匹配的运算符 
    }
    return false; // 匹配失败 
}

OperatorSyntax*  OperatorSyntax::getInstance() {
    static OperatorSyntax os;
    return &os;
}

bool OperatorSyntax::vital() {
    return true; // 标识符是重要的 
}

std::string OperatorSyntax::getSyntaxName() const {
    return "OperatorSyntax";
}

