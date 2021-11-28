#ifndef LOADMENU_H
#define LOADMENU_H

#include <string>
#include <vector>

#include "IMenu.h"

class LoadMenu: public IMenu {
public:
    virtual std::string getTitle() const;                     // 获取菜单的标题 
    virtual const std::vector<std::string>& getTerms() const; // 获取菜单中每一项内容 
    virtual void show() const;                                // 显示这个菜单, 委托给 View 做 
    virtual void process();
};

#endif

