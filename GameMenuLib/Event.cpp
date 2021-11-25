#include <conio.h>

#include "Event.h"
#include "IMenu.h"

Event::Event() { // ��ʱʹ�� conio.h ���ṩ�ĺ����������� 
    char ch = getch();
    mKeyLeft  = (ch == 'a'  || ch == 'A');
    mKeyRight = (ch == 'd'  || ch == 'D');
    mKeyUp    = (ch == 'w'  || ch == 'W');
    mKeyDown  = (ch == 's'  || ch == 'S');
    mKeyEnter = (ch == '\n' || ch == '\r'); // ����Ƿ���ָ���İ����������� 
}

bool Event::isLeft() const { // ����Ƿ��������ƶ��Ĳ��� 
    return mKeyLeft;
}

bool Event::isRight() const { // ����Ƿ��������ƶ��Ĳ��� 
    return mKeyRight;
}

bool Event::isUp() const { // ����Ƿ��������ƶ��Ĳ��� 
    return mKeyUp;
}

bool Event::isDown() const { // ����Ƿ��������ƶ��Ĳ��� 
    return mKeyDown;
}

bool Event::isConfirm() const { // ����Ƿ���ȷ�ϲ��� 
    // �˴��������ܻᱻ�޸� 
    return mKeyEnter;
}

void Event::operateIMenu(IMenu* imenu) const { // ���� event ���� imenu 
    if(isUp()) {
        imenu -> prevTerm(); // �������һ����Ŀ 
    }
    if(isDown()) {
        imenu -> nextTerm(); // �������һ����Ŀ 
    }
}

