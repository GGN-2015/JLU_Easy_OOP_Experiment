#ifndef MEMORY_H
#define MEMORY_H // 存储器数据结构, 存储器中每个位置的值都是 double 

class Memory {
public:
    static Memory& getInstance(); // 静态单例 
    ~Memory();
    
    double getValueAt(int index)   const; // 获取存储器中某个变量的值 
    int getMemoryLength()          const; // 获取存储器中值的个数 
    int pushVar(int len)                ; // 在栈空间中新增一块长度为 len 的内存并返回首地址 
    int dumpVar(int len)                ; // 在堆空间中申请一块长度为 len 的内存并返回首地址 
    bool checkAvailable(int index) const; // 检测某个位置是否可读 
    void popVar(int len);                 // 释放堆空间 
    void setValueAt(int pos, double val); // 内存赋值 
    
    static const int MEMORY_LENGTH = 1048576; // 最大地址下标 
private:
    Memory();
    
    double* mMemory;   // 储存空间 
    int     mStackTop; // 栈顶 
    int     mDumpTop;  // 堆顶 
};

#endif

