//
//  main.cpp
//  Card
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#include <iostream>
#include "Card.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    Card cardA(43, 10, 10);
    Card cardB(cardA); // copy constructor
    
    // Card cardB = cardA; // <= not ok, it is regarded as implicit construct
    return 0;
}
