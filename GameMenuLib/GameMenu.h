#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "Chessboard.h"
#include "IMenu.h" // ���еĲ˵����� IMenu �������� 

const int TICK_LENGTH_MAX  = 600; 
const int TICK_LENGTH_STEP = 90;

class GameMenu: public IMenu {
public:
    GameMenu(); // ���� mLastTickTime 
    GameMenu(const char* filename); // ���ļ�������Ϸ 
    
    // �����Ǻܹ��� Title �� Terms����Ϊ������� 
    // �� IMenu ����ֻ��Ϊ�˷��� show �� process �ӿ� 
    virtual void show() const;
    virtual void process();
    
    int getScore() const;
    void runTick(); // ��������Ϸ����һ�� tick 
    
    const Chessboard* getChessboard() const; // ��ȡ��ǰ��������Ϣ 
    Chessboard* getChessboard();
    void inActive();                         // ��ʱʧ�� 
    
    static void setSpeed(int degree);
    void saveGameMenu() const; // ���浱ǰ��Ϸ״̬ 
    void setScore(int score);  // ������Ϸ���� 
    
    virtual std::string getMenuType() const; // ����Ŀ¼���� 
    
private:
    // ���ļ��ж�ȡ����, ���ļ���д������ 
    void outputToFile(const char* filename) const;
    void inputFromFile(const char* filename) const;
    
    static int tickLength; // ÿһ�� tick �ĳ��� 
    
    int mLastTickTime;      // ��һ�� tick ���µ�ʱ�� 
    int mScore = 0;         // ����Ϸ���÷�Ϊ�� 
    Chessboard mChessboard; // ���� 
};

#endif

