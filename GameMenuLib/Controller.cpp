#include <cstdlib>
#include <iostream>

#include "Controller.h"
#include "Event.h"
#include "IMenu.h"
#include "MainMenu.h"
#include "MenuMgr.h"
#include "SettingsMenu.h"

void Controller::processIMenu(IMenu* imenu) { // 处理 imenu 的输入事件 
    Event event;               // 获取当前的所有事件 
    event.operateIMenu(imenu); // 根据当前事件对 imenu 进行调整 
    
    if(event.isConfirm()) { // isConfirm  :是确认事件 
        int id = imenu -> getActiveTermId();
        std::cout << "Term(" << id << ") is Choosen." << std::endl;
        system("pause");
    }
}

void Controller::processMainMenu(MainMenu* mainMenu) { // 处理 imenu 的输入事件 
    Event event;                  // 获取当前的所有事件 
    event.operateIMenu(mainMenu); // 根据事件对 mainMenu 进行调整，暂时使用 IMenu 的方法 
    
    if(event.isConfirm()) {
        int id = mainMenu -> getActiveTermId();
        switch(id) {
            case MainMenu::NewGame:
                std::cout << "Todo: NewGame" << std::endl;
                system("pause");
                break;
            case MainMenu::SaveLoad: // 读取存档 
                std::cout << "Todo: SaveLoad" << std::endl;
                system("pause");
                break;
            case MainMenu::Settings: // 进行设置 
                MenuMgr::getInstance().pushMenuStack(new SettingsMenu); // 设置页面进栈 
                break;
            case MainMenu::Quit:     // 退出游戏 
                MenuMgr::getInstance().popMenuStack();
                break; // 不要使用 cstdlib 中的 exit 函数直接退出程序, 可能会内存泄漏 
        }
    }
}

void Controller::processSettingsMenu(SettingsMenu* settingsMenu) {
    Event event;                      // 获取当前的所有事件 
    event.operateIMenu(settingsMenu); // 根据事件对 mainMenu 进行调整，暂时使用 IMenu 的方法 
    
    if(event.isLeft()) {
        settingsMenu -> leftMoveActive(); // 音量/分辨率调低 
    }
    if(event.isRight()) {
        settingsMenu -> rightMoveActive(); // 音量/分辨率调高 
    }
    if(event.isConfirm() && settingsMenu -> getActiveTermId() == SettingsMenu::Back) {
        MenuMgr::getInstance().popMenuStack(); // 回到主菜单或上级菜单 
    }
}

