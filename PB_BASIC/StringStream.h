#ifndef STRINGSTREAM_H
#define STRINGSTREAM_H

#include <string>

class StringStream { // 手写一个字符流 
public:
    StringStream(std::string);  // 根据构建一个字符流，字符串中不应该有 
    bool empty() const;         // 检测流是否为空 
    char front() const;         // 读取第一个字符，如果字符数列已经为空，返回 0 
    void popFront();            // 删除第一个字符，如果字符数列已经为空，忽略此操作 
    
    void withdraw(int cnt = 1); // 撤销一个字符的删除，如果序列已经还原，报错 
    int  size() const;          // 计算剩余字符串个数 
    
    std::string front(int len); // 获取前若干个字符 
    
    int position() const;       // 获得当前的位置 ID 
    
private:
    std::string mString;
    int mIndex;
};

#endif

