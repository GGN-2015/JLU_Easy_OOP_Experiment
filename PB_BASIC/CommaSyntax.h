#ifndef COMMASYNTAX_H
#define COMMASYNTAX_H // 逗号 

#include "ISyntax.h"

class StringStream;
class CommaSyntax: public ISyntax { // 单独识别一个逗号 
public:
    bool        check(StringStream&);
    std::string match(StringStream&);
    
    static CommaSyntax* getInstance();
    virtual bool vital();
    
    virtual std::string getSyntaxName() const;
};

#endif 

