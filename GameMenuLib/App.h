#ifndef APP_H
#define APP_H

#include <string>

class App {
public:
    App();
    
    void initialize(); // 初始化 
    void run();        // 运行 
    void terminate();  // 终止运行 
    
    bool checkResource(); // 检查程序运行的资源文件是否有缺失 
    bool checkVersion();  // 检查程序数据文件的版本与 exe 文件的版本是否兼容 
    void saveData();      // 将数据写回文件 
    
    std::string getVersion() const; // 获取 exe 的版本号信息 
    
private:
    static std::string mVersion; // 记录当前版本 
    
    App(const App&) = delete;
    App& operator= (const App&) = delete; // 禁止拷贝和赋值 
};

#endif

