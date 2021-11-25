// ����ֻ��һ��ԭ�Ͱ汾������һ������������ʽ 

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
    std::cout << "  " << imenu -> getTitle() << std::endl << std::endl; // ������� 
    
    for(int id = 0; id < imenu -> getTermsCount(); id ++) {
        if(id == imenu -> getActiveTermId()) { // ��ǰ��ѡ�е��� 
            std::cout << " => " << imenu -> getTerms()[id] << std::endl;
        }else { // ��ǰû�б�ѡ�е��� 
            std::cout << "    " << imenu -> getTerms()[id] << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "+----------------------------------------+" << std::endl << std::endl;
}

void View::showMainMenu(const MainMenu* mainMenu) {
    showIMenu(mainMenu); // Ŀǰ��ʱ������ͬ�ķ�ʽ����������Ժ���ܻ���� 
    std::cout << "  Use 'w/s' to select term, use enter to confirm." << std::endl << std::endl;
}

void View::showSettngsMenu(const SettingsMenu* settingsMenu) {
    showIMenu(settingsMenu); // Ŀǰ��ʱ������ͬ�ķ�ʽ����������Ժ���ܻ���� 
    std::cout << "  Use 'w/s' to select term, use a/d to change the value." << std::endl << std::endl;
    View::showScroll("Volumn", settingsMenu -> getVolumnScroll());
    View::showScroll("Resolution", settingsMenu -> getResolutionScroll());
}

void View::showScroll(const char* scrollName, const Scroll* scroll) {
    // Scroll [===================>] ���һ��ˮƽ����� 
    
    const int SCROLL_LENGTH = 20;              // ˮƽ���������󳤶� 
    std::cout << "  * " << scrollName << "\t"; // ���ˮƽ����������� 
    std::cout << "[";
    for(int i = 1; i <= SCROLL_LENGTH; i ++) {
        double rateNow = double(i)/SCROLL_LENGTH;
        double rateNxt = double(i+1)/SCROLL_LENGTH;
        if(i == 1 && scroll -> getRate() == 0) {
            std::cout << ">";
        }else {
            if(rateNow > scroll -> getRate()) {
                std::cout << " "; // �ո� 
            }else {
                if(rateNxt > scroll -> getRate()) { // ���һ��λ���� '>' 
                    std::cout << ">";
                }else {
                    std::cout << "=";
                }
            }
        }
    }
    std::cout << "]" << std::endl << std::endl;
}

