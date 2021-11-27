#ifndef APP_H
#define APP_H

#include <string>
#include <vector>

class GameMenu;

class App {
public:
    App();
    
    void initialize(); // 初始化 
    void run();        // 运行 
    void terminate();  // 终止运行 
    
    bool checkResource(); // 检查程序运行的资源文件是否有缺失 
    bool checkVersion();  // 检查程序数据文件的版本与 exe 文件的版本是否兼容 
    void saveData();      // 将数据写回文件 
    
    static int getVersion(); // 获取 exe 的版本号信息 
    
    static void saveGameMenu(const GameMenu*); // 储存棋盘信息 
    static std::string getDateTime();    // 获取系统时间 
    static void loadGameMenu(std::string, GameMenu*); // 加载游戏数据 
    
    static const std::vector<std::string>& getAboutMessage(); // 获得关于信息 
    
private:
    static const int mVersion; // 记录当前版本 
    
    App(const App&) = delete;
    App& operator= (const App&) = delete; // 禁止拷贝和赋值 
};

#endif

