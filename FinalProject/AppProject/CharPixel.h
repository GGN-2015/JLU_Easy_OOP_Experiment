// CharPixel.h
#pragma once

#include "CharColor.h"

const int CHAR_LENGTH = 2;

class CharPixel {
public:
    CharPixel();
    CharPixel(const char* bytes);           // create with default color
    CharPixel(const char* bytes, CharColor charColor); // create a CharPixel

    void outputChar() const;
    bool equalTo(const CharPixel& rhs) const; // check whether two pixel are the same
    const CharColor& getCharColor() const;

private:
    CharColor mCharColor;
    char mBytes[CHAR_LENGTH] {};
};
