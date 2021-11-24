// IMenu.h
#pragma once

#include <string>
#include <vector>

class Rect {
public:
    bool inRect(int r, int c) const { // check if a point in a rect
        return
            row <= r && r < row + height &&
            col <= c && c < col + width;
    }
    bool isMargin(int r, int c) const { // check if a point is on the margin of a rect
        bool rBorder = (r == row || r == row + height - 1);
        bool cBorder = (c == col || c == col + width - 1);
        return inRect(r, c) && (rBorder || cBorder);
    }
    int row, col, height, width; // describe a rectangle in the screen cache
};

class IMenu {
public:
    IMenu(const Rect&);
    virtual ~IMenu();
    virtual bool process(); // menu process determine

    virtual const Rect& getRect() const;
    virtual const std::string& getTitle() const;                 // get the title of the menu
    virtual const std::vector<std::string>& getTerms() const;   // get terms
    virtual int getActiveTermId() const;                         // return -1 means no active

protected:
    Rect mRect;
};
