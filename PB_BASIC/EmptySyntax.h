#ifndef EMPTYSYNTAX_H
#define EMPTYSYNTAX_H

#include <string>

#include "ISyntax.h"

class StringStream;
class EmptySyntax: public ISyntax {
public:
    bool        check(StringStream&);
    std::string match(StringStream&);
    
    static EmptySyntax* getInstance();
    virtual bool vital();
    
private:
    bool availableChar(char c) const; // ���кϷ��Ŀհ��ַ� 
};

#endif

