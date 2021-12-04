#ifndef ERRORMGR_H
#define ERRORMGR_H // 错误管理器 

#include <string>
#include <vector>

struct ErrorMessage {
    std::string fileName; // 错误所在文件名 
    int lineNum;          // 错误所在行号 
    std::string message;  // 错误信息 
};

class ErrorMgr {
public:
    static ErrorMgr& getInstance(); // 获取错误管理器单例对象 
    void push(std::string fileName, int lineNum, std::string message); // 向错误序列中添加错误 
    void show(int line) const;      // 显示所有错误到屏幕 
    bool checkEmpty() const;        // 检查是否出现了错误 
    void clear();                   // 清空错误信息 

private:
    ErrorMgr();
    std::vector<ErrorMessage> mErrors; // 记录所有错误信息 
};

#endif

