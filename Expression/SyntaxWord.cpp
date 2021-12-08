#include "SyntaxWord.h"

SyntaxWord::SyntaxWord(
    std::string raw,
    SyntaxWordType type
): mRaw(raw), mType(type) {
    // ��ʼ��һ���ʷ���Ԫ 
}

std::string SyntaxWord::getRaw() const {
    return mRaw;
}

SyntaxWord::SyntaxWordType
    SyntaxWord::getType() const {
    return mType;
}

