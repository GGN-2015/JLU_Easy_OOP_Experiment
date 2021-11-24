// View.h
// methods to output menus onto the screens
#pragma once

class Chessboard;
class Rect;
class IMenu;

class ViewMgr {
public:
    static ViewMgr& getInstance();                              // get the ViewMgr
    void loadMenu(const IMenu* imenu) const;                    // show menu in Terminal
    void loadChessboard(const Chessboard* chessboard) const;    // show a chessboard in Terminal

    void updateScreen() const;                               // update the whole screen
    void changeTitle(const char* title) const;

    void drawBox(const Rect& rect) const; // draw a box on the screen
private:
    ViewMgr() {} // private and do nothing

    ViewMgr(const ViewMgr&) = delete;
    ViewMgr& operator= (const ViewMgr&) = delete; // not allow to copy
};
