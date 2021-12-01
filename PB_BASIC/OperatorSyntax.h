#ifndef OPERATORSYNTAX_H
#define OPERATORSYNTAX_H

#include <string>

#include "ISyntax.h"

class StringStream;
class OperatorSyntax: public ISyntax { // �Ӽ��˳���˫Ŀ���� 
public:
    bool        check(StringStream&);
    std::string match(StringStream&);
    
    bool checkSucess(std::string) const; // ���һ���ַ����Ƿ��ǺϷ������ 
    static OperatorSyntax* getInstance();
    
    virtual bool vital();
    
private:
    bool singleChar(char c)    const; // ���ַ������������ 
    bool multiChar(char c)     const; // ���ܶ��ַ��ıȽ������ 
    bool availableChar(char c) const;
};

#endif

