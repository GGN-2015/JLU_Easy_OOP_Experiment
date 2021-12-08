#pragma once

#include <string>

class SyntaxWord {
public:
    enum SyntaxWordType {
        TYPE_LABEL = 0, // 常量或者变量名、函数名 
        TYPE_ADD,
        TYPE_SUB,
        TYPE_MUL,
        TYPE_DIV,
        TYPE_MOD,
        TYPE_LEFT, // 左括号和右括号 
        TYPE_RIGHT,
    };
    
    SyntaxWord(std::string raw, SyntaxWordType type);
    std::string getRaw() const;    // 获取原始信息字符串 
    SyntaxWordType getType() const; // 获取类型 ID 

private:
    std::string mRaw;
    SyntaxWordType mType;
};

