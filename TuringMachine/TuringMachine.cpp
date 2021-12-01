#include <assert.h>

#include "TuringMachine.h"

void TuringMachine::prevBit() {
    mActiveIndex --;
    assert(mActiveIndex >= 0); // C 语言风格的动态错误检查 
}

void TuringMachine::nextBit() {
    mActiveIndex ++;
    if((mMemory.size() - 1) < mActiveIndex) { // 动态延长图灵机的纸带 
        mMemory.push_back(false);
    }
}

bool TuringMachine::getBit() const { // 读取一个位置的值 
    return mMemory[mActiveIndex];
}

void TuringMachine::setBit(bool nVal) { // 设置一个位置的值 
    mMemory[mActiveIndex] = nVal;
}

