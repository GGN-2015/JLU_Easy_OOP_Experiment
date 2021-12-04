#ifndef VARTYPE_H
#define VARTYPE_H

#include <string>
#include <vector>

class VarType { // 记录变量的类型 
public:
    VarType();
    VarType(const std::vector<std::string>& varType); // 构造时检查类型是否合法 
    
    int size() const;                // 返回一个 size 
    bool same(const VarType&) const; // 比较两个类型是否一致 
    
    static bool isType(const std::vector<std::string>& varType); // 判断是否是合法类型 
    bool isPointer() const; // 判断是不是指针 
    
    static const int SIZE_OF_PTR = 1;
    static const int SIZE_OF_VAR = 1;
private:
    std::vector<std::string> mVarType; // 记录一个字符串序列表示变量的类型 
};

#endif

