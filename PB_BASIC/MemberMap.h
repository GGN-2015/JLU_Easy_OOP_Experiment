#ifndef MEMBERMAP_H
#define MEMBERMAP_H

#include <map>
#include <string>

#include "VarType.h"

class MemberMap { 
public:
    MemberMap();
    
    bool checkMemberExist(std::string memberName) const; // 检查成员是否已经存在 
    void addMemberMessage(std::string memberName, const VarType& varType);
    // 没有 delete, 因此直接在 mSize 上累加对象的尺寸即可 
    
    int sizeOfSturct() const; // 计算结构体的大小 
    const VarType& getMemberMessage(std::string memberName); // 获取成员信息 

private:
    std::map<std::string, VarType> mMemberMessage; // 成员名 => 成员 VarType
    std::map<std::string, int> mMemberOffset;      // 成员名 => 首偏移量 
    int mSize; // 当前类型的 size 
};

#endif

