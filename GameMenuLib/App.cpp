#include <iostream>

#include "App.h" // App �������к��ļ���صĲ����Լ��������еĿ�� 
#include "Event.h"
#include "IMenu.h"
#include "MenuMgr.h"

std::string App::mVersion = "2021-11-25";

App::App() {
    // �����ڲ��� App ������֯���֣���ʱ��û��ʲô��Ҫ���� 
}

void App::initialize() {
    system("title Tetris");
    system("cls");
    std::cout << " * App::initialize() ... " << std::endl;
    bool resource = checkResource();
    bool version  = checkVersion ();
    if(!resource) { // �����ļ���ȫ 
        std::cout << "App::initialize(): resource damaged!" << std::endl;
    }
    if(!version) { // �汾�� 
        std::cout << "App::initialize(): version not match with resource!" << std::endl;
    }
    system("pause");
    system("cls");
    Event::inActivate(); // �ս��� App ʱ����ʧ�� 
}

void App::run() { // �������� App 
    while(true) {
        IMenu* imenu = MenuMgr::getInstance().getActiveMenu();
        if(imenu == nullptr) break;
        else {
            imenu -> show();    // ��ʾҳ����Ϣ 
            imenu -> process(); // ����ҳ���¼� 
        }
    }
}

void App::terminate() {
    system("cls");
    saveData(); // ������д���ļ� 
    // system("pause");
}

bool App::checkResource() { // ��������ļ��Ƿ����� 
    std::cout << " * checking resource ... \t";
    std::cout << "[OK]" << std::endl;
    return true;
}

bool App::checkVersion() { // ���汾��Ϣ�Ƿ�ƥ�� 
    std::cout << " * checking version ... \t";
    std::cout << "[OK]" << std::endl;
    return true;
}
void App::saveData() { // д�������ļ� 
    std::cout << " * saving Data ... \t";
    std::cout << "[OK]" << std::endl;
}

std::string App::getVersion() const {
    return mVersion;
}

