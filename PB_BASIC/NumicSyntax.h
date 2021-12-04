#ifndef NUMICSYNTAX_H
#define NUMICSYNTAX_H

#include "ISyntax.h"

class StringStream;
class NumicSyntax: public ISyntax { // 匹配整数用的词法单元 
public:
    bool        check(StringStream&);
    std::string match(StringStream&);
    
    static NumicSyntax* getInstance();
    virtual bool vital();
    
    virtual std::string getSyntaxName() const;
    
private:
    bool availableChar(char c) const;
};

#endif

