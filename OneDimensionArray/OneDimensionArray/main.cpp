//
//  main.cpp
//  OneDimensionArray
//
//  Created by 031 on 2021/11/17.
//  Copyright © 2021 NEKOSAN. All rights reserved.
//

#include <iostream>
#include "A.hpp"

void g(int n) {
    // create arr
    A** arr = new A*[n];
    for(int i = 0; i < n; i ++) {
        arr[i] = new A(i + 1); // create the A obj
    }
    
    // use the value of A arr[]
    for(int i = 0; i < n; i ++) {
        std::cout << *arr[i] << "\t"; // output the values
    }
    std::cout << std::endl;
    
    // free arr
    for(int i = 0; i < n; i ++) {
        delete arr[i];
    }
    delete[] arr;
}

int main(int argc, const char * argv[]) {
    g(6);
    return 0;
}
