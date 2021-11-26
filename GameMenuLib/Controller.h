#ifndef CONTROLLER_H
#define CONTROLLER_H

class IMenu;
class GameMenu;
class MainMenu;
class SettingsMenu;
class UnfinishedMenu;

class Controller {
public:
    static void processIMenu(IMenu*);                   // ����һ�� IMenu �������¼� 
    static void processMainMenu(MainMenu*);             // ����һ�� MainMenu �������¼� 
    static void processSettingsMenu(SettingsMenu*);     // ����һ�� SettingsMenu �������¼� 
    static void processUnfinishedMenu(UnfinishedMenu*); // ����һ�� UnfinishedMenu �������¼� 
    static void processGameMenu(GameMenu*);             // ����һ�� GameMenu �������¼� 

private:
    Controller() = delete;
    Controller(const Controller&) = delete;
    Controller& operator= (const Controller&) = delete; // ��ֹ���쿽����ֵ 
};

#endif

