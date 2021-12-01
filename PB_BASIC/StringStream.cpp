#include <assert.h>
#include <iostream>
#include <string>

#include "StringStream.h"

StringStream::StringStream(std::string str) {
    mString = str;
    mIndex  = 0;
}

bool StringStream::empty() const {
    return mIndex == mString.length(); // ָ�����ַ���ĩβ�Ŀ��ַ� 
}

char StringStream::front() const {
    if(empty()) return 0; // ���Ϊ�շ��ؿ��ַ� 0 
    return mString[mIndex];
}

void StringStream::popFront() {
    if(!empty()) {
        mIndex ++; // ���ԶԿ����е� popFront ���� 
    }
}

void StringStream::withdraw(int cnt) {
    assert(cnt >= 0);       // ������ cnt < 0 
    
    mIndex -= cnt;
    assert(mIndex >= 0); // ����Ѿ���ԭΪ�����״̬���Ǿ�ʲô���������� 
}

int StringStream::size() const {
    return mString.length() - mIndex; // ����ʣ���ַ����� 
}

std::string StringStream::front(int len) {
    assert(len >= 0);      // Ҫ������õ����ַ������Ȳ���Ϊ���� 
    assert(size() >= len); // ʣ��ĳ��ȱ��빻�ò��� 
    
    std::string ans = "";
    int nlen = len;        // ��¼֮ǰ�ĳ��� 
    
    while(len --) {
        ans += front();
        popFront();
    }
    
    withdraw(nlen);        // ��Ҫ��İ��ⲿ�ֵ�ֵ��ȡ���� 
    return ans;
}

int StringStream::position() const {
    return mIndex;
}

