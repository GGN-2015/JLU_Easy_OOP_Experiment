#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H

#include <vector>

class TuringMachine { // ������ʲô��ͼ��� 
public:
    void prevBit(); // ��дͷ��ǰ�ƶ� 
    void nextBit(); // ��дͷ����ƶ� 
    
    bool getBit() const;    // ��ȡ��ǰָ��ָ��λ�õ�ֵ 
    void setBit(bool nVal); // ���õ�ǰָ��ָ���λ�õ�ֵ 
    
private:
    int mActiveIndex;              // ��дͷ��λ�� 
    std::vector<bool> mMemory {0}; // ֽ�� 
};

#endif

