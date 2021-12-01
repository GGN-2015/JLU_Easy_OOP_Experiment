#ifndef BRACESYNTAX_H
#define BRACESYNTAX_H

#include <string>
#include "ISyntax.h"

class StringStream;
class LeftBraceSyntax: public ISyntax { // ��С���� 
public:
    bool        check(StringStream&);
    std::string match(StringStream&);
    
    static LeftBraceSyntax* getInstance();
    bool vital();
};

class RightBraceSyntax: public ISyntax { // ��С���� 
public:
    bool        check(StringStream&);
    std::string match(StringStream&);
    
    static RightBraceSyntax* getInstance();
    bool vital();
};

#endif

