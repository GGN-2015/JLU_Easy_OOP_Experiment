#ifndef LEFTVALUE_H
#define LEFTVALUE_H // ��ֵ = ���� + ��ַ 

#include "VarType.h"

class RightValue;

class LeftValue {
public:
    friend class RightValue;
    
    LeftValue(int address, const VarType& varType); // ������ֵ 
    
    void getRightValue(RightValue&) const;  // �����ֵ 
    void setRightValue(const RightValue&);  // ����������ֵ 
    void getPointerRightValue(RightValue&); // ���ָ����ֵ 
    bool sameType(const RightValue&) const; // �ж������Ƿ���ͬ 
    
private:
    int mAddress;     // ������ַ 
    VarType mVarType; // �������� 
};

#endif

