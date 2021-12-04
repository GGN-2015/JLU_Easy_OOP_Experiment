#include <iostream>

#include "GrammarTree.h"

int GrammarTree::maxDepth = 3; // 最大输出深度 

GrammarTree::GrammarTree(std::string matchName, int matchMethodId, int beginPos) {
    mMatchName     = matchName;     // 匹配的符号名 
    mMatchMethodId = matchMethodId; // 匹配方式编号，下标从 0 开始 
    mBeginPos      = beginPos;      // 在 vector of string 中的起始下标 
}

void GrammarTree::addSon(GrammarTree* newSon) {
    mSonNodes.push_back(newSon);    // 追加一个子节点 
}

GrammarTree::~GrammarTree() {
    for(auto ptr: mSonNodes) {
        delete ptr;
    }
}

void GrammarTree::show() const {
    static int indent = 0; // 记录缩进层数 
    if(mSonNodes.size() && indent <= maxDepth) {
        makeIndent(indent);    // 输出缩进空格 
        std::cout << mMatchName << " [" << mBeginPos << "]" << std::endl;
        makeIndent(indent);
        std::cout << "{" << std::endl;
        indent ++;             // 为子树中准备好缩进块 
        for(auto son: mSonNodes) { // 枚举所有子节点 
            son -> show();         // 递归输出子树信息 
        }
        indent --; makeIndent(indent);
        std::cout << "}" << std::endl;
    }else {
        // 输出没有儿子节点的终结符 
        makeIndent(indent);
        std::cout << mMatchName << " [" << mBeginPos << "]" << std::endl;
    }
}

void GrammarTree::makeIndent(int len) {
    for(int i = 0; i < 2 * len; i ++) putchar(' ');
}

