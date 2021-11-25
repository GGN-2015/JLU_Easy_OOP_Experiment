#ifndef EVENT_H
#define EVENT_H

class IMenu;
class MainMenu;

class Event {
public:
    Event(); // �ڹ����ͬʱ��ȡ��ǰ���¼���Ϣ 
    
    virtual bool isConfirm() const;  // ���س��Ƿ񱻰����� 
    
    bool isLeft  () const;
    bool isRight () const;
    bool isUp    () const;
    bool isDown  () const; // ����Ƿ����������ҷ����ƶ��ļ������� 
    
    void operateIMenu(IMenu*) const; // ���� IMenu �ĵ� ActiveTerm ��ѡ�� 
    
private:
    bool mKeyLeft, mKeyRight, mKeyUp, mKeyDown; // ����� 
    bool mKeyEnter;
};

#endif

