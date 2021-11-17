//
//  MyString.hpp
//  MyString
//
//  Created by 031 on 2021/11/17.
//  Copyright © 2021 NEKOSAN. All rights reserved.
//

#ifndef MyString_hpp
#define MyString_hpp

#include <iostream>

class MyString {
public:
    MyString(const char* pData = nullptr);
    MyString(const MyString& mystr);
    ~MyString();
    
    MyString& operator= (const MyString& rhs);
    MyString& operator+= (const MyString& rhs);
    
    operator char* () const;
    
    friend std::ostream& operator<< (std::ostream& out, const MyString& mystr);
    friend MyString operator+ (const MyString& lhs, const MyString& rhs);
private:
    int strlen(const char* str);
    
    char* mData;
};

#endif /* MyString_hpp */
