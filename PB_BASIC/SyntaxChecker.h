#ifndef SYNTAXCHECKER_H
#define SYNTAXCHECKER_H

#include <vector>
#include "ISyntax.h"

typedef std::pair<std::string, ISyntax*> SyntaxWord; // һ���ʷ�ģ�� 
typedef std::vector<SyntaxWord> SyntaxWordList; // һ���ʷ�ģ������ 

class SyntaxChecker { // �﷨����� 
public:
    SyntaxChecker();
    ~SyntaxChecker();
    
    int syntaxCheck(std::string sline, SyntaxWordList& syntaxList) const;
    // ����ֵ���� -1 ��ʾ�����ɹ�, ���� >= 0 ��ֵ��ʾ�ڸ�λ���޷�ƥ�� 
    
private:
    std::vector<ISyntax*> mAllSyntax; // ��¼���п��ܳ��ֵ��﷨ 
};

#endif

