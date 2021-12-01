#ifndef NAMESYNTAX_H
#define NAMESYNTAX_H

#include <string>
#include "ISyntax.h"

class StringStream;
class NameSyntax: public ISyntax { // 变量名/关键字 
public:
    bool        check(StringStream&);
    std::string match(StringStream&);
    
    static NameSyntax* getInstance();
    virtual bool vital();
    
private:
    bool availableChar(char c) const;
}; 

#endif

