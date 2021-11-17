//
//  main.cpp
//  SingleInstance
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#include <iostream>
#include "Demo.hpp"

int main(int argc, const char * argv[]) {
    Demo& demo = Demo::getInstance();
    
    demo.addValue(100).showValue();
    demo.addValue(200).showValue();
    
    // Demo* pdemo = new Demo(demo); // this is not avaible
    return 0;
}
