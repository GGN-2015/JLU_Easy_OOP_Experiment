#ifndef STRINGSTREAM_H
#define STRINGSTREAM_H

#include <string>

class StringStream { // ��дһ���ַ��� 
public:
    StringStream(std::string);  // ���ݹ���һ���ַ������ַ����в�Ӧ���� 
    bool empty() const;         // ������Ƿ�Ϊ�� 
    char front() const;         // ��ȡ��һ���ַ�������ַ������Ѿ�Ϊ�գ����� 0 
    void popFront();            // ɾ����һ���ַ�������ַ������Ѿ�Ϊ�գ����Դ˲��� 
    
    void withdraw(int cnt = 1); // ����һ���ַ���ɾ������������Ѿ���ԭ������ 
    int  size() const;          // ����ʣ���ַ������� 
    
    std::string front(int len); // ��ȡǰ���ɸ��ַ� 
    
    int position() const;       // ��õ�ǰ��λ�� ID 
    
private:
    std::string mString;
    int mIndex;
};

#endif

