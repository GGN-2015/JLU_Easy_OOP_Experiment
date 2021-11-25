// 我觉得吧，这个游戏逻辑没什么可拓展的
// 就直接 if - else 了，感觉问题不大 
// 要是非要拓展，倒是不如换个游戏 

#include <iostream>
#include "TetrisBlock.h"

TetrisBlock::TetrisBlock(TetrisType type) {
    // 根据 type 来定义俄罗斯方块的类型 
    if(type == TypeZ) {
        mPos[0][0] = 1; // □□
        mPos[0][1] = 1; //   □□
        mPos[1][1] = 1;
        mPos[1][2] = 1;
    }else
    if(type == TypeT) {
        mPos[0][0] = 1; // □□□
        mPos[0][1] = 1; //   □
        mPos[0][2] = 1; 
        mPos[1][1] = 1;
    }else
    if(type == TypeL) {
        mPos[0][0] = 1; // □
        mPos[1][0] = 1; // □
        mPos[2][0] = 1; // □□
        mPos[2][1] = 1; 
    }else
    if(type == TypeI) {
        mPos[0][0] = 1; // □
        mPos[1][0] = 1; // □
        mPos[2][0] = 1; // □
        mPos[3][0] = 1; // □
    }else
    if(type == TypeO) {
        mPos[0][0] = 1; // □□
        mPos[0][1] = 1; // □□
        mPos[1][0] = 1;
        mPos[1][1] = 1;
    }else {
        std::cout << "TetrisBlock::TetrisBlock(TetrisType type) type error!" << std::endl;
    }
}

void TetrisBlock::debugShow() const {
    std::cout << std::endl;
    for(int i = 0; i < 4; i ++) {
        for(int j = 0; j < 4; j ++) {
            if(mPos[i][j]) {
                std::cout << "□";
            }else {
                std::cout << "**";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int TetrisBlock::maxDepth() const {
    int maxDep = 0;
    for(int i = 3; i >= 0; i --) {
        for(int j = 0; j < 4; j ++) {
            if(mPos[i][j]) {
                maxDep = i;
                break;
            }
        }
    }
    return maxDep;
}

void TetrisBlock::rotate() {
    rotateFull();
    while(!leftMost()) {
        moveLeft();
    }
    while(!upMost()) {
        moveUp();
    }
}

void TetrisBlock::rotateFull() {
    bool nPos[4][4] = {};
    for(int i = 0; i < 4; i ++) {
        for(int j = 0; j < 4; j ++) {
            int ni = j, nj = 3 - i; // 绕中心顺时针旋转 90 度 
            nPos[ni][nj] = mPos[i][j];
        }
    }
    for(int i = 0; i < 4; i ++) {
        for(int j = 0; j < 4; j ++) {
            mPos[i][j] = nPos[i][j];
        }
    }
}

bool TetrisBlock::leftMost() const {
    // 检测第一列有没有值 
    for(int i = 0; i < 4; i ++) {
        if(mPos[i][0]) {
            return true;
        }
    }
    return false;
}

bool TetrisBlock::upMost() const {
    // 检测第一行有没有值 
    for(int j = 0; j < 4; j ++) {
        if(mPos[0][j]) {
            return true;
        }
    }
    return false;
}

void TetrisBlock::moveLeft() {
    for(int j = 0; j < 3; j ++) {
        // 按列拷贝 
        for(int i = 0; i < 4; i ++) {
            mPos[i][j] = mPos[i][j+1];
        }
    }
    for(int i = 0; i < 4; i ++) {
        mPos[i][3] = 0; // 清空最后一列 
    }
}

void TetrisBlock::moveUp() {
    for(int i = 0; i < 3; i ++) {
        // 按行拷贝 
        for(int j = 0; j < 4; j ++) {
            mPos[i][j] = mPos[i+1][j];
        }
    }
    for(int j = 0; j < 4; j ++) {
        mPos[3][j] = 0; // 清空最后一行 
    }
}

