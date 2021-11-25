#include <stack>

#include "MainMenu.h"
#include "MenuMgr.h"

MenuMgr& MenuMgr::getInstance() { // �˵����������þ�̬���� 
    static MenuMgr menuMgr;
    return menuMgr;
}

IMenu* MenuMgr::getActiveMenu() const { // ��ȡ��ǰҳ��ջ����Ĳ˵� 
    if(mMenuStack.size() > 0) {
        return mMenuStack.top();
    }else {
        return nullptr; // ҳ��ջ���Ѿ�û��ҳ��˵�������ʱӦ���˳� 
    }
}

void MenuMgr::popMenuStack() {
    if(mMenuStack.size() > 0) {  // ���ǿ�����Ϊ == 0 �����һ��������� 
        delete mMenuStack.top(); // �ڵ�ջʱ��ն�Ӧ�Ĵ��浥Ԫ 
        mMenuStack.pop();        // ��Ϊ����Ҫ�� App ������ IMenu = nullptr ʱ�ͻ������˳� 
    }
}

void MenuMgr::pushMenuStack(IMenu* imenu) { // ��ҳ��ջ��ѹ��һ��Ԫ��: push(new MenuType); 
    mMenuStack.push(imenu);
}

MenuMgr::MenuMgr() {
    mMenuStack.push(new MainMenu); // ��ʼ��ʱ�����һ�����˵� 
}

MenuMgr::~MenuMgr() {
    while(!mMenuStack.empty()) { // ��ֹ�ڴ�й©��������ʱ��Ҫ����ҳ��ջ 
        popMenuStack();
    }
}

