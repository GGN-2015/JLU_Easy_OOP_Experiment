#include <assert.h>

#include "Memory.h"

Memory::Memory() {
    mMemory = new double[MEMORY_LENGTH + 1];
    mStackTop = 0;
    mDumpTop  = MEMORY_LENGTH + 1;
    // Top: 当前最后一个被使用的下标 
}

Memory::~Memory() {
    delete[] mMemory; // 清空存储空间 
}

double Memory::getValueAt(int index) const {
    assert(checkAvailable(index));
    
    return mMemory[index];
}

int Memory::getMemoryLength() const {
    return mDumpTop - mStackTop - 1;
}

int Memory::pushVar(int len) {
    assert(len >= 1); // 申请的长度必须 >= 1 
    assert(getMemoryLength() >= len);
    
    int ans = mStackTop + 1;
    mStackTop += len;
    return ans; // 返回首地址 
}

int Memory::dumpVar(int len) {
    assert(len >= 1); // 申请的长度必须 >= 1 
    assert(getMemoryLength() >= len);
    
    mDumpTop -= len;
    return mDumpTop;
}

void Memory::popVar(int len) {
    assert(len >= 1);             // 要求 len >= 1 
    assert(mStackTop - len >= 0);
    
    mStackTop -= len;
}

bool Memory::checkAvailable(int index) const {
    return
        (1 <= index && index <= mStackTop) || // 在栈空间中 
        (mDumpTop <= index && index <= MEMORY_LENGTH); // 在堆空间中 
}

Memory& Memory::getInstance() {
    static Memory mem;
    return mem;
}

void Memory::setValueAt(int pos, double val) {
    assert(checkAvailable(pos));
    
    mMemory[pos] = val; // 设置一个位置的值 
}

