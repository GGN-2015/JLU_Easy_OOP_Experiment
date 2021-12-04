#ifndef TYPEMGR_H
#define TYPEMGR_H

#include <map>
#include <string>

#include "MemberMap.h" // 成员映射：从 成员名 => VarType 对象, 再记录一些其他的辅助信息 

class TypeMgr {  // 自定义结构体类型管理器 
public:
    static TypeMgr& getInstance();                   // 静态单例类型管理器 
    bool checkTypeExist(std::string typeName) const; // 检查某个类型名是否存在 
    
    void createNewType(std::string typeName, const MemberMap& memberMap); // 新建类型 
    const MemberMap& getTypeMessage(std::string typeName);                // 获取类型信息 
    
    static bool checkTypeNameSyntax(std::string typeName);
    
private:
    TypeMgr();
    
    std::map<std::string, MemberMap> mTypeMessage; // 储存类型信息 
    
    TypeMgr(const TypeMgr&) = delete;
    TypeMgr& operator= (const TypeMgr&) = delete;
};

#endif

