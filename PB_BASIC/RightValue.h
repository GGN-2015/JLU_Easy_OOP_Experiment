#ifndef RIGHTVALUE_H
#define RIGHTVALUE_H // 右值 = 类型 + 数值 

#include <vector>

#include "VarType.h"

class RightValue {
public:
    friend class LeftValue;
    RightValue();
    
private:
    std::vector<double> mValue;
    VarType mVarType;
};

#endif

