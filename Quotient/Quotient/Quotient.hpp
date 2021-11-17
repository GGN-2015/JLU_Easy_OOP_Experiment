//
//  Quotient.hpp
//  Quotient
//
//  Created by 031 on 2021/11/17.
//  Copyright © 2021 NEKOSAN. All rights reserved.
//

#ifndef Quotient_hpp
#define Quotient_hpp

#include <iostream>
const int MAXLEN = 30; // the max length of a quotient

class Quotient {
public:
    Quotient(double val, int dep = MAXLEN - 1);
    ~Quotient();
    
    friend std::ostream& operator<< (std::ostream& out, const Quotient& quotient);
    
private:
    int mVal, mDep; // depth = 0 to MAXLEN - 1
    Quotient* nextQuotient;
};

#endif /* Quotient_hpp */
