//
//  Crypter.cpp
//  Crypter
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#include "Crypter.hpp"
#include "TRand.hpp"

//void Coder(char* data, int len, int key) {
//    TRand trand(key);
//    for(int i = 0; i < len; i ++) {
//        data[i] ^= (char)trand.getInteger(-128, 127);
//    }
//}
//
//void Coder(char* data, int len, TRand& trand, int key) {
//    // if we change "TRand&" into "const TRand&" it can not go through compiling
//    // if we change "TRand&" into "TRand", the program is ok to work
//    trand.setSeed(key);
//    for(int i = 0; i < len; i ++) {
//        data[i] ^= (char)trand.getInteger(-128, 127);
//    }
//}

void Crypter::encode(char* str, int len) { // encode a string
    TRand trand(this -> mKey);
    for(int i = 0; i < len; i ++) {
        str[i] ^= (char)trand.getInteger(-128, 127);
    }
}
