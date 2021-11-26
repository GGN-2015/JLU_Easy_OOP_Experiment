#include <cstdlib>
#include <iostream>

#include "Controller.h"
#include "Event.h"
#include "GameMenu.h"
#include "IMenu.h"
#include "MainMenu.h"
#include "MenuMgr.h"
#include "PauseMenu.h"
#include "SettingsMenu.h"
#include "UnfinishedMenu.h"

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
                MenuMgr::getInstance().pushMenuStack(new GameMenu);
                //std::cout << "Here!" << std::endl;
                //system("pause");
                break;
            case MainMenu::SaveLoad: // 读取存档 
                MenuMgr::getInstance().pushMenuStack(new UnfinishedMenu("Save/Load"));
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

void Controller::processUnfinishedMenu(UnfinishedMenu* unfinishedMenu) {
    Event event;                        // 获取当前的所有事件 
    event.operateIMenu(unfinishedMenu); // 根据事件对 unfinishedMenu 进行调整，暂时使用 IMenu 的方法 
    
    if(event.isConfirm()) {
        MenuMgr::getInstance().popMenuStack(); // 退出当前页面 
    }
}

void Controller::processGameMenu(GameMenu* gameMenu) {
    gameMenu -> runTick();           // 试图运行一个 tick 
    Event event;                     // 获取当前的所有事件 
    event.operateGameMenu(gameMenu); // 根据事件对 gameMenu 进行调整，暂时使用 IMenu 的方法 
    
    if(event.isEsc()) { // 按 ESC 暂停 
        // TODO: 此处应该插入暂停页面 
        // MenuMgr::getInstance().pushMenuStack(new UnfinishedMenu);
        MenuMgr::getInstance().pushMenuStack(new PauseMenu);
    }
}

void Controller::processPauseMenu(PauseMenu* pauseMenu) {
    Event event;                   // 获取当前的所有事件 
    event.operateIMenu(pauseMenu); // 根据事件对 mainMenu 进行调整，暂时使用 IMenu 的方法 
    
    if(event.isLeft()) {
        pauseMenu -> leftMoveActive(); // 速度调低 
    }
    if(event.isRight()) {
        pauseMenu -> rightMoveActive(); // 速度调高 
    }
    if(event.isConfirm()) {
        if(pauseMenu -> getActiveTermId() == PauseMenu::Resume) {
            MenuMgr::getInstance().popMenuStack(); // 回到上级菜单 
        }else
        if(pauseMenu -> getActiveTermId() == PauseMenu::Quit) {
            MenuMgr::getInstance().popMenuStack(); // 回到主菜单 
            MenuMgr::getInstance().popMenuStack(); // 弹栈两次 
        }else
        if(pauseMenu -> getActiveTermId() == PauseMenu::Save) {
            // TODO: 保存功能与 S - L 界面 
            MenuMgr::getInstance().pushMenuStack(new UnfinishedMenu("Save"));
        }
    }
}

void Controller::lostGame(int finalScore) {
    // 游戏失败 
    MenuMgr::getInstance().pushMenuStack(new UnfinishedMenu("GameLostMenu"));
}
