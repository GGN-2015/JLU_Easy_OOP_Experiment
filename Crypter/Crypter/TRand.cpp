//
//  TRand.cpp
//  Crypter
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#include <ctime>
#include <cstdlib>

#include "TRand.hpp"

TRand::TRand() {
    mSeedNow = (int)time(0);
}

TRand::TRand(int seed) {
    mSeedNow = seed;
}

void TRand::setSeed(int newSeed) {
    mSeedNow = newSeed;
}

void TRand::nextVal() {
    srand(mSeedNow);
    mSeedNow = rand();
}

int TRand::getInteger() {
    nextVal();
    return mSeedNow;
}

int TRand::getInteger(int minInt, int maxInt) {
    nextVal();
    return mSeedNow % (maxInt - minInt + 1) + minInt;
}
