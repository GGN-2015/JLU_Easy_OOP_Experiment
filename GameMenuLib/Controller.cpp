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
                MenuMgr::getInstance().pushMenuStack(new GameMenu);
                //std::cout << "Here!" << std::endl;
                //system("pause");
                break;
            case MainMenu::SaveLoad: // ��ȡ�浵 
                MenuMgr::getInstance().pushMenuStack(new UnfinishedMenu("Save/Load"));
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

void Controller::processUnfinishedMenu(UnfinishedMenu* unfinishedMenu) {
    Event event;                        // ��ȡ��ǰ�������¼� 
    event.operateIMenu(unfinishedMenu); // �����¼��� unfinishedMenu ���е�������ʱʹ�� IMenu �ķ��� 
    
    if(event.isConfirm()) {
        MenuMgr::getInstance().popMenuStack(); // �˳���ǰҳ�� 
    }
}

void Controller::processGameMenu(GameMenu* gameMenu) {
    gameMenu -> runTick();           // ��ͼ����һ�� tick 
    Event event;                     // ��ȡ��ǰ�������¼� 
    event.operateGameMenu(gameMenu); // �����¼��� gameMenu ���е�������ʱʹ�� IMenu �ķ��� 
    
    if(event.isEsc()) { // �� ESC ��ͣ 
        // TODO: �˴�Ӧ�ò�����ͣҳ�� 
        // MenuMgr::getInstance().pushMenuStack(new UnfinishedMenu);
        MenuMgr::getInstance().pushMenuStack(new PauseMenu);
    }
}

void Controller::processPauseMenu(PauseMenu* pauseMenu) {
    Event event;                   // ��ȡ��ǰ�������¼� 
    event.operateIMenu(pauseMenu); // �����¼��� mainMenu ���е�������ʱʹ�� IMenu �ķ��� 
    
    if(event.isLeft()) {
        pauseMenu -> leftMoveActive(); // �ٶȵ��� 
    }
    if(event.isRight()) {
        pauseMenu -> rightMoveActive(); // �ٶȵ��� 
    }
    if(event.isConfirm()) {
        if(pauseMenu -> getActiveTermId() == PauseMenu::Resume) {
            MenuMgr::getInstance().popMenuStack(); // �ص��ϼ��˵� 
        }else
        if(pauseMenu -> getActiveTermId() == PauseMenu::Quit) {
            MenuMgr::getInstance().popMenuStack(); // �ص����˵� 
            MenuMgr::getInstance().popMenuStack(); // ��ջ���� 
        }else
        if(pauseMenu -> getActiveTermId() == PauseMenu::Save) {
            // TODO: ���湦���� S - L ���� 
            MenuMgr::getInstance().pushMenuStack(new UnfinishedMenu("Save"));
        }
    }
}

void Controller::lostGame(int finalScore) {
    // ��Ϸʧ�� 
    MenuMgr::getInstance().pushMenuStack(new UnfinishedMenu("GameLostMenu"));
}
