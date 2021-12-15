#pragma once

#include <string>
#include <vector>
#include "IObject.h"

class File: public IObject {
public:
    File(std::string fileName); // �����ļ�ʱҪ�����ļ��� 
    
    std::string getObjectName() const;        // �����ļ��� 
    std::string getObjectType() const;        // DIR / FILE
    void changeObjectName(std::string); // �޸��ļ��� 
    
    int getLineCount() const;                       // �����ļ������� 
    std::string getLineById(int index) const;       // �ҵ��ļ���ĳ�����ݣ�Լ���кŴ� 1 ��ʼ 
    bool insertLineBeforeId(int index, std::string); // ��ĳ��ǰ�������� 
    
    void deleteLineById(int index); // ���� index ɾ��ĳһ������ 
    virtual void show(int from = 0, int to = -1) const; // ��ʾһ�������ڵ����� 
    void append(std::string newLine); // ���ļ�β�������� 
    
protected:
    void showLine(int prelen, int index) const; // ����� index ��ʵ�ʵ��±� 
    int getRealLineId(int index) const;         // ��ȡ vector ��ĳ�еĴ洢λ�� 
    std::string getLineMessage(int from, int to) const; // ����к���Ϣ 

    std::string              mFileName; // ��¼�ļ��� 
    std::vector<std::string> mText;     // ��¼�ı����� 
};

