//
//  main.cpp
//  IndexedArraySimulation
//
//  Created by 031 on 2021/11/17.
//  Copyright © 2021 NEKOSAN. All rights reserved.
//

#include <iostream>
#include "OneDimensionArray.hpp"
#include "TwoDimensionArray.hpp"

int main(int argc, const char * argv[]) {
    const int n = 5, m = 7;
    TwoDimensionArray tda(n, m);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            tda[i][j] = i * m + j + 1;
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            std::cout << tda[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
