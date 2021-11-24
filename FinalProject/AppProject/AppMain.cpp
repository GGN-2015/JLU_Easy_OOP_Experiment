// AppMain.cpp

#define DEBUG_MODE // use this when you are debugging your main program

#ifdef DEBUG_MODE
    #include <cstdlib>
    #include <iostream>
    #include <string>
#endif // DEBUG_MODE

#include "ConsoleMgr.h"
#include "ViewMgr.h"
#include "IMenu.h"

ViewMgr& viewMgr = ViewMgr::getInstance();

int main() {
    #ifdef DEBUG_MODE
        std::cout << "AppMain.cpp: main()" << std::endl;
        // std::string stmp;
        // std::cin >> stmp; // input a string and output the ASCII
        // std::cout << "ASCII: ";
        // for(int i = 0; i < (int)stmp.length(); i ++) {
        //     std::cout << (int)stmp[i] << " ";
        // }
        // std::cout << std::endl;
        system("pause");
    #endif // DEBUG_MODE

    viewMgr.drawBox({0, 0, 10, 20});
    viewMgr.updateScreen();
    viewMgr.changeTitle("gobang");
    system("pause");
    return 0;
}
