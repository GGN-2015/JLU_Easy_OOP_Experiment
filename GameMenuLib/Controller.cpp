#include <cstdlib>
#include <iostream>

#include "Controller.h"
#include "Event.h"
#include "IMenu.h"
#include "MainMenu.h"
#include "MenuMgr.h"
#include "SettingsMenu.h"

void Controller::processIMenu(IMenu* imenu) { // ���� imenu �������¼� 
    Event event;               // ��ȡ��ǰ�������¼� 
    event.operateIMenu(imenu); // ���ݵ�ǰ�¼��� imenu ���е��� 
    
    if(event.isConfirm()) { // isConfirm  :��ȷ���¼� 
        int id = imenu -> getActiveTermId();
        std::cout << "Term(" << id << ") is Choosen." << std::endl;
        system("pause");
    }
}

void Controller::processMainMenu(MainMenu* mainMenu) { // ���� imenu �������¼� 
    Event event;                  // ��ȡ��ǰ�������¼� 
    event.operateIMenu(mainMenu); // �����¼��� mainMenu ���е�������ʱʹ�� IMenu �ķ��� 
    
    if(event.isConfirm()) {
        int id = mainMenu -> getActiveTermId();
        switch(id) {
            case MainMenu::NewGame:
                std::cout << "Todo: NewGame" << std::endl;
                system("pause");
                break;
            case MainMenu::SaveLoad: // ��ȡ�浵 
                std::cout << "Todo: SaveLoad" << std::endl;
                system("pause");
                break;
            case MainMenu::Settings: // �������� 
                MenuMgr::getInstance().pushMenuStack(new SettingsMenu); // ����ҳ���ջ 
                break;
            case MainMenu::Quit:     // �˳���Ϸ 
                MenuMgr::getInstance().popMenuStack();
                break; // ��Ҫʹ�� cstdlib �е� exit ����ֱ���˳�����, ���ܻ��ڴ�й© 
        }
    }
}

void Controller::processSettingsMenu(SettingsMenu* settingsMenu) {
    Event event;                      // ��ȡ��ǰ�������¼� 
    event.operateIMenu(settingsMenu); // �����¼��� mainMenu ���е�������ʱʹ�� IMenu �ķ��� 
    
    if(event.isLeft()) {
        settingsMenu -> leftMoveActive(); // ����/�ֱ��ʵ��� 
    }
    if(event.isRight()) {
        settingsMenu -> rightMoveActive(); // ����/�ֱ��ʵ��� 
    }
    if(event.isConfirm() && settingsMenu -> getActiveTermId() == SettingsMenu::Back) {
        MenuMgr::getInstance().popMenuStack(); // �ص����˵����ϼ��˵� 
    }
}

