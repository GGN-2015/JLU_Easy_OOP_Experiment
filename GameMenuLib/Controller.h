#ifndef CONTROLLER_H
#define CONTROLLER_H

class IMenu;
class MainMenu;
class SettingsMenu;
class UnfinishedMenu;

class Controller {
public:
    static void processIMenu(IMenu*);                   // 处理一个 IMenu 的输入事件 
    static void processMainMenu(MainMenu*);             // 处理一个 MainMenu 的输入事件 
    static void processSettingsMenu(SettingsMenu*);     // 处理一个 SettingsMenu 的输入事件 
    static void processUnfinishedMenu(UnfinishedMenu*); // 处理一个 UnfinishedMenu 的输入事件 
    
private:
    Controller() = delete;
    Controller(const Controller&) = delete;
    Controller& operator= (const Controller&) = delete; // 禁止构造拷贝赋值 
};

#endif

