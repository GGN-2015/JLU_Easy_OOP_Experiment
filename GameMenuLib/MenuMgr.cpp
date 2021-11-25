#include <stack>

#include "MainMenu.h"
#include "MenuMgr.h"

MenuMgr& MenuMgr::getInstance() { // 菜单管理器采用静态单例 
    static MenuMgr menuMgr;
    return menuMgr;
}

IMenu* MenuMgr::getActiveMenu() const { // 获取当前页面栈最顶部的菜单 
    if(mMenuStack.size() > 0) {
        return mMenuStack.top();
    }else {
        return nullptr; // 页面栈中已经没有页面说明程序此时应该退出 
    }
}

void MenuMgr::popMenuStack() {
    if(mMenuStack.size() > 0) {  // 我们可以认为 == 0 的情况一定不会出现 
        delete mMenuStack.top(); // 在弹栈时清空对应的储存单元 
        mMenuStack.pop();        // 因为我们要求 App 中遇到 IMenu = nullptr 时就会立即退出 
    }
}

void MenuMgr::pushMenuStack(IMenu* imenu) { // 向页面栈中压入一个元素: push(new MenuType); 
    mMenuStack.push(imenu);
}

MenuMgr::MenuMgr() {
    mMenuStack.push(new MainMenu); // 初始的时候插入一个主菜单 
}

MenuMgr::~MenuMgr() {
    while(!mMenuStack.empty()) { // 防止内存泄漏，析构的时候要弹空页面栈 
        popMenuStack();
    }
}

