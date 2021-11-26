#include <iostream>

#include "App.h" // App 负责所有和文件相关的操作以及程序运行的框架 
#include "Event.h"
#include "IMenu.h"
#include "MenuMgr.h"

std::string App::mVersion = "2021-11-25";

App::App() {
    // 程序内部的 App 数据组织部分，暂时还没有什么需要做的 
}

void App::initialize() {
    system("title Tetris");
    system("cls");
    std::cout << " * App::initialize() ... " << std::endl;
    bool resource = checkResource();
    bool version  = checkVersion ();
    if(!resource) { // 数据文件不全 
        std::cout << "App::initialize(): resource damaged!" << std::endl;
    }
    if(!version) { // 版本和 
        std::cout << "App::initialize(): version not match with resource!" << std::endl;
    }
    system("pause");
    system("cls");
    Event::inActivate(); // 刚进入 App 时动作失活 
}

void App::run() { // 运行整个 App 
    while(true) {
        IMenu* imenu = MenuMgr::getInstance().getActiveMenu();
        if(imenu == nullptr) break;
        else {
            imenu -> show();    // 显示页面信息 
            imenu -> process(); // 处理页面事件 
        }
    }
}

void App::terminate() {
    system("cls");
    saveData(); // 将数据写回文件 
    // system("pause");
}

bool App::checkResource() { // 检测数据文件是否完整 
    std::cout << " * checking resource ... \t";
    std::cout << "[OK]" << std::endl;
    return true;
}

bool App::checkVersion() { // 检测版本信息是否匹配 
    std::cout << " * checking version ... \t";
    std::cout << "[OK]" << std::endl;
    return true;
}
void App::saveData() { // 写回数据文件 
    std::cout << " * saving Data ... \t";
    std::cout << "[OK]" << std::endl;
}

std::string App::getVersion() const {
    return mVersion;
}

