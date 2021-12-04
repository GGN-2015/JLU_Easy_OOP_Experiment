#include <assert.h>
#include <cctype>

#include "ErrorMgr.h"
#include "TypeMgr.h"

TypeMgr& TypeMgr::getInstance() { // 静态单例 
    static TypeMgr tm;
    return tm;
}

bool TypeMgr::checkTypeExist(std::string typeName) const {
    // 查看一个变量类型是否存在 
    return mTypeMessage.count(typeName);
}

void TypeMgr::createNewType(std::string typeName, const MemberMap& memberMap) {
    // 创建一个新的变量类型 
    assert(!checkTypeExist(typeName));     // 原先不能已经出现过 
    assert(checkTypeNameSyntax(typeName)); // 变量名要在词法上合理 
    
    mTypeMessage[typeName] = memberMap;    // 存储 
}

const MemberMap& TypeMgr::getTypeMessage(std::string typeName) {
    assert(checkTypeExist(typeName)); // 原来对象已经存在 
    
    return mTypeMessage[typeName];
}

bool TypeMgr::checkTypeNameSyntax(std::string typeName) {
    // 类型名规范:
    // 字母或下划线开头的字母数字下划线序列
    // 要求不能全是大写字母，因为关键字只含有大写字母 
    if(typeName == "") {
        ErrorMgr::getInstance().push(__FILE__, __LINE__, "类型名不允许为空");
        return false;
    }
    if(!isalpha(typeName[0]) && typeName[0] != '_') {
        ErrorMgr::getInstance().push(
            __FILE__, 
            __LINE__, 
            "类型名的第一个字符只能是字母或下划线不允许为空"
        );
        return false;
    }
    int capitalCnt = 0;
    for(int i = 0; i < typeName.length(); i ++) {
        if(isupper(typeName[i])) {
            capitalCnt ++;
        }
        if(!isalpha(typeName[i]) && !isdigit(typeName[i]) && typeName[i] != '_') {
            std::string ctmp = "";
            ctmp += typeName[i]; // 记录非法字母 
            
            ErrorMgr::getInstance().push(__FILE__, __LINE__, "类型名出现非法字符 [" + ctmp + "]");
            return false;
        }
    }
    if(capitalCnt == typeName.length()) {
        ErrorMgr::getInstance().push(__FILE__, __LINE__, "类型名不允许只含有大写字母");
        return false;
    }
    return true;
}

TypeMgr::TypeMgr() {
    // 什么也不做 
}
