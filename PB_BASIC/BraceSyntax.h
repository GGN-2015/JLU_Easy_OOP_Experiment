#ifndef BRACESYNTAX_H
#define BRACESYNTAX_H

#include <string>
#include "ISyntax.h"

class StringStream;
class LeftBraceSyntax: public ISyntax { // ×óÐ¡À¨ºÅ 
public:
    bool        check(StringStream&);
    std::string match(StringStream&);
    
    static LeftBraceSyntax* getInstance();
    bool vital();
    
    virtual std::string getSyntaxName() const;
};

class RightBraceSyntax: public ISyntax { // ×óÐ¡À¨ºÅ 
public:
    bool        check(StringStream&);
    std::string match(StringStream&);
    
    static RightBraceSyntax* getInstance();
    bool vital();
    
    virtual std::string getSyntaxName() const;
};

#endif

