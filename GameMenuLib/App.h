#ifndef APP_H
#define APP_H

#include <string>
#include <vector>

class GameMenu;

class App {
public:
    App();
    
    void initialize(); // ��ʼ�� 
    void run();        // ���� 
    void terminate();  // ��ֹ���� 
    
    bool checkResource(); // ���������е���Դ�ļ��Ƿ���ȱʧ 
    bool checkVersion();  // �����������ļ��İ汾�� exe �ļ��İ汾�Ƿ���� 
    void saveData();      // ������д���ļ� 
    
    static int getVersion(); // ��ȡ exe �İ汾����Ϣ 
    
    static void saveGameMenu(const GameMenu*); // ����������Ϣ 
    static std::string getDateTime();    // ��ȡϵͳʱ�� 
    static void loadGameMenu(std::string, GameMenu*); // ������Ϸ���� 
    
    static const std::vector<std::string>& getAboutMessage(); // ��ù�����Ϣ 
    
private:
    static const int mVersion; // ��¼��ǰ�汾 
    
    App(const App&) = delete;
    App& operator= (const App&) = delete; // ��ֹ�����͸�ֵ 
};

#endif

