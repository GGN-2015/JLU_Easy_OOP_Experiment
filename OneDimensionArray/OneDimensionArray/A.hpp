//
//  A.hpp
//  OneDimensionArray
//
//  Created by 031 on 2021/11/17.
//  Copyright © 2021 NEKOSAN. All rights reserved.
//

#ifndef A_hpp
#define A_hpp

#include <iostream>

class A {
public:
    A(int n);
    int Data() const;
    
    friend std::ostream& operator<< (std::ostream& out, const A& aObj);
    
private:
    int data;
};

#endif /* A_hpp */
