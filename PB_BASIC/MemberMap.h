#ifndef MEMBERMAP_H
#define MEMBERMAP_H

#include <map>
#include <string>

#include "VarType.h"

class MemberMap { 
public:
    MemberMap();
    
    bool checkMemberExist(std::string memberName) const; // ����Ա�Ƿ��Ѿ����� 
    void addMemberMessage(std::string memberName, const VarType& varType);
    // û�� delete, ���ֱ���� mSize ���ۼӶ���ĳߴ缴�� 
    
    int sizeOfSturct() const; // ����ṹ��Ĵ�С 
    const VarType& getMemberMessage(std::string memberName); // ��ȡ��Ա��Ϣ 

private:
    std::map<std::string, VarType> mMemberMessage; // ��Ա�� => ��Ա VarType
    std::map<std::string, int> mMemberOffset;      // ��Ա�� => ��ƫ���� 
    int mSize; // ��ǰ���͵� size 
};

#endif

