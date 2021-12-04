#ifndef GRAMMARTREE_H
#define GRAMMARTREE_H // 抽象语法树结点 

#include <string>
#include <vector>

class GrammarTree { // 抽象语法树结点 
public:
    GrammarTree(std::string matchName, int matchMethodId, int beginPos);
    ~GrammarTree(); // 递归析构抽象语法树 
    
    void addSon(GrammarTree* newSon);   // 新增一个子节点 
    void show() const ;                 // 递归显示抽象语法树 

private:
    static int maxDepth;
    static void makeIndent(int len);    // 进行缩进 
    
    std::string mMatchName; // 匹配结构名 
    int mMatchMethodId;     // 匹配方法编号 (从 0 开始) 
    int mBeginPos;          // 起始位置的下标 
    
    std::vector <GrammarTree*> mSonNodes; // 子节点序列 
};

#endif

