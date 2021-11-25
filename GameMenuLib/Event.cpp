#include <conio.h>

#include "Event.h"
#include "IMenu.h"

Event::Event() { // 暂时使用 conio.h 中提供的函数进行输入 
    char ch = getch();
    mKeyLeft  = (ch == 'a'  || ch == 'A');
    mKeyRight = (ch == 'd'  || ch == 'D');
    mKeyUp    = (ch == 'w'  || ch == 'W');
    mKeyDown  = (ch == 's'  || ch == 'S');
    mKeyEnter = (ch == '\n' || ch == '\r'); // 检测是否是指定的按键被按下了 
}

bool Event::isLeft() const { // 检测是否是向左移动的操作 
    return mKeyLeft;
}

bool Event::isRight() const { // 检测是否是向右移动的操作 
    return mKeyRight;
}

bool Event::isUp() const { // 检测是否是向上移动的操作 
    return mKeyUp;
}

bool Event::isDown() const { // 检测是否是向下移动的操作 
    return mKeyDown;
}

bool Event::isConfirm() const { // 检测是否是确认操作 
    // 此处将来可能会被修改 
    return mKeyEnter;
}

void Event::operateIMenu(IMenu* imenu) const { // 根据 event 操作 imenu 
    if(isUp()) {
        imenu -> prevTerm(); // 光标上移一个条目 
    }
    if(isDown()) {
        imenu -> nextTerm(); // 光标下移一个条目 
    }
}

