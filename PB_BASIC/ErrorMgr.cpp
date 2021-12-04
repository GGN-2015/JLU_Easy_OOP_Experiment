#include <iostream> 

#include "ErrorMgr.h"

ErrorMgr& ErrorMgr::getInstance() {
    static ErrorMgr em;
    return em;
}

void ErrorMgr::push(std::string fileName, int lineNum, std::string message) {
    // 依次调用成员构造函数 
    mErrors.push_back(ErrorMessage{fileName, lineNum, message});
}

void ErrorMgr::show(int line) const {
    std::cout << "[ On line " << line << " ] ";
    std::cout << "[ " << mErrors.size() << " Error(s) occurs]" << std::endl;
    for(auto msg: mErrors) {
        // 输出所有错误信息 
        std::cout << msg.fileName << " " << msg.lineNum << " 行, " << msg.message << std::endl;
    }
}

bool ErrorMgr::checkEmpty() const {
    // 检测是否没有出现错误 
    return mErrors.size() == 0;
}

ErrorMgr::ErrorMgr() {
    // 什么也不做 
}

void ErrorMgr::clear() {
    mErrors.clear(); // 清空 vector 
}
