#ifndef MENUMGR_H
#define MENUMGR_H

#include <stack> // �˵��������ı�����ҳ��ջ 

class IMenu; // ����˵����� 

class MenuMgr {
public:
    static MenuMgr& getInstance(); // �˵��������ǵ��� 
    
    IMenu* getActiveMenu() const; // ��õ�ǰҳ��ջջ����Ԫ�� 
    void popMenuStack();          // ����ҳ��ջ��ջ��Ԫ�أ�¶���·�Ԫ�� 
    void pushMenuStack(IMenu*);   // ��ջ��ѹ��һ���µ�ҳ�棬��ջʱ�����ͷ� 

private:
    MenuMgr();
    ~MenuMgr(); 
    
    MenuMgr(const MenuMgr&) = delete;
    MenuMgr& operator= (const MenuMgr&) = delete; // ��ֹ���쿽����ֵ 
    
    std::stack<IMenu*> mMenuStack; // ҳ��ջ����ջ��ʱ��ǵ����� 
};

#endif

