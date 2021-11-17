//
//  TwoDimensionArray.hpp
//  IndexedArraySimulation
//
//  Created by 031 on 2021/11/17.
//  Copyright © 2021 NEKOSAN. All rights reserved.
//

#ifndef TwoDimensionArray_hpp
#define TwoDimensionArray_hpp

class OneDimensionArray;
class TwoDimensionArray {
public:
    TwoDimensionArray(int n, int m); // create a N * M array
    ~TwoDimensionArray();
    
    OneDimensionArray& operator[] (int index);
    const OneDimensionArray& operator[] (int index) const;
private:
    int sizN;
    OneDimensionArray** subArrays;
};

#endif /* TwoDimensionArray_hpp */
