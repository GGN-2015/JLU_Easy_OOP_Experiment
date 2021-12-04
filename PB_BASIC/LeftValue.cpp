#include <assert.h>

#include "LeftValue.h"
#include "Memory.h"
#include "RightValue.h"

LeftValue::LeftValue(int address, const VarType& varType)
    :mAddress(address), mVarType(varType) {
    // ����һ����ֵ 
}

void LeftValue::getRightValue(RightValue& rv) const {
    // �õ������е���ֵ 
    rv.mVarType = mVarType; // ����ֱ�ӿ�����ȥ (�д��Ż�) 
    rv.mValue.clear();      // ����� 
    
    int len = mVarType.size(); // ����ռ�õĳߴ� 
    for(int i = 0; i < len; i ++) {
        rv.mValue.push_back(Memory::getInstance().getValueAt(mAddress + i));
    }
}

void LeftValue::setRightValue(const RightValue& rv) {
    assert(sameType(rv)); // ��������Ƿ���ͬ 
    
    // �����ڴ��еĸ�ֵ���� 
    int len = mVarType.size();
    for(int i = 0; i < len; i ++) {
        Memory::getInstance().setValueAt(mAddress + i, rv.mValue[i]);
        // ѭ����ֵ 
    }
}

bool LeftValue::sameType(const RightValue& rv) const {
    return mVarType.same(rv.mVarType);
    // �ж������Ƿ���ͬ������ͬ���ܸ�ֵ 
}

