#ifndef VIEW_H
#define VIEW_H

class IMenu;
class MainMenu;
class SettingsMenu;
class Scroll; 

class View { // 负责所有显示工作，初期只是一个 Demo 版 
public:
    static void showIMenu(const IMenu*);              // 显示一个最基础的抽象页面 
    static void showMainMenu(const MainMenu*);        // 显示主页面 
    static void showSettngsMenu(const SettingsMenu*); // 显示设置页面 
    
    static void showScroll(const char* scrollName, const Scroll*); // 输出一个卷滚条 
    
private:
    View() = delete;
    View(const View&) = delete;
    View& operator= (const View&) = delete; // 禁止构造拷贝赋值 
};

#endif

