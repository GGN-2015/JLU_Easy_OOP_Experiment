#include <iostream>

#include "GrammarTree.h"

int GrammarTree::maxDepth = 3; // ��������� 

GrammarTree::GrammarTree(std::string matchName, int matchMethodId, int beginPos) {
    mMatchName     = matchName;     // ƥ��ķ����� 
    mMatchMethodId = matchMethodId; // ƥ�䷽ʽ��ţ��±�� 0 ��ʼ 
    mBeginPos      = beginPos;      // �� vector of string �е���ʼ�±� 
}

void GrammarTree::addSon(GrammarTree* newSon) {
    mSonNodes.push_back(newSon);    // ׷��һ���ӽڵ� 
}

GrammarTree::~GrammarTree() {
    for(auto ptr: mSonNodes) {
        delete ptr;
    }
}

void GrammarTree::show() const {
    static int indent = 0; // ��¼�������� 
    if(mSonNodes.size() && indent <= maxDepth) {
        makeIndent(indent);    // ��������ո� 
        std::cout << mMatchName << " [" << mBeginPos << "]" << std::endl;
        makeIndent(indent);
        std::cout << "{" << std::endl;
        indent ++;             // Ϊ������׼���������� 
        for(auto son: mSonNodes) { // ö�������ӽڵ� 
            son -> show();         // �ݹ����������Ϣ 
        }
        indent --; makeIndent(indent);
        std::cout << "}" << std::endl;
    }else {
        // ���û�ж��ӽڵ���ս�� 
        makeIndent(indent);
        std::cout << mMatchName << " [" << mBeginPos << "]" << std::endl;
    }
}

void GrammarTree::makeIndent(int len) {
    for(int i = 0; i < 2 * len; i ++) putchar(' ');
}

