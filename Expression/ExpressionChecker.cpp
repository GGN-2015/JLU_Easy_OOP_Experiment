#include <stack>

#include "Expression.h"
#include "ExpressionChecker.h"
#include "IMatcher.h"
#include "SyntaxWord.h"

ExpressionChecker* ExpressionChecker::spChecker = nullptr; // 静态单例 

ExpressionChecker&
    ExpressionChecker::getInstance() { // 获取单例 
    if(spChecker == nullptr) {
        spChecker = new ExpressionChecker;
    }
    return *spChecker;
}

void ExpressionChecker::release() { // 程序结束前要释放空间 
    delete spChecker;
    spChecker = nullptr;
}

void ExpressionChecker::addIMatcher(IMatcher* iMatcher) {
    mMatchers.push_back(iMatcher);
}

Expression* ExpressionChecker::build(
    SyntaxWord** syntaxWordArray, 
    int length, 
    int& posNow
) { // build 函数是算法的关键 
    std::vector<Expression*> expList {}; // 得到一个 Expression 序列 
    while(posNow < length) {             // 仍有可匹配的元素 
        bool matchSuc = false;
        for(IMatcher* matchPtr: mMatchers) { // 枚举所有匹配器 
            if(matchPtr -> check(syntaxWordArray, length, posNow)) { // 能匹配则匹配 
                Expression* newExp = 
                    matchPtr -> match(syntaxWordArray, length, posNow);
                if(newExp == nullptr) {
                    // TODO: 此处应该进行错误信息处理 
                    break;
                }else {
                    expList.push_back(newExp);
                    matchSuc = true;
                    break;
                }
            }
        }
        if(!matchSuc) {
            // TODO: posNow 处无法进行匹配，报错 
        }
    }
    // 此时得到了 expList 要根据双目运算符进行合并 
    std::stack<Expression*> operators;
    std::stack<Expression*> values;
    
    for(Expression* expPtr: expList) {
        if(expPtr -> isOperator()) { // 判断是不是双目运算符 
            while(!operators.empty() && operators.top() -> degree() >= expPtr -> degree()) {
                // 如果运算符栈中有元素，并且优先级高于当前元素，则弹栈 
                Expression* newExp = new Expression(
                    operators.top() -> getSyntaxWord(), 
                    Expression::ExpressionType::EXP_OPERATION
                );
                operators.pop();
                if(values.size() < 2) {
                    // TODO: 此处应该报错，算符操作数不够 
                }
                Expression* right = values.top(); values.pop();
                Expression* left  = values.top(); values.pop();
                newExp -> addSon(left);
                newExp -> addSon(right); // 依次将左子右子挂上 
                values.push(newExp);
            }
            operators.push(expPtr);
        }else {
            values.push(expPtr);
        }
    }
}

