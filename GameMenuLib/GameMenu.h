#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "Chessboard.h"
#include "IMenu.h" // 所有的菜单都由 IMenu 派生而来 

const int TICK_LENGTH_MAX  = 600; 
const int TICK_LENGTH_STEP = 90;

class GameMenu: public IMenu {
public:
    GameMenu(); // 设置 mLastTickTime 
    GameMenu(const char* filename); // 从文件加载游戏 
    
    // 并不是很关心 Title 和 Terms，因为并不输出 
    // 从 IMenu 派生只是为了服用 show 和 process 接口 
    virtual void show() const;
    virtual void process();
    
    int getScore() const;
    void runTick(); // 尝试让游戏进行一个 tick 
    
    const Chessboard* getChessboard() const; // 获取当前的棋盘信息 
    Chessboard* getChessboard();
    void inActive();                         // 计时失活 
    
    static void setSpeed(int degree);
    void saveGameMenu() const; // 储存当前游戏状态 
    void setScore(int score);  // 设置游戏分数 
    
    virtual std::string getMenuType() const; // 计算目录类型 
    
private:
    // 从文件中读取数据, 向文件中写入数据 
    void outputToFile(const char* filename) const;
    void inputFromFile(const char* filename) const;
    
    static int tickLength; // 每一个 tick 的长度 
    
    int mLastTickTime;      // 上一个 tick 更新的时间 
    int mScore = 0;         // 新游戏，得分为零 
    Chessboard mChessboard; // 棋盘 
};

#endif

