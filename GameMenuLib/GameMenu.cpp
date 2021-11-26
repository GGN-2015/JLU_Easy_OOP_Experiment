#include <ctime>
#include <iostream>

#include "Controller.h"
#include "GameMenu.h"
#include "View.h"

int GameMenu::tickLength = 600; // 600 ms

GameMenu::GameMenu() {
    mLastTickTime = clock(); // ��һ�� tick ���µ�ʱ�� 
}

void GameMenu::show() const {
    View::showGameMenu(this); // ί�и� View 
}

void GameMenu::process() {
    Controller::processGameMenu(this); // ί�и� Controller 
}

int GameMenu::getScore() const {
    return mScore;
}

void GameMenu::runTick() { // ��ͼ����һ�� tick 
    if(mLastTickTime < 0) {
        mLastTickTime = clock();
    }else {
        if(clock() - mLastTickTime >= tickLength) {
            mScore += mChessboard.moveDown(); // ����Ϸ����һ�� tick 
            mLastTickTime = clock();
            // ��ʼһ���µ� Tick 
        }
    }
}

const Chessboard* GameMenu::getChessboard() const {
    return &mChessboard;
}

Chessboard* GameMenu::getChessboard() {
    return &mChessboard; // Ϊ�� process ʹ�� 
}

