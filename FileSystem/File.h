#pragma once

#include <string>
#include <vector>
#include "IObject.h"

class File: public IObject {
public:
    File(std::string fileName); // 创建文件时要给出文件名 
    
    std::string getObjectName() const;        // 返回文件名 
    std::string getObjectType() const;        // DIR / FILE
    void changeObjectName(std::string); // 修改文件名 
    
    int getLineCount() const;                       // 计算文件的行数 
    std::string getLineById(int index) const;       // 找到文件中某行内容，约定行号从 1 开始 
    bool insertLineBeforeId(int index, std::string); // 在某行前插入内容 
    
    void deleteLineById(int index); // 根据 index 删除某一行内容 
    virtual void show(int from = 0, int to = -1) const; // 显示一个区间内的内容 
    void append(std::string newLine); // 在文件尾插入内容 
    
protected:
    void showLine(int prelen, int index) const; // 这里的 index 是实际的下标 
    int getRealLineId(int index) const;         // 获取 vector 中某行的存储位置 
    std::string getLineMessage(int from, int to) const; // 获得行号信息 

    std::string              mFileName; // 记录文件名 
    std::vector<std::string> mText;     // 记录文本内容 
};

