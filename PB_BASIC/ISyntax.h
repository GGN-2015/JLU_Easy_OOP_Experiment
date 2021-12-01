#ifndef ISYNTAX_H
#define ISYNTAX_H

#include <string>
class StringStream;

class ISyntax { // �ʷ��������ĳ����ʽ 
public:
    virtual bool        check(StringStream&) = 0; // ����Ƿ��ܹ�ƥ�� 
    virtual std::string match(StringStream&) = 0; // ����һ���﷨�ɷ� 
    
    // Լ�������� match ʱ��֤һ���Ѿ������� check ���ҷ���ֵֵΪ true
    virtual bool vital() = 0; // �Ƿ���Ҫ 
};

#endif

