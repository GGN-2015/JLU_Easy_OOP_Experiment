#include <assert.h>

#include "Memory.h"

Memory::Memory() {
    mMemory = new double[MEMORY_LENGTH + 1];
    mStackTop = 0;
    mDumpTop  = MEMORY_LENGTH + 1;
    // Top: ��ǰ���һ����ʹ�õ��±� 
}

Memory::~Memory() {
    delete[] mMemory; // ��մ洢�ռ� 
}

double Memory::getValueAt(int index) const {
    assert(checkAvailable(index));
    
    return mMemory[index];
}

int Memory::getMemoryLength() const {
    return mDumpTop - mStackTop - 1;
}

int Memory::pushVar(int len) {
    assert(len >= 1); // ����ĳ��ȱ��� >= 1 
    assert(getMemoryLength() >= len);
    
    int ans = mStackTop + 1;
    mStackTop += len;
    return ans; // �����׵�ַ 
}

int Memory::dumpVar(int len) {
    assert(len >= 1); // ����ĳ��ȱ��� >= 1 
    assert(getMemoryLength() >= len);
    
    mDumpTop -= len;
    return mDumpTop;
}

void Memory::popVar(int len) {
    assert(len >= 1);             // Ҫ�� len >= 1 
    assert(mStackTop - len >= 0);
    
    mStackTop -= len;
}

bool Memory::checkAvailable(int index) const {
    return
        (1 <= index && index <= mStackTop) || // ��ջ�ռ��� 
        (mDumpTop <= index && index <= MEMORY_LENGTH); // �ڶѿռ��� 
}

Memory& Memory::getInstance() {
    static Memory mem;
    return mem;
}

void Memory::setValueAt(int pos, double val) {
    assert(checkAvailable(pos));
    
    mMemory[pos] = val; // ����һ��λ�õ�ֵ 
}

