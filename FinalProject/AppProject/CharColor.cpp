// CharColor.cpp
#include "CharColor.h"

Color::Color(BaseColor baseColor, bool isLight) {
    colorId = (int)baseColor;
    if(isLight) {
        colorId += BaseColor::LIGHT; // const value of make some color light
    }
}

int Color::getColorId() const {
    return this -> colorId;
}

CharColor::CharColor(Color background, Color foreground):
    mBackground(background), mForeground(foreground) {}  // just store the color of background and foreground

int CharColor::getCharColorId() const {
    return (mBackground.getColorId() << 4) | mForeground.getColorId();
}
