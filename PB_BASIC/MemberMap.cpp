#include <assert.h>

#include "MemberMap.h"

MemberMap::MemberMap() {
    mSize = 0;
}

bool MemberMap::checkMemberExist(std::string memberName) const {
    return mMemberMessage.count(memberName);
}

void MemberMap::addMemberMessage(std::string memberName, const VarType& varType) {
    assert(!checkMemberExist(memberName)); // 成员不允许重名 
    
    mMemberOffset[memberName] = mSize;
    mMemberMessage[memberName] = varType;
    mSize += varType.size(); // 新增一个元素 
}

int MemberMap::sizeOfSturct() const {
    return mSize;
}

const VarType& MemberMap::getMemberMessage(std::string memberName) {
    assert(checkMemberExist(memberName));
    
    return mMemberMessage[memberName];
}

