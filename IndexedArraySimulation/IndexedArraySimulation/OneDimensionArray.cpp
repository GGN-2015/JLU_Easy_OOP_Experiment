//
//  OneDimensionArray.cpp
//  IndexedArraySimulation
//
//  Created by 031 on 2021/11/17.
//  Copyright © 2021 NEKOSAN. All rights reserved.
//

#include "OneDimensionArray.hpp"

OneDimensionArray::OneDimensionArray(int n) {
    sizN = n;
    arr = new int[n];
    for(int i = 0; i < n; i ++) { // init to zero
        arr[i] = 0;
    }
}

OneDimensionArray::~OneDimensionArray() {
    delete[] arr;
}

int& OneDimensionArray::operator[] (int index) {
    if(0 <= index && index < sizN) {
        return arr[index];
    }else {
        throw "Index out of range";
    }
}

int OneDimensionArray::operator[] (int index) const {
    if(0 <= index && index < sizN) {
        return arr[index];
    }else {
        throw "Index out of range";
    }
}
