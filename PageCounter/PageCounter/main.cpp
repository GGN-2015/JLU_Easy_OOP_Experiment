//
//  main.cpp
//  PageCounter
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#include <iostream>
#include "PageCounter.hpp"

int main(int argc, const char * argv[]) {
    PageCounter pageCounter(100);
    
    using std::cin;
    using std::cout;
    using std::endl;
    
    pageCounter.readToday(10).readToday(10);
    cout << pageCounter.getCovered() << "/" << pageCounter.getTotalPage() << endl;
    
    pageCounter.readToday(10);
    cout << pageCounter.getCovered() << "/" << pageCounter.getTotalPage() << endl;
    
    pageCounter.readToday(71);
    cout << pageCounter.getCovered() << "/" << pageCounter.getTotalPage() << endl;
    return 0;
}
