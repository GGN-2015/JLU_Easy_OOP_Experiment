#include <assert.h>

#include "ErrorMgr.h" // ������Ϣ������ 
#include "MemberMap.h"
#include "VarType.h"
#include "TypeMgr.h"

VarType::VarType(const std::vector<std::string>& varType)
    :mVarType(varType) {
    assert(isType(varType)); // Ҫ�� varType ���������Ͳ��� 
}

int VarType::size() const {
    // ��ִ�е���仰��˵������һ���Ѿ��ǺϷ����� 
    if(mVarType[0] == "PTR") {
        return SIZE_OF_PTR;
        // ָ�����;�ռһ����Ԫ�Ĵ�С 
    }else if(mVarType[0] == "VAR") {
        return SIZE_OF_VAR;
        // ��������Ҳ��ռһ����Ԫ�Ĵ�С 
    }else if(mVarType[0] == "VOID") {
        return 0;
        // �����Ͳ�ռ�ݱ�������ռ� 
    }else {
        // mVarType[0] һ������ "TYPE" ��Ȼ�������� 
        // ����ṹ������ 
        return TypeMgr::getInstance().getTypeMessage(mVarType[1]).sizeOfSturct();
    }
}

bool VarType::same(const VarType& rhs) const {
    return mVarType == rhs.mVarType;
    // ֱ�ӱȽ����� vector �Ƿ���ȫ��ͬ���� 
}

bool VarType::isType(const std::vector<std::string>& varType) {
    // �ж�һ�������Ƿ���һ���Ϸ������� 
    int i = 0;
    while(i < varType.size() && varType[i] == "PTR") {
        i ++;
    }
    if(i >= varType.size()) {
        // Ҫ��������һ������ PTR �Ļ����� 
        ErrorMgr::getInstance().push(__FILE__, __LINE__, "PTR ������Ҫ������Ӧ�Ļ����Ͳ��ܹ�����Ч����");
        return false;
    }
    if(varType[i] == "VAR") {
        // VAR ������ vector �����һ��Ԫ�� 
        if(i != varType.size() - 1) {
            ErrorMgr::getInstance().push(__FILE__, __LINE__, "�������� VAR ��������������Ϣ");
            return false;
        }else {
            return true;
        }
    }else if(varType[i] == "VOID") { // ������ 
        // VOID ǰ�治������ PTR
        // PTR VOID ���ǺϷ����� 
        if(i != 0) {
            ErrorMgr::getInstance().push(__FILE__, __LINE__, "��������ָ�� VOID ���͵�ָ��");
            return false;
        }else if(varType.size() > 1) {
            ErrorMgr::getInstance().push(__FILE__, __LINE__, "�������� VOID ��������������Ϣ");
            return false;
        }else {
            return true;   
        }
    }else if(varType[i] == "TYPE") { // �Զ������� 
        if(i != varType.size() - 2) {
            ErrorMgr::getInstance().push(__FILE__, __LINE__, "TYPE ��Ҫ������ֻ��һ���ṹ������");
            return false;
            // TYPE �����ǵ����ڶ���Ԫ�� 
        }else {
            // �������Ǹ������������������������в��ҵ� 
            if(!TypeMgr::getInstance().checkTypeExist(varType[i + 1])) {
                ErrorMgr::getInstance().push(__FILE__, __LINE__, "�ṹ������δ�ҵ�");
                return false;
            }else {
                return true;
            }
        }
    }else {
        // �����˲���ʶ�Ļ����� varType[i]
        return false;
    }
    ErrorMgr::getInstance().push(__FILE__, __LINE__, "���ͼ�������û���ǵ������");
    return false;
}

VarType::VarType() {
    // ʲô��������Ϊ�˼��� tuple �� 
}

bool VarType::isPointer() const { // �ж��ǲ���ָ�� 
    if(mVarType.size() == 0) {
        return false;
    }else {
        return mVarType[0] == "PTR";
    }
}

