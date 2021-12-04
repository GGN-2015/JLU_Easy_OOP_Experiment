#ifndef LEFTVALUE_H
#define LEFTVALUE_H // 左值 = 类型 + 地址 

#include "VarType.h"

class RightValue;

class LeftValue {
public:
    friend class RightValue;
    
    LeftValue(int address, const VarType& varType); // 构建左值 
    
    void getRightValue(RightValue&) const;  // 获得右值 
    void setRightValue(const RightValue&);  // 重新设置右值 
    void getPointerRightValue(RightValue&); // 获得指针右值 
    bool sameType(const RightValue&) const; // 判断类型是否相同 
    
private:
    int mAddress;     // 变量地址 
    VarType mVarType; // 变量类型 
};

#endif

