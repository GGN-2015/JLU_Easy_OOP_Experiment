#ifndef VIEW_H
#define VIEW_H

class IMenu;
class MainMenu;
class SettingsMenu;
class Screen; // ��ʾ���� 
class Scroll;
class UnfinishedMenu;

const int MAX_HEIGHT = 24;
const int MAX_WIDTH  = 24;

class View { // ����������ʾ����������ֻ��һ�� Demo �� 
public:
    static void showIMenu(const IMenu*);                   // ��ʾһ��������ĳ���ҳ�� 
    static void showMainMenu(const MainMenu*);             // ��ʾ��ҳ�� 
    static void showSettngsMenu(const SettingsMenu*);      // ��ʾ����ҳ�� 
    static void showUnfinishedMenu(const UnfinishedMenu*); // ��ʾ��δ��ɵ�ҳ�� 
    
    static void showScroll(const char* scrollName, const Scroll*, bool); // ���һ������� 
    
    static Screen* getScreen(); // ��ȡ Screen ���� 
    
private:
    View() = delete;
    View(const View&) = delete;
    View& operator= (const View&) = delete; // ��ֹ���쿽����ֵ 
    
    static Screen mScreen;
};

#endif

