//
//  Quotient.cpp
//  Quotient
//
//  Created by 031 on 2021/11/17.
//  Copyright © 2021 NEKOSAN. All rights reserved.
//

#include "Quotient.hpp"


Quotient::Quotient(double val, int dep) {
    mVal = int(val);
    if(dep - 1 >= 0) { // build next quotient
        nextQuotient = new Quotient(1.0/(val - mVal), dep - 1);
    }else {
        nextQuotient = nullptr;
    }
}

Quotient::~Quotient() {
    if(nextQuotient != nullptr) { // delete the whole quotient recursively
        delete nextQuotient;
    }
}

std::ostream& operator<< (std::ostream& out, const Quotient& quotient) { // output 
    out << quotient.mVal;
    if(quotient.nextQuotient != nullptr) {
        out << "+";
        out << *(quotient.nextQuotient);
    }
    return out;
}
