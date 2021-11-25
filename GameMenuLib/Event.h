#ifndef EVENT_H
#define EVENT_H

class IMenu;
class MainMenu;

class Event {
public:
    Event(); // 在构造的同时读取当前的事件信息 
    
    virtual bool isConfirm() const;  // 检测回车是否被按下了 
    
    bool isLeft  () const;
    bool isRight () const;
    bool isUp    () const;
    bool isDown  () const; // 检测是否是上下左右方向移动的键被按下 
    
    void operateIMenu(IMenu*) const; // 操作 IMenu 的的 ActiveTerm 的选中 
    
private:
    bool mKeyLeft, mKeyRight, mKeyUp, mKeyDown; // 方向键 
    bool mKeyEnter;
};

#endif

