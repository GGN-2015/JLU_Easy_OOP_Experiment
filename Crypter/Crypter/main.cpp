//
//  main.cpp
//  Crypter
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#include <iostream>
#include <cstring>

#include "TRand.hpp"
#include "Crypter.hpp"

static void outputData(const char* prompt, const char* str, int len) {
    using std::cout;
    using std::endl;
    cout << prompt;
    for(int i = 0; i < len; i ++) {
        cout << int((unsigned char)str[i]) << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    using std::cin;
    using std::cout;
    using std::endl;
    
    const int MAX_LEN = 1024;
    const int CRYPTO_KEY = 12345;
    
    Crypter crypter(CRYPTO_KEY);
    
    char str[MAX_LEN] = {};
    cout << "please input a string:";
    cin.getline(str, MAX_LEN); // input a string
    
    int len = (int)strlen(str);
    outputData("normal message:", str, len); // output the ascii of the string
    
    crypter.encode(str, len); // Code the string
    outputData("coded message:", str, len);
    
    crypter.encode(str, len); // decode the string
    outputData("decoded message:", str, len);
    
    cout << str << endl;
    
    return 0;
}
