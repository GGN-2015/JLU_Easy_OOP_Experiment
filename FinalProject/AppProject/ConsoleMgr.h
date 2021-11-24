// ConsoleMgr.h
// this header file can only be included by ViewMgr.cpp
// many console API is create in this file
#pragma once

#include "windows.h" // using hwnd for windows

class CharColor;
class CharPixel;

class ConsoleMgr {
public:
    static ConsoleMgr& getInstance();   // there is only one ConsoleMgr
    void displayAll();                  // output all the message on the console screen
    void setCharPixel(const CharPixel& cp, int row, int col) const; // set a pixel on the screen cache

    POINT getCursorPos() const; // get the raw cursor position
    bool cursorDown() const;
    RECT getConsolePos() const;

private:
    ConsoleMgr(); // create console manager with a default char color
    ~ConsoleMgr();

    bool keyDown(int vkNoname) const;
    POINT waitCursorClick(int sleepTime = 200) const; // wait for cursor click
    bool checkUpon() const; // check if the console is on the top of the windows
    POINT getCursorCharPosInConsole() const;
    bool checkCursorPosInScreen(POINT p) const;

    void hideOutputCursor() const;
    POINT getCursorPosInConsole() const;

    void modeInitialize() const;
    void fontInitialize() const;

    ConsoleMgr(const ConsoleMgr&) = delete;
    ConsoleMgr& operator= (const ConsoleMgr&) = delete; // you are not allowed to copy a manager

    void setOutputCursor(int row, int col) const;          // set the position of the output cursor
    void setOutputColor(const CharColor& charColor) const; // change the color of output cursor

    void clearCurrentScreen(); // clear new screen cache (after output a cache)
    void getWidthAndHeight();

    bool inScreen(int row, int col) const; // check if a position is in screen

    HWND hwnd;

    int mHeight, mWidth;       // the size of the console screen
    CharPixel** charPixels[2]; // record all the

    int currentScreenId;       // => 0 or 1, shows the screen cache that will be shown
};
