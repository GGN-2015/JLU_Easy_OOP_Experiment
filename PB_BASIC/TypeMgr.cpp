#include <assert.h>
#include <cctype>

#include "ErrorMgr.h"
#include "TypeMgr.h"

TypeMgr& TypeMgr::getInstance() { // ��̬���� 
    static TypeMgr tm;
    return tm;
}

bool TypeMgr::checkTypeExist(std::string typeName) const {
    // �鿴һ�����������Ƿ���� 
    return mTypeMessage.count(typeName);
}

void TypeMgr::createNewType(std::string typeName, const MemberMap& memberMap) {
    // ����һ���µı������� 
    assert(!checkTypeExist(typeName));     // ԭ�Ȳ����Ѿ����ֹ� 
    assert(checkTypeNameSyntax(typeName)); // ������Ҫ�ڴʷ��Ϻ��� 
    
    mTypeMessage[typeName] = memberMap;    // �洢 
}

const MemberMap& TypeMgr::getTypeMessage(std::string typeName) {
    assert(checkTypeExist(typeName)); // ԭ�������Ѿ����� 
    
    return mTypeMessage[typeName];
}

bool TypeMgr::checkTypeNameSyntax(std::string typeName) {
    // �������淶:
    // ��ĸ���»��߿�ͷ����ĸ�����»�������
    // Ҫ����ȫ�Ǵ�д��ĸ����Ϊ�ؼ���ֻ���д�д��ĸ 
    if(typeName == "") {
        ErrorMgr::getInstance().push(__FILE__, __LINE__, "������������Ϊ��");
        return false;
    }
    if(!isalpha(typeName[0]) && typeName[0] != '_') {
        ErrorMgr::getInstance().push(
            __FILE__, 
            __LINE__, 
            "�������ĵ�һ���ַ�ֻ������ĸ���»��߲�����Ϊ��"
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
            ctmp += typeName[i]; // ��¼�Ƿ���ĸ 
            
            ErrorMgr::getInstance().push(__FILE__, __LINE__, "���������ַǷ��ַ� [" + ctmp + "]");
            return false;
        }
    }
    if(capitalCnt == typeName.length()) {
        ErrorMgr::getInstance().push(__FILE__, __LINE__, "������������ֻ���д�д��ĸ");
        return false;
    }
    return true;
}

TypeMgr::TypeMgr() {
    // ʲôҲ���� 
}
