//
//  A.cpp
//  OneDimensionArray
//
//  Created by 031 on 2021/11/17.
//  Copyright © 2021 NEKOSAN. All rights reserved.
//

#include <iostream>
#include "A.hpp"

A::A(int n): data(n) {}

int A::Data() const {
    return data;
}

std::ostream& operator<< (std::ostream& out, const A& aObj) {
    out << aObj.data;
    return out;
}
