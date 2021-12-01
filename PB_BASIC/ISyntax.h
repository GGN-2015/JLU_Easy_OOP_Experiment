#ifndef ISYNTAX_H
#define ISYNTAX_H

#include <string>
class StringStream;

class ISyntax { // 词法分析器的抽象格式 
public:
    virtual bool        check(StringStream&) = 0; // 检测是否能够匹配 
    virtual std::string match(StringStream&) = 0; // 读出一个语法成分 
    
    // 约定，调用 match 时保证一定已经经过了 check 并且返回值值为 true
    virtual bool vital() = 0; // 是否重要 
};

#endif

