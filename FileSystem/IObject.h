#pragma once
// ������ʾһ������Ķ��󣬿�����һ���ļ��л���һ���ļ� 

#include <string>

class IObject {
public:
    virtual std::string getObjectName() const = 0;        // �ļ���Ҫ��ֻ����ĸ�����»��� 
    virtual void changeObjectName(std::string) = 0; // �޸��ļ��� 
    virtual std::string getObjectType() const = 0;        // DIR / FILE
};

