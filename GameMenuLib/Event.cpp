#include <conio.h>
#include <cstdio>
#include <ctime>
#include <windows.h>

#include "Console.h"
#include "Event.h"
#include "GameMenu.h"
#include "IMenu.h"

KeyList Event::keyListNow;
KeyList Event::keyListLast;

void KeyList::getKeyList() {
    mKeyLeft  = Console::keyDown(VK_LEFT);
    mKeyRight = Console::keyDown(VK_RIGHT);
    mKeyUp    = Console::keyDown(VK_UP);
    mKeyDown  = Console::keyDown(VK_DOWN);
    mKeyEnter = Console::keyDown(VK_RETURN); // ����Ƿ���ָ���İ����������� 
    mKeyEsc   = Console::keyDown(VK_ESCAPE);
}

void KeyList::clearKeyList() {
    mKeyLeft  = Console::keyDown(VK_LEFT);
    mKeyRight = Console::keyDown(VK_RIGHT);
    mKeyUp    = Console::keyDown(VK_UP);
    mKeyDown  = Console::keyDown(VK_DOWN);
    mKeyEnter = Console::keyDown(VK_RETURN); // ����Ƿ���ָ���İ����������� 
    mKeyEsc   = Console::keyDown(VK_ESCAPE);
}

Event::Event() { // ��ʱʹ�� conio.h ���ṩ�ĺ����������� 
    keyListLast = keyListNow;
    keyListNow.getKeyList(); // ��ȡ�µİ������� 
}       
        
bool Event::isLeft() const { // ����Ƿ��������ƶ��Ĳ��� 
    return keyListLast.mKeyLeft && !keyListNow.mKeyLeft;
}

bool Event::isRight() const { // ����Ƿ��������ƶ��Ĳ��� 
    return keyListLast.mKeyRight && !keyListNow.mKeyRight;
}

bool Event::isUp() const { // ����Ƿ��������ƶ��Ĳ��� 
    return keyListLast.mKeyUp && !keyListNow.mKeyUp;
}

bool Event::isDown() const { // ����Ƿ��������ƶ��Ĳ��� 
    return keyListLast.mKeyDown && !keyListNow.mKeyDown;
}

bool Event::isConfirm() const { // ����Ƿ���ȷ�ϲ��� 
    // �˴��������ܻᱻ�޸� 
    return keyListLast.mKeyEnter && !keyListNow.mKeyEnter;
}

bool Event::isEsc() const { // ��� Esc ���Ƿ񱻰����� 
    return keyListLast.mKeyEsc && !keyListNow.mKeyEsc;
}

void Event::operateIMenu(IMenu* imenu) const { // ���� event ���� imenu 
    if(isUp()) {
        imenu -> prevTerm(); // �������һ����Ŀ 
    }
    if(isDown()) {
        imenu -> nextTerm(); // �������һ����Ŀ 
    }
}

void Event::inActivate() {
    keyListNow.clearKeyList(); // ���֮ǰ�İ�ѹ�¼� 
}

void Event::operateGameMenu(GameMenu* gameMenu) const {
    if(isLeft()) { // ��ͼ�����ƶ� 
        gameMenu -> getChessboard() -> tetrisLeft();
    }
    if(isRight()) { // ��ͼ�����ƶ� 
        gameMenu -> getChessboard() -> tetrisRight();
    }
    if(isUp()) { // ��ͼ��ת����� 
        gameMenu -> getChessboard() -> tetrisTurn();
    }
    if(isDown()) { // ��ͼ�� ��������� 
        gameMenu -> getChessboard() -> moveDown();
    }
    
}
