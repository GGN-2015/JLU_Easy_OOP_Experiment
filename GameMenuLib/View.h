#ifndef VIEW_H
#define VIEW_H

class IMenu;
class MainMenu;
class SettingsMenu;
class Scroll; 

class View { // ����������ʾ����������ֻ��һ�� Demo �� 
public:
    static void showIMenu(const IMenu*);              // ��ʾһ��������ĳ���ҳ�� 
    static void showMainMenu(const MainMenu*);        // ��ʾ��ҳ�� 
    static void showSettngsMenu(const SettingsMenu*); // ��ʾ����ҳ�� 
    
    static void showScroll(const char* scrollName, const Scroll*); // ���һ������� 
    
private:
    View() = delete;
    View(const View&) = delete;
    View& operator= (const View&) = delete; // ��ֹ���쿽����ֵ 
};

#endif

