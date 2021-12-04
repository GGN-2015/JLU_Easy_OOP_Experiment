#ifndef TYPEMGR_H
#define TYPEMGR_H

#include <map>
#include <string>

#include "MemberMap.h" // ��Աӳ�䣺�� ��Ա�� => VarType ����, �ټ�¼һЩ�����ĸ�����Ϣ 

class TypeMgr {  // �Զ���ṹ�����͹����� 
public:
    static TypeMgr& getInstance();                   // ��̬�������͹����� 
    bool checkTypeExist(std::string typeName) const; // ���ĳ���������Ƿ���� 
    
    void createNewType(std::string typeName, const MemberMap& memberMap); // �½����� 
    const MemberMap& getTypeMessage(std::string typeName);                // ��ȡ������Ϣ 
    
    static bool checkTypeNameSyntax(std::string typeName);
    
private:
    TypeMgr();
    
    std::map<std::string, MemberMap> mTypeMessage; // ����������Ϣ 
    
    TypeMgr(const TypeMgr&) = delete;
    TypeMgr& operator= (const TypeMgr&) = delete;
};

#endif

