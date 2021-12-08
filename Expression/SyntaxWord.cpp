#include "SyntaxWord.h"

SyntaxWord::SyntaxWord(
    std::string raw,
    SyntaxWordType type
): mRaw(raw), mType(type) {
    // 初始化一个词法单元 
}

std::string SyntaxWord::getRaw() const {
    return mRaw;
}

SyntaxWord::SyntaxWordType
    SyntaxWord::getType() const {
    return mType;
}

