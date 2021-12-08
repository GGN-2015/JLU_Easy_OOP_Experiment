#pragma once

#include <string>

class SyntaxWord {
public:
    enum SyntaxWordType {
        TYPE_LABEL = 0, // �������߱������������� 
        TYPE_ADD,
        TYPE_SUB,
        TYPE_MUL,
        TYPE_DIV,
        TYPE_MOD,
        TYPE_LEFT, // �����ź������� 
        TYPE_RIGHT,
    };
    
    SyntaxWord(std::string raw, SyntaxWordType type);
    std::string getRaw() const;    // ��ȡԭʼ��Ϣ�ַ��� 
    SyntaxWordType getType() const; // ��ȡ���� ID 

private:
    std::string mRaw;
    SyntaxWordType mType;
};

