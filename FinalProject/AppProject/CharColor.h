// CharColor.h
#pragma once

class Color {
public:
    enum BaseColor {
        BLACK=0, BLUE=1, GREEN=2, CYAN=3, RED=4, PURPLE=5, YELLOW=6, WHITE=7, LIGHT=8
    };
    Color(BaseColor baseColor, bool isLight = false); // create color

    int getColorId() const;

private:
    int colorId;
};

class CharColor {
public:
    CharColor(Color background, Color foreground); // get char color by color

    int getCharColorId() const;

    Color getBackgroundColor() const;
    Color GetForegroundColor() const; // They are not often used

private:
    Color mBackground, mForeground;
};
