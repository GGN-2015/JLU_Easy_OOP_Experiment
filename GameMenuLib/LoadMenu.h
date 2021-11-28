#ifndef LOADMENU_H
#define LOADMENU_H

#include <string>
#include <vector>

#include "IMenu.h"

class LoadMenu: public IMenu {
public:
    virtual std::string getTitle() const;                     // ��ȡ�˵��ı��� 
    virtual const std::vector<std::string>& getTerms() const; // ��ȡ�˵���ÿһ������ 
    virtual void show() const;                                // ��ʾ����˵�, ί�и� View �� 
    virtual void process();
};

#endif

