#pragma once
// 用来表示一个抽象的对象，可能是一个文件夹或者一个文件 

#include <string>

class IObject {
public:
    virtual std::string getObjectName() const = 0;        // 文件名要求只有字母数字下划线 
    virtual void changeObjectName(std::string) = 0; // 修改文件名 
    virtual std::string getObjectType() const = 0;        // DIR / FILE
};

