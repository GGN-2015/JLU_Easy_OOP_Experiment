#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H

#include <vector>

class TuringMachine { // 定义了什么叫图灵机 
public:
    void prevBit(); // 读写头向前移动 
    void nextBit(); // 读写头向后移动 
    
    bool getBit() const;    // 获取当前指针指向位置的值 
    void setBit(bool nVal); // 设置当前指针指向的位置的值 
    
private:
    int mActiveIndex;              // 读写头的位置 
    std::vector<bool> mMemory {0}; // 纸带 
};

#endif

