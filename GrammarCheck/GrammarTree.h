#ifndef GRAMMARTREE_H
#define GRAMMARTREE_H // �����﷨����� 

#include <string>
#include <vector>

class GrammarTree { // �����﷨����� 
public:
    GrammarTree(std::string matchName, int matchMethodId, int beginPos);
    ~GrammarTree(); // �ݹ����������﷨�� 
    
    void addSon(GrammarTree* newSon);   // ����һ���ӽڵ� 
    void show() const ;                 // �ݹ���ʾ�����﷨�� 

private:
    static int maxDepth;
    static void makeIndent(int len);    // �������� 
    
    std::string mMatchName; // ƥ��ṹ�� 
    int mMatchMethodId;     // ƥ�䷽����� (�� 0 ��ʼ) 
    int mBeginPos;          // ��ʼλ�õ��±� 
    
    std::vector <GrammarTree*> mSonNodes; // �ӽڵ����� 
};

#endif

