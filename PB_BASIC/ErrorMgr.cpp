#include <iostream> 

#include "ErrorMgr.h"

ErrorMgr& ErrorMgr::getInstance() {
    static ErrorMgr em;
    return em;
}

void ErrorMgr::push(std::string fileName, int lineNum, std::string message) {
    // ���ε��ó�Ա���캯�� 
    mErrors.push_back(ErrorMessage{fileName, lineNum, message});
}

void ErrorMgr::show(int line) const {
    std::cout << "[ On line " << line << " ] ";
    std::cout << "[ " << mErrors.size() << " Error(s) occurs]" << std::endl;
    for(auto msg: mErrors) {
        // ������д�����Ϣ 
        std::cout << msg.fileName << " " << msg.lineNum << " ��, " << msg.message << std::endl;
    }
}

bool ErrorMgr::checkEmpty() const {
    // ����Ƿ�û�г��ִ��� 
    return mErrors.size() == 0;
}

ErrorMgr::ErrorMgr() {
    // ʲôҲ���� 
}

void ErrorMgr::clear() {
    mErrors.clear(); // ��� vector 
}
