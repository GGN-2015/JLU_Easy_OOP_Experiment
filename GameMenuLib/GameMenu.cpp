#include <ctime>
#include <iostream>

#include "App.h"
#include "Controller.h"
#include "GameMenu.h"
#include "View.h"

int GameMenu::tickLength = TICK_LENGTH_MAX; // 600 ms

GameMenu::GameMenu() {
    mLastTickTime = clock(); // 上一个 tick 更新的时间 
}

GameMenu::GameMenu(const char* fileName) { // 从文件加载游戏 
    mLastTickTime = clock();
    // TODO: not finished!
    App::loadGameMenu(fileName, this);
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
            bool okToRun = true;
            mScore += mChessboard.moveDown(okToRun); // 让游戏进行一个 tick 
            mLastTickTime = clock();
            // 开始一个新的 Tick 
            if(!okToRun) {
                Controller::lostGame(getScore()); // 游戏失败 
            }
        }
    }
}

const Chessboard* GameMenu::getChessboard() const {
    return &mChessboard;
}

Chessboard* GameMenu::getChessboard() {
    return &mChessboard; // 为了 process 使用 
}

void GameMenu::setSpeed(int degree) {
    int discount = degree * TICK_LENGTH_STEP;
    GameMenu::tickLength
        = TICK_LENGTH_MAX - discount;
}

void GameMenu::saveGameMenu() const {
    App::saveGameMenu(this);
}

void GameMenu::setScore(int score) {
    mScore = score;
}

std::string GameMenu::getMenuType() const {
    return "GameMenu";
}

