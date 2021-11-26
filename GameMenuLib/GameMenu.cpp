#include <ctime>
#include <iostream>

#include "Controller.h"
#include "GameMenu.h"
#include "View.h"

int GameMenu::tickLength = 600; // 600 ms

GameMenu::GameMenu() {
    mLastTickTime = clock(); // 上一个 tick 更新的时间 
}

void GameMenu::show() const {
    View::showGameMenu(this); // 委托给 View 
}

void GameMenu::process() {
    Controller::processGameMenu(this); // 委托给 Controller 
}

int GameMenu::getScore() const {
    return mScore;
}

void GameMenu::runTick() { // 试图运行一个 tick 
    if(mLastTickTime < 0) {
        mLastTickTime = clock();
    }else {
        if(clock() - mLastTickTime >= tickLength) {
            mScore += mChessboard.moveDown(); // 让游戏进行一个 tick 
            mLastTickTime = clock();
            // 开始一个新的 Tick 
        }
    }
}

const Chessboard* GameMenu::getChessboard() const {
    return &mChessboard;
}

Chessboard* GameMenu::getChessboard() {
    return &mChessboard; // 为了 process 使用 
}

