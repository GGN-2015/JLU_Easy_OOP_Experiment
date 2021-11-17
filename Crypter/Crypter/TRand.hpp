//
//  TRand.hpp
//  Crypter
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#ifndef TRand_hpp
#define TRand_hpp

class TRand {
public:
    TRand(); // initialize with a random seed (system time)
    TRand(int seed);
    
    void setSeed(int newSeed);
    
    int getInteger();
    int getInteger(int minInt, int maxInt);
private:
    void nextVal();
    int mSeedNow;
};

#endif /* TRand_hpp */
