#ifndef QUOTESYNTAX_H
#define QUOTESYNTAX_H

#include "ISyntax.h"

class StringStream;
class QuoteSyntax: public ISyntax {
public:
    bool        check(StringStream&);
    std::string match(StringStream&);
    
    static QuoteSyntax* getInstance();
    virtual bool vital();
    
    virtual std::string getSyntaxName() const;
};

#endif

