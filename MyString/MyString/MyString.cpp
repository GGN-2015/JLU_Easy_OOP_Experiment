//
//  MyString.cpp
//  MyString
//
//  Created by 031 on 2021/11/17.
//  Copyright © 2021 NEKOSAN. All rights reserved.
//

#include <algorithm>

#include "MyString.hpp"

MyString::MyString(const char* pData) {
    if(pData == nullptr) {
        mData = nullptr;
    }else {
        int len = strlen(pData);
        mData = new char[len + 1];
        for(int i = 0; i <= len; i ++) {
            mData[i] = pData[i];
        }
    }
}

MyString::MyString(const MyString& mystr){
    delete[] this -> mData; // free old memory
    if(mystr.mData == nullptr) {
        this -> mData = nullptr;
    }else {
        int len = strlen(mystr.mData);
        this -> mData = new char[len + 1]; // create new memory
        for(int i = 0; i <= len; i ++) {
            this -> mData[i] = mystr.mData[i];
        }
    }
}

MyString::~MyString() {
    delete[] this -> mData;
}

MyString& MyString::operator= (const MyString& rhs) {
    if(this != &rhs) {
        delete[] this -> mData; // free old memory
        if(rhs.mData == nullptr) {
            this -> mData = nullptr;
        }else {
            int len = (int)strlen(rhs.mData);
            this -> mData = new char[len + 1]; // create new memory
            for(int i = 0; i <= len; i ++) {
                this -> mData[i] = rhs.mData[i];
            }
        }
    }
    return *this;
}

MyString& MyString::operator+= (const MyString& rhs) {
    MyString strTmp(nullptr);
    int len = strlen(this -> mData) + strlen(rhs.mData); // get the total length of the new string
    if(len == 0) {
        std::swap(strTmp.mData, this -> mData); // return the value of the new string
        return *this;
    }
    strTmp.mData = new char[len + 1];
    int cnt = 0;
    if(this -> mData != nullptr) {
        for(int i = 0; this -> mData[i] != 0; i ++) {
            strTmp.mData[cnt ++] = this -> mData[i];
        }
    }
    if(rhs.mData != nullptr) {
        for(int i = 0; rhs.mData[i] != 0; i ++) {
            strTmp.mData[cnt ++] = rhs.mData[i];
        }
    }
    strTmp.mData[cnt ++] = '\0';
    std::swap(strTmp.mData, this -> mData); // return the value of the new string
    return *this;
}

MyString::operator char* () const { // just return the pointer
    return this -> mData;
}

std::ostream& operator<< (std::ostream& out, const MyString& mystr) {
    for(int i = 0; mystr.mData[i] != 0; i ++) {
        out << mystr.mData[i]; // output a single char
    }
    return out;
}

MyString operator+ (const MyString& lhs, const MyString& rhs) {
    MyString strTmp; // empty string
    strTmp += lhs;
    strTmp += rhs;
    return strTmp;
}

int MyString::strlen(const char* str) { // my own strlen
    if(str == nullptr) return 0;
    int cnt = 0;
    for(int i = 0; str[i] != 0; i ++) {
        cnt ++;
    }
    return cnt;
}
