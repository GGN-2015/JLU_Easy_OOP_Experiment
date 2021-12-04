#include <assert.h>

#include "ErrorMgr.h" // 错误信息管理器 
#include "MemberMap.h"
#include "VarType.h"
#include "TypeMgr.h"

VarType::VarType(const std::vector<std::string>& varType)
    :mVarType(varType) {
    assert(isType(varType)); // 要求 varType 必须是类型才行 
}

int VarType::size() const {
    // 能执行到这句话，说明类型一定已经是合法类型 
    if(mVarType[0] == "PTR") {
        return SIZE_OF_PTR;
        // 指针类型就占一个单元的大小 
    }else if(mVarType[0] == "VAR") {
        return SIZE_OF_VAR;
        // 基础变量也就占一个单元的大小 
    }else if(mVarType[0] == "VOID") {
        return 0;
        // 空类型不占据变量储存空间 
    }else {
        // mVarType[0] 一定等于 "TYPE" 不然不是类型 
        // 计算结构体类型 
        return TypeMgr::getInstance().getTypeMessage(mVarType[1]).sizeOfSturct();
    }
}

bool VarType::same(const VarType& rhs) const {
    return mVarType == rhs.mVarType;
    // 直接比较两个 vector 是否完全相同即可 
}

bool VarType::isType(const std::vector<std::string>& varType) {
    // 判断一个类型是否是一个合法的类型 
    int i = 0;
    while(i < varType.size() && varType[i] == "PTR") {
        i ++;
    }
    if(i >= varType.size()) {
        // 要求至少有一个不是 PTR 的基类型 
        ErrorMgr::getInstance().push(__FILE__, __LINE__, "PTR 类型需要给出对应的基类型才能构成有效类型");
        return false;
    }
    if(varType[i] == "VAR") {
        // VAR 必须是 vector 中最后一个元素 
        if(i != varType.size() - 1) {
            ErrorMgr::getInstance().push(__FILE__, __LINE__, "基础类型 VAR 后不能再有修饰信息");
            return false;
        }else {
            return true;
        }
    }else if(varType[i] == "VOID") { // 空类型 
        // VOID 前面不允许有 PTR
        // PTR VOID 不是合法类型 
        if(i != 0) {
            ErrorMgr::getInstance().push(__FILE__, __LINE__, "不允许建立指向 VOID 类型的指针");
            return false;
        }else if(varType.size() > 1) {
            ErrorMgr::getInstance().push(__FILE__, __LINE__, "基础类型 VOID 后不能再有修饰信息");
            return false;
        }else {
            return true;   
        }
    }else if(varType[i] == "TYPE") { // 自定义类型 
        if(i != varType.size() - 2) {
            ErrorMgr::getInstance().push(__FILE__, __LINE__, "TYPE 后要求有且只有一个结构体名字");
            return false;
            // TYPE 必须是倒数第二个元素 
        }else {
            // 最后面的那个类型名必须能在所有类型中查找到 
            if(!TypeMgr::getInstance().checkTypeExist(varType[i + 1])) {
                ErrorMgr::getInstance().push(__FILE__, __LINE__, "结构体名字未找到");
                return false;
            }else {
                return true;
            }
        }
    }else {
        // 发现了不认识的基类型 varType[i]
        return false;
    }
    ErrorMgr::getInstance().push(__FILE__, __LINE__, "类型检查程序有没考虑到的情况");
    return false;
}

VarType::VarType() {
    // 什么都不做，为了兼容 tuple 库 
}

bool VarType::isPointer() const { // 判断是不是指针 
    if(mVarType.size() == 0) {
        return false;
    }else {
        return mVarType[0] == "PTR";
    }
}

