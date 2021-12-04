#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <map>
#include <string>
#include <vector>

class GrammarTree;

class Grammar { // 从文件读取语法数据 
public:
    static Grammar& getInstance();                                   // 静态单例 
    GrammarTree* match(std::vector<std::string>, std::string, int&); // 对一个符号串进行匹配 
    int getMaxPos() const;                                           // 获得终结符的最大匹配位置 
    
    static void inputText(std::string, std::vector<std::string>&);   // 输入文件中的 vector 
    
private:
    Grammar(std::string fileName);
    void outputMap() const; // 输出 mMatchMethod 
    int maxPos = 0;
    
    static bool isUnfinished(std::string); // 检测一个字符串是不是非终结符 
    static void quit();                    // 终止语法检查 
    
    std::map<std::string, std::vector<std::vector<std::string>> > mMatchMethods; // 匹配方法 
};

#endif

