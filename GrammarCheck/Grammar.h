#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <map>
#include <string>
#include <vector>

class GrammarTree;

class Grammar { // ���ļ���ȡ�﷨���� 
public:
    static Grammar& getInstance();                                   // ��̬���� 
    GrammarTree* match(std::vector<std::string>, std::string, int&); // ��һ�����Ŵ�����ƥ�� 
    int getMaxPos() const;                                           // ����ս�������ƥ��λ�� 
    
    static void inputText(std::string, std::vector<std::string>&);   // �����ļ��е� vector 
    
private:
    Grammar(std::string fileName);
    void outputMap() const; // ��� mMatchMethod 
    int maxPos = 0;
    
    static bool isUnfinished(std::string); // ���һ���ַ����ǲ��Ƿ��ս�� 
    static void quit();                    // ��ֹ�﷨��� 
    
    std::map<std::string, std::vector<std::vector<std::string>> > mMatchMethods; // ƥ�䷽�� 
};

#endif

