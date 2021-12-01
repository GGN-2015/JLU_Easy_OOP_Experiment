#include <assert.h>

#include "TuringMachine.h"

void TuringMachine::prevBit() {
    mActiveIndex --;
    assert(mActiveIndex >= 0); // C ���Է��Ķ�̬������ 
}

void TuringMachine::nextBit() {
    mActiveIndex ++;
    if((mMemory.size() - 1) < mActiveIndex) { // ��̬�ӳ�ͼ�����ֽ�� 
        mMemory.push_back(false);
    }
}

bool TuringMachine::getBit() const { // ��ȡһ��λ�õ�ֵ 
    return mMemory[mActiveIndex];
}

void TuringMachine::setBit(bool nVal) { // ����һ��λ�õ�ֵ 
    mMemory[mActiveIndex] = nVal;
}

