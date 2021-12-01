#include <assert.h>
#include <iostream>
#include <string>

#include "StringStream.h"

StringStream::StringStream(std::string str) {
    mString = str;
    mIndex  = 0;
}

bool StringStream::empty() const {
    return mIndex == mString.length(); // 指向了字符串末尾的空字符 
}

char StringStream::front() const {
    if(empty()) return 0; // 如果为空返回空字符 0 
    return mString[mIndex];
}

void StringStream::popFront() {
    if(!empty()) {
        mIndex ++; // 忽略对空序列的 popFront 操作 
    }
}

void StringStream::withdraw(int cnt) {
    assert(cnt >= 0);       // 不允许 cnt < 0 
    
    mIndex -= cnt;
    assert(mIndex >= 0); // 如果已经还原为最初的状态，那就什么都不能做了 
}

int StringStream::size() const {
    return mString.length() - mIndex; // 计算剩余字符个数 
}

std::string StringStream::front(int len) {
    assert(len >= 0);      // 要求申请得到的字符串长度不能为负数 
    assert(size() >= len); // 剩余的长度必须够用才行 
    
    std::string ans = "";
    int nlen = len;        // 记录之前的长度 
    
    while(len --) {
        ans += front();
        popFront();
    }
    
    withdraw(nlen);        // 不要真的把这部分的值读取出来 
    return ans;
}

int StringStream::position() const {
    return mIndex;
}

