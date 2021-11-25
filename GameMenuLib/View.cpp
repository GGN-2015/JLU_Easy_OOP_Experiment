// 现在只是一个原型版本，将来一定会更改输出方式 

#include <iostream>
#include <cstdlib>

#include "IMenu.h"
#include "MainMenu.h"
#include "Scroll.h"
#include "SettingsMenu.h"
#include "View.h"

void View::showIMenu(const IMenu* imenu) {
    system("cls");
    std::cout << "+----------------------------------------+" << std::endl << std::endl;
    std::cout << "  " << imenu -> getTitle() << std::endl << std::endl; // 输出标题 
    
    for(int id = 0; id < imenu -> getTermsCount(); id ++) {
        if(id == imenu -> getActiveTermId()) { // 当前被选中的项 
            std::cout << " => " << imenu -> getTerms()[id] << std::endl;
        }else { // 当前没有被选中的项 
            std::cout << "    " << imenu -> getTerms()[id] << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "+----------------------------------------+" << std::endl << std::endl;
}

void View::showMainMenu(const MainMenu* mainMenu) {
    showIMenu(mainMenu); // 目前暂时采用相同的方式进行输出，以后可能会更改 
    std::cout << "  Use 'w/s' to select term, use enter to confirm." << std::endl << std::endl;
}

void View::showSettngsMenu(const SettingsMenu* settingsMenu) {
    showIMenu(settingsMenu); // 目前暂时采用相同的方式进行输出，以后可能会更改 
    std::cout << "  Use 'w/s' to select term, use a/d to change the value." << std::endl << std::endl;
    View::showScroll("Volumn", settingsMenu -> getVolumnScroll());
    View::showScroll("Resolution", settingsMenu -> getResolutionScroll());
}

void View::showScroll(const char* scrollName, const Scroll* scroll) {
    // Scroll [===================>] 输出一个水平卷滚条 
    
    const int SCROLL_LENGTH = 20;              // 水平卷滚条的最大长度 
    std::cout << "  * " << scrollName << "\t"; // 输出水平卷滚条的名字 
    std::cout << "[";
    for(int i = 1; i <= SCROLL_LENGTH; i ++) {
        double rateNow = double(i)/SCROLL_LENGTH;
        double rateNxt = double(i+1)/SCROLL_LENGTH;
        if(i == 1 && scroll -> getRate() == 0) {
            std::cout << ">";
        }else {
            if(rateNow > scroll -> getRate()) {
                std::cout << " "; // 空格 
            }else {
                if(rateNxt > scroll -> getRate()) { // 最后一个位置用 '>' 
                    std::cout << ">";
                }else {
                    std::cout << "=";
                }
            }
        }
    }
    std::cout << "]" << std::endl << std::endl;
}

