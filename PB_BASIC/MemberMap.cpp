#include <assert.h>

#include "MemberMap.h"

MemberMap::MemberMap() {
    mSize = 0;
}

bool MemberMap::checkMemberExist(std::string memberName) const {
    return mMemberMessage.count(memberName);
}

void MemberMap::addMemberMessage(std::string memberName, const VarType& varType) {
    assert(!checkMemberExist(memberName)); // ��Ա���������� 
    
    mMemberOffset[memberName] = mSize;
    mMemberMessage[memberName] = varType;
    mSize += varType.size(); // ����һ��Ԫ�� 
}

int MemberMap::sizeOfSturct() const {
    return mSize;
}

const VarType& MemberMap::getMemberMessage(std::string memberName) {
    assert(checkMemberExist(memberName));
    
    return mMemberMessage[memberName];
}

