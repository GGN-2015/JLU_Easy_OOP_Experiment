#ifndef MEMORY_H
#define MEMORY_H // �洢�����ݽṹ, �洢����ÿ��λ�õ�ֵ���� double 

class Memory {
public:
    static Memory& getInstance(); // ��̬���� 
    ~Memory();
    
    double getValueAt(int index)   const; // ��ȡ�洢����ĳ��������ֵ 
    int getMemoryLength()          const; // ��ȡ�洢����ֵ�ĸ��� 
    int pushVar(int len)                ; // ��ջ�ռ�������һ�鳤��Ϊ len ���ڴ沢�����׵�ַ 
    int dumpVar(int len)                ; // �ڶѿռ�������һ�鳤��Ϊ len ���ڴ沢�����׵�ַ 
    bool checkAvailable(int index) const; // ���ĳ��λ���Ƿ�ɶ� 
    void popVar(int len);                 // �ͷŶѿռ� 
    void setValueAt(int pos, double val); // �ڴ渳ֵ 
    
    static const int MEMORY_LENGTH = 1048576; // ����ַ�±� 
private:
    Memory();
    
    double* mMemory;   // ����ռ� 
    int     mStackTop; // ջ�� 
    int     mDumpTop;  // �Ѷ� 
};

#endif

