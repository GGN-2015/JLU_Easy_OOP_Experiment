#include <ctime>
#include <iostream>

#include "App.h"
#include "Controller.h"
#include "GameMenu.h"
#include "View.h"

int GameMenu::tickLength = TICK_LENGTH_MAX; // 600 ms

GameMenu::GameMenu() {
    mLastTickTime = clock(); // ��һ�� tick ���µ�ʱ�� 
}

GameMenu::GameMenu(const char* fileName) { // ���ļ�������Ϸ 
    mLastTickTime = clock();
    // TODO: not finished!
    App::loadGameMenu(fileName, this);
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
            bool okToRun = true;
            mScore += mChessboard.moveDown(okToRun); // ����Ϸ����һ�� tick 
            mLastTickTime = clock();
            // ��ʼһ���µ� Tick 
            if(!okToRun) {
                Controller::lostGame(getScore()); // ��Ϸʧ�� 
            }
        }
    }
}

const Chessboard* GameMenu::getChessboard() const {
    return &mChessboard;
}

Chessboard* GameMenu::getChessboard() {
    return &mChessboard; // Ϊ�� process ʹ�� 
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

