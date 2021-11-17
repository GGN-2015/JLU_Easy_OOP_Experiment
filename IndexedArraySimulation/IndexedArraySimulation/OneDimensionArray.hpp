//
//  OneDimensionArray.hpp
//  IndexedArraySimulation
//
//  Created by 031 on 2021/11/17.
//  Copyright © 2021 NEKOSAN. All rights reserved.
//

#ifndef OneDimensionArray_hpp
#define OneDimensionArray_hpp

class OneDimensionArray {
public:
    OneDimensionArray(int n);
    ~OneDimensionArray();
    
    int& operator[] (int index);
    int operator[] (int index) const;
private:
    int sizN;
    int* arr;
};

#endif /* OneDimensionArray_hpp */
