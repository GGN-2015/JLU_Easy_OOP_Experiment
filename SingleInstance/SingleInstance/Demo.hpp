//
//  Demo.hpp
//  SingleInstance
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#ifndef Demo_hpp
#define Demo_hpp

#include <iostream>

class Demo {
public:
    static Demo& getInstance() {
        static Demo singleInstance;
        return singleInstance;
    }
    Demo& addValue(int value) {
        mNum += value;
        return *this;
    }
    void showValue() const {
        using std::cout;
        using std::endl;
        cout << "Value = " << mNum << endl;
    }
private:
    Demo() {
        mNum = 0;
    }
    
    Demo(const Demo&) = delete;
    Demo& operator= (const Demo&) = delete;
    
    int mNum;
};

#endif /* Demo_hpp */
