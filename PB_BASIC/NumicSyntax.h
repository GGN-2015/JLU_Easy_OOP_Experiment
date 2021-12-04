#ifndef NUMICSYNTAX_H
#define NUMICSYNTAX_H

#include "ISyntax.h"

class StringStream;
class NumicSyntax: public ISyntax { // ƥ�������õĴʷ���Ԫ 
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

