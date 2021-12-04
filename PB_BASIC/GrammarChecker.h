#ifndef GRAMMARCHECKER_H
#define GRAMMARCHECKER_H // ������������Ƿ�����﷨ 

#include <map>
#include <stack>
#include <string>
#include <vector>

#include "SyntaxChecker.h"

class IGammar;      // �������г���ģʽ��ƥ�� 
class ILineMessage; // �������г��������Ϣ 

class GrammarChecker {
public:
    static GrammarChecker& getInstance(); // ��þ�̬���� 
    
    bool checkGrammar(const SyntaxWordLineList&); // �������Ƿ�Ϸ��������﷨���� 
    
    void pushLineId(int lineId);      // ��ƥ��ջ��ѹ��һ���к� 
    int  topLineId(int lineId) const; // ����ƥ��ջ�е�ջ��Ԫ�أ����ǲ����� 
    void popLineId();                 // ��ƥ��ջ�е���һ��Ԫ�� 
    bool checkLineIdEmpty() const;    // ���ƥ��ջ�Ƿ�Ϊ�� 
    
    void setMainLink(int subId, int mainLink) const; // ��¼��Ҫ����±� 
    
private:
    std::vector<IGammar*> mGrammerList; // ���п��ܵ��﷨����ʽ 
    
    GrammarChecker();        // ��̬���� 
    SyntaxWordLineList mRaw; // ��¼����������ĳ��� 
    
    int find(std::string, const SyntaxWordList&);    // ��ĳһ������ĳ���ַ������ֵ�λ�� 
    bool unique(std::string, const SyntaxWordList&); // �ж�ĳ���ַ�����ĳһ�����Ƿ�ֻ������һ�� 
    
    void copyPart(SyntaxWordList&, SyntaxWordLineList&, int line, int begin, int end);
    // ��  SyntaxWordLineList[line] �� [begin, end) ���ֿ����� SyntaxWordList 
    
    bool checkIsLeftValue(const SyntaxWordList&); // ����ǲ�����ֵ 
    bool checkIsRightValue(const SyntaxWordList&); // ����ǲ�����ֵ 
    
    std::stack<int>  mMatchStack;  // ƥ��ջ  
    std::map<int, int> mMainLink;  // ��������¼��Ҫ���� vector �±�� 
    
    std::map<int, ILineMessage*> mLineMessage; // ILineMessage �ǳ��������Ϣ 
    std::map<std::string, int> mFunctionLine;  // ��¼�������������� 
    std::map<std::string, int> mTypeLine;      // ��¼���Ͷ��������� 
};

#endif

/* �ع�ǰ�����м�¼����Ϣ 

struct Parameter {
    std::string paraName;              // ��¼������ 
    std::vector<std::string> paraType; // ��¼�������� 
};

struct FunctionMessage {  // ����һ��������������Ϣ 
    std::string funcName; // ������ 
    int lineId;           // ���������������� vector �е��±� 
    std::vector<std::string> returnType;  // ��ʱ��������Ҫ�������ͼ�� 
    std::vector<Parameter> parameterList; // ���μ�¼���в�����Ϣ 
};

struct IfMessage {   // ��¼ If ����������Ϣ 
    int lineId;      // if ���ڵ��±��� 
    int elseLineId;  // Ĭ�� ���� -1 ��ʾû����֮ƥ��� else 
    int endifLineId; // endif ���б�ţ�Ĭ��Ϊ -1 
};

struct ForMessage {   // ��¼ For ����������Ϣ 
    int lineId;       // for ���ڵ� vector �±�� 
    int endforLineId; // endfor ���ڵ� vector �±�� 
    
    SyntaxWordList leftValue;  // �Ⱥ�ǰ����ֵ���� 
    SyntaxWordList rightValue; // �Ⱥź�ĳ�ʼ��ֵ 
    SyntaxWordList finalValue; // ����ֵ 
    SyntaxWordList stepValue;  // ���� 
};

struct WhileMessage {
    int lineId;         // ��¼ while �����е��±� 
    int endwhileLineId; // ��¼ endwhile �����е��±� 
    
    SyntaxWordList checkValue; // ÿ�α��������ֵ 
};

struct DefineMessage {
    std::vector<std::string> nameList; // ����ı��������� 
    std::vector<std::string> varType;  // ����������Ϣ 
};

struct SetMessage {
    SyntaxWordList leftValue;  // �Ⱥ�ǰ����ֵ 
    SyntaxWordList rightValue; // �Ⱥź����ֵ���ַ�����ָ����ֵ 
};

struct WriteMessage {
    SyntaxWordLineList leftValues; // ��¼ÿһ����Ҫ���������ֵ 
};

struct WriteCharMessage {
    SyntaxWordLineList leftValues; // ��¼ÿһ����Ҫ���������ֵ 
};
*/ 
