#ifndef COMMASYNTAX_H
#define COMMASYNTAX_H // ���� 

#include "ISyntax.h"

class StringStream;
class CommaSyntax: public ISyntax { // ����ʶ��һ������ 
public:
    bool        check(StringStream&);
    std::string match(StringStream&);
    
    static CommaSyntax* getInstance();
    virtual bool vital();
    
    virtual std::string getSyntaxName() const;
};

#endif 

