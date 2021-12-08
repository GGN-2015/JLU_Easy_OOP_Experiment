#include <algorithm>

#include "Expression.h"
#include "SyntaxWord.h"

Expression::Expression(
    SyntaxWord* syntaxWord,
    ExpressionType expType
): mSyntaxWord(syntaxWord), mExpressionType(expType) {
    // vector 默认为空 
}

void Expression::addSon(Expression* exp) {
    mSonList.push_back(exp);
}

const std::vector<Expression*>&
    Expression::getSonList() const {
        return mSonList;
}

bool Expression::isOperator() const {
    static std::vector<std::string> operators = {"+", "-", "*", "/", "%"};
    for(std::string opes: operators) {
        if(mSyntaxWord -> getRaw() == opes) { // 找到了，说明是双目运算符 
            return true;
        }
    }
    return false;
}

int Expression::degree() const {
    static std::vector<std::pair<std::string,int> > operators = {
        std::make_pair("+", 1), 
        std::make_pair("-", 1), 
        std::make_pair("*", 2), 
        std::make_pair("/", 2), 
        std::make_pair("%", 2)
    };
    for(auto opes: operators) {
        if(mSyntaxWord -> getRaw() == opes.first) {
            return opes.second;
        }
    }
    return 0;
}

SyntaxWord* Expression::getSyntaxWord() {
    return mSyntaxWord; 
}

