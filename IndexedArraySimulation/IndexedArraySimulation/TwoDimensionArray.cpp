//
//  TwoDimensionArray.cpp
//  IndexedArraySimulation
//
//  Created by 031 on 2021/11/17.
//  Copyright © 2021 NEKOSAN. All rights reserved.
//

#include "OneDimensionArray.hpp"
#include "TwoDimensionArray.hpp"

TwoDimensionArray::TwoDimensionArray(int n, int m): sizN(n) {
    subArrays = new OneDimensionArray*[n];
    for(int i = 0; i < n; i ++) {
        subArrays[i] = new OneDimensionArray(m);
    }
}

TwoDimensionArray::~TwoDimensionArray() {
    for(int i = 0; i < sizN; i ++) {
        delete subArrays[i];
    }
    delete[] subArrays; // free all
}

OneDimensionArray& TwoDimensionArray::operator[] (int index) {
    if(0 <= index && index < sizN) {
        return *subArrays[index];
    }else {
        throw "TwoDimensionArray::operator[]: index out of range";
    }
}

const OneDimensionArray& TwoDimensionArray::operator[] (int index) const {
    if(0 <= index && index < sizN) {
        return *subArrays[index];
    }else {
        throw "TwoDimensionArray::operator[] const: index out of range";
    }
}
