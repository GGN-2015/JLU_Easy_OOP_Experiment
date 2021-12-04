#ifndef ERRORMGR_H
#define ERRORMGR_H // ��������� 

#include <string>
#include <vector>

struct ErrorMessage {
    std::string fileName; // ���������ļ��� 
    int lineNum;          // ���������к� 
    std::string message;  // ������Ϣ 
};

class ErrorMgr {
public:
    static ErrorMgr& getInstance(); // ��ȡ����������������� 
    void push(std::string fileName, int lineNum, std::string message); // �������������Ӵ��� 
    void show(int line) const;      // ��ʾ���д�����Ļ 
    bool checkEmpty() const;        // ����Ƿ�����˴��� 
    void clear();                   // ��մ�����Ϣ 

private:
    ErrorMgr();
    std::vector<ErrorMessage> mErrors; // ��¼���д�����Ϣ 
};

#endif

