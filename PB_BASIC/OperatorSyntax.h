#ifndef OPERATORSYNTAX_H
#define OPERATORSYNTAX_H

#include <string>

#include "ISyntax.h"

class StringStream;
class OperatorSyntax: public ISyntax { // 加减乘除等双目运算 
public:
    bool        check(StringStream&);
    std::string match(StringStream&);
    
    bool checkSucess(std::string) const; // 检测一个字符串是否是合法的算符 
    static OperatorSyntax* getInstance();
    
    virtual bool vital();
    
private:
    bool singleChar(char c)    const; // 单字符的算术运算符 
    bool multiChar(char c)     const; // 可能多字符的比较运算符 
    bool availableChar(char c) const;
};

#endif

