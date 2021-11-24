// CharPixel.cpp
#include <cstdio>

#include "CharPixel.h"
#include "CharColor.h"

const CharColor defaultColor = CharColor(Color(Color::BLACK), Color(Color::WHITE));

CharPixel::CharPixel(const char* bytes, CharColor charColor):
    mCharColor(charColor) {
    for(int i = 0; i < CHAR_LENGTH; i ++) {
        mBytes[i] = bytes[i]; // copy the char and store it
    }
}

CharPixel::CharPixel(const char* bytes): // use default color
    mCharColor(defaultColor) {
    for(int i = 0; i < CHAR_LENGTH; i ++) {
        mBytes[i] = bytes[i]; // copy the char and store it
    }
}

CharPixel::CharPixel(): mCharColor(defaultColor) {
    for(int i = 0; i < CHAR_LENGTH; i ++) {
        mBytes[i] = 0; // default value of mBytes is zero
    }
}

void CharPixel::outputChar() const {
    for(int i = 0; i < CHAR_LENGTH; i ++) {
        putchar(mBytes[i]); // output the char to the screen
    }
}

bool CharPixel::equalTo(const CharPixel& rhs) const {
    for(int i = 0; i < CHAR_LENGTH; i ++) {
        if(mBytes[i] != rhs.mBytes[i]) {
            return false; // check if char is the same
        }
    }
    // check if color is the same
    return getCharColor().getCharColorId() == rhs.getCharColor().getCharColorId();
}

const CharColor& CharPixel::getCharColor() const { // get the color of CharPixel
    return mCharColor;
}
