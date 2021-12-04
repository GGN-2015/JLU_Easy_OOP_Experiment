#include <assert.h>

#include "LeftValue.h"
#include "Memory.h"
#include "RightValue.h"

LeftValue::LeftValue(int address, const VarType& varType)
    :mAddress(address), mVarType(varType) {
    // 构架一个左值 
}

void LeftValue::getRightValue(RightValue& rv) const {
    // 得到变量中的右值 
    rv.mVarType = mVarType; // 类型直接拷贝过去 (有待优化) 
    rv.mValue.clear();      // 先清空 
    
    int len = mVarType.size(); // 类型占用的尺寸 
    for(int i = 0; i < len; i ++) {
        rv.mValue.push_back(Memory::getInstance().getValueAt(mAddress + i));
    }
}

void LeftValue::setRightValue(const RightValue& rv) {
    assert(sameType(rv)); // 检查类型是否相同 
    
    // 进行内存中的赋值操作 
    int len = mVarType.size();
    for(int i = 0; i < len; i ++) {
        Memory::getInstance().setValueAt(mAddress + i, rv.mValue[i]);
        // 循环赋值 
    }
}

bool LeftValue::sameType(const RightValue& rv) const {
    return mVarType.same(rv.mVarType);
    // 判断类型是否相同，不相同不能赋值 
}

