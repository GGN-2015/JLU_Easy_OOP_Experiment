#ifndef VARTYPE_H
#define VARTYPE_H

#include <string>
#include <vector>

class VarType { // ��¼���������� 
public:
    VarType();
    VarType(const std::vector<std::string>& varType); // ����ʱ��������Ƿ�Ϸ� 
    
    int size() const;                // ����һ�� size 
    bool same(const VarType&) const; // �Ƚ����������Ƿ�һ�� 
    
    static bool isType(const std::vector<std::string>& varType); // �ж��Ƿ��ǺϷ����� 
    bool isPointer() const; // �ж��ǲ���ָ�� 
    
    static const int SIZE_OF_PTR = 1;
    static const int SIZE_OF_VAR = 1;
private:
    std::vector<std::string> mVarType; // ��¼һ���ַ������б�ʾ���������� 
};

#endif

