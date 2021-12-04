#ifndef SYNTAXCHECKER_H
#define SYNTAXCHECKER_H

#include <algorithm>
#include <tuple>
#include <vector>
#include "ISyntax.h"

// �к�, �к�, ԭ����, ������ 
struct SyntaxWord { // һ���ʷ�ģ�� 
    int lineId;
    int columnId;
    std::string rawString;
    std::string typeName;
};

typedef std::vector<SyntaxWord> SyntaxWordList; // һ���ʷ�ģ������ 
typedef std::vector<SyntaxWordList> SyntaxWordLineList; // ÿ��Ԫ�ض���һ�г��� 

class SyntaxChecker { // �﷨����� 
public:
    static SyntaxChecker& getInstance(); // ��̬���� 
    ~SyntaxChecker();
    
    int syntaxCheck(std::string sline, SyntaxWordList& syntaxList, int lineId) const;
    // ����ֵ���� -1 ��ʾ�����ɹ�, ���� >= 0 ��ֵ��ʾ�ڸ�λ���޷�ƥ�� 
    
    void inputAndCheckSyntax(SyntaxWordLineList&) const;
    // �����������򲢽����﷨��� 
    
private:
    SyntaxChecker();
    std::vector<ISyntax*> mAllSyntax; // ��¼���п��ܳ��ֵ��﷨ 
};

#endif

