//
//  Crypter.hpp
//  Crypter
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#ifndef Crypter_hpp
#define Crypter_hpp

#include "TRand.hpp"

// void Coder(char* data, int len, int key); // prototype of Coder
// void Coder(char* data, int len, TRand& rand, int key);

class Crypter {
public:
    Crypter(int key):mKey(key) {} // just get the key
    void encode(char* str, int len);
    // void decode(char* str, int len); // decode is the same with encode
private:
    int mKey;
};

#endif /* Crypter_hpp */
