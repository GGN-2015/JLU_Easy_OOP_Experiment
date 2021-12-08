#include <stack>

#include "Expression.h"
#include "ExpressionChecker.h"
#include "IMatcher.h"
#include "SyntaxWord.h"

ExpressionChecker* ExpressionChecker::spChecker = nullptr; // ��̬���� 

ExpressionChecker&
    ExpressionChecker::getInstance() { // ��ȡ���� 
    if(spChecker == nullptr) {
        spChecker = new ExpressionChecker;
    }
    return *spChecker;
}

void ExpressionChecker::release() { // �������ǰҪ�ͷſռ� 
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
) { // build �������㷨�Ĺؼ� 
    std::vector<Expression*> expList {}; // �õ�һ�� Expression ���� 
    while(posNow < length) {             // ���п�ƥ���Ԫ�� 
        bool matchSuc = false;
        for(IMatcher* matchPtr: mMatchers) { // ö������ƥ���� 
            if(matchPtr -> check(syntaxWordArray, length, posNow)) { // ��ƥ����ƥ�� 
                Expression* newExp = 
                    matchPtr -> match(syntaxWordArray, length, posNow);
                if(newExp == nullptr) {
                    // TODO: �˴�Ӧ�ý��д�����Ϣ���� 
                    break;
                }else {
                    expList.push_back(newExp);
                    matchSuc = true;
                    break;
                }
            }
        }
        if(!matchSuc) {
            // TODO: posNow ���޷�����ƥ�䣬���� 
        }
    }
    // ��ʱ�õ��� expList Ҫ����˫Ŀ��������кϲ� 
    std::stack<Expression*> operators;
    std::stack<Expression*> values;
    
    for(Expression* expPtr: expList) {
        if(expPtr -> isOperator()) { // �ж��ǲ���˫Ŀ����� 
            while(!operators.empty() && operators.top() -> degree() >= expPtr -> degree()) {
                // ��������ջ����Ԫ�أ��������ȼ����ڵ�ǰԪ�أ���ջ 
                Expression* newExp = new Expression(
                    operators.top() -> getSyntaxWord(), 
                    Expression::ExpressionType::EXP_OPERATION
                );
                operators.pop();
                if(values.size() < 2) {
                    // TODO: �˴�Ӧ�ñ���������������� 
                }
                Expression* right = values.top(); values.pop();
                Expression* left  = values.top(); values.pop();
                newExp -> addSon(left);
                newExp -> addSon(right); // ���ν��������ӹ��� 
                values.push(newExp);
            }
            operators.push(expPtr);
        }else {
            values.push(expPtr);
        }
    }
}

