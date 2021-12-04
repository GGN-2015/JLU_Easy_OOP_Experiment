#ifndef GRAMMARCHECKER_H
#define GRAMMARCHECKER_H // 检查整个程序是否符合语法 

#include <map>
#include <stack>
#include <string>
#include <vector>

#include "SyntaxChecker.h"

class IGammar;      // 描述所有抽象模式的匹配 
class ILineMessage; // 描述所有抽象的行信息 

class GrammarChecker {
public:
    static GrammarChecker& getInstance(); // 获得静态单例 
    
    bool checkGrammar(const SyntaxWordLineList&); // 检查程序是否合法并进行语法分析 
    
    void pushLineId(int lineId);      // 向匹配栈中压入一个行号 
    int  topLineId(int lineId) const; // 返回匹配栈中的栈顶元素，但是不弹出 
    void popLineId();                 // 从匹配栈中弹出一个元素 
    bool checkLineIdEmpty() const;    // 检查匹配栈是否为空 
    
    void setMainLink(int subId, int mainLink) const; // 记录主要语句下标 
    
private:
    std::vector<IGammar*> mGrammerList; // 所有可能的语法处理方式 
    
    GrammarChecker();        // 静态单例 
    SyntaxWordLineList mRaw; // 记录整个被编译的程序 
    
    int find(std::string, const SyntaxWordList&);    // 在某一行中找某个字符串出现的位置 
    bool unique(std::string, const SyntaxWordList&); // 判断某个字符串在某一行中是否只出现了一次 
    
    void copyPart(SyntaxWordList&, SyntaxWordLineList&, int line, int begin, int end);
    // 将  SyntaxWordLineList[line] 中 [begin, end) 部分拷贝给 SyntaxWordList 
    
    bool checkIsLeftValue(const SyntaxWordList&); // 检测是不是左值 
    bool checkIsRightValue(const SyntaxWordList&); // 检测是不是右值 
    
    std::stack<int>  mMatchStack;  // 匹配栈  
    std::map<int, int> mMainLink;  // 附属语句记录主要语句的 vector 下标号 
    
    std::map<int, ILineMessage*> mLineMessage; // ILineMessage 是抽象的行信息 
    std::map<std::string, int> mFunctionLine;  // 记录函数定义所在行 
    std::map<std::string, int> mTypeLine;      // 记录类型定义所在行 
};

#endif

/* 重构前的所有记录的信息 

struct Parameter {
    std::string paraName;              // 记录参数名 
    std::vector<std::string> paraType; // 记录参数类型 
};

struct FunctionMessage {  // 描述一个函数的所有信息 
    std::string funcName; // 函数名 
    int lineId;           // 函数定义所在行在 vector 中的下标 
    std::vector<std::string> returnType;  // 此时的类型需要经过类型检查 
    std::vector<Parameter> parameterList; // 依次记录所有参数信息 
};

struct IfMessage {   // 记录 If 语句的所有信息 
    int lineId;      // if 所在的下标编号 
    int elseLineId;  // 默认 等于 -1 表示没有与之匹配的 else 
    int endifLineId; // endif 的行编号，默认为 -1 
};

struct ForMessage {   // 记录 For 语句的所有信息 
    int lineId;       // for 所在的 vector 下标号 
    int endforLineId; // endfor 所在的 vector 下标号 
    
    SyntaxWordList leftValue;  // 等号前的左值变量 
    SyntaxWordList rightValue; // 等号后的初始右值 
    SyntaxWordList finalValue; // 最终值 
    SyntaxWordList stepValue;  // 步长 
};

struct WhileMessage {
    int lineId;         // 记录 while 所在行的下标 
    int endwhileLineId; // 记录 endwhile 所在行的下标 
    
    SyntaxWordList checkValue; // 每次被检验的左值 
};

struct DefineMessage {
    std::vector<std::string> nameList; // 定义的变量名序列 
    std::vector<std::string> varType;  // 变量类型信息 
};

struct SetMessage {
    SyntaxWordList leftValue;  // 等号前的左值 
    SyntaxWordList rightValue; // 等号后的右值，字符串是指针右值 
};

struct WriteMessage {
    SyntaxWordLineList leftValues; // 记录每一个将要被输出的左值 
};

struct WriteCharMessage {
    SyntaxWordLineList leftValues; // 记录每一个将要被输出的左值 
};
*/ 
