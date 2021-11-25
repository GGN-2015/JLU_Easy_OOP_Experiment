#ifndef UNFINISHEDMENU_H
#define UNFINISHEDMENU_H

#include "IMenu.h"

class UnfinishedMenu: public IMenu { // Ϊ��û���깤��Ŀ¼����ռλ 
    enum Terms { // �˴������ֶ��� getTerms �е�����һ�� 
        OK = 0
    };
    
    virtual std::string getTitle() const;
    virtual const std::vector<std::string>& getTerms() const;
    virtual void show() const;
    
    virtual void process();
};

#endif
