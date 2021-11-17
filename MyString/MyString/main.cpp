//
//  main.cpp
//  MyString
//
//  Created by 031 on 2021/11/17.
//  Copyright © 2021 NEKOSAN. All rights reserved.
//

#include <iostream>
#include "MyString.hpp"

int main(int argc, const char * argv[]) {
    using std::cin;
    using std::cout;
    using std::endl;
    
    MyString strA;
    MyString strB("B");
    MyString strC;
    strC = strA + strB;
    cout << strC << endl;
    return 0;
}
