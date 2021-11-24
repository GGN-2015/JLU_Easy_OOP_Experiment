// ConsoleMgr.cpp
#include "windows.h"

#include "CharPixel.h"
#include "ConsoleMgr.h"
#include "CharColor.h"

#define DEBUG_MODE

#ifdef DEBUG_MODE
    #include <iostream> // for debug output
    #include <cstdlib>
#endif // DEBUG_MODE

ConsoleMgr& ConsoleMgr::getInstance() {
    static ConsoleMgr consoleMgr;
    return consoleMgr;
}

ConsoleMgr::~ConsoleMgr() { // destruction function
    for(int row = 0; row < mHeight; row ++) {
        delete[] charPixels[0][row];
        delete[] charPixels[1][row];
    }
    delete[] charPixels[0];
    delete[] charPixels[1];
}

bool ConsoleMgr::cursorDown() const {
    return keyDown(VK_LBUTTON); // left button of the key
}

bool ConsoleMgr::keyDown(int vkNoname) const {
    return  (GetAsyncKeyState(vkNoname) & 0x8000) ? 1:0; // check if a key is down
}

POINT ConsoleMgr::getCursorPosInConsole() const {
    POINT p = getCursorPos();
    RECT rect = getConsolePos();
    p.x -= rect.left;
    p.y -= rect.top;
    return p;
}

POINT ConsoleMgr::getCursorCharPosInConsole() const {
    POINT p = getCursorPosInConsole();
    p.x -= 5;  p.x /= 12; /// ! change this in new algorithm
    p.y -= 31; p.y /= 24;
    return p;
}

bool ConsoleMgr::checkCursorPosInScreen(POINT p) const {
    return true;
}

POINT ConsoleMgr::waitCursorClick(int sleepTime) const {
    POINT p;
    while(true) {
        if(keyDown(VK_LBUTTON) && checkUpon()) {
            p = getCursorCharPosInConsole();
            if(checkCursorPosInScreen(p)) { // Rin(0, p.x, mWidth * 2) && Rin(0, p.y, mHeight)
                break;
            }
        }
        Sleep(20);
    }
    Sleep(sleepTime);
    #define DEBUG_MODE
        //! need to debug
    #endif // DEBUG_MODE
    return p;
}

bool ConsoleMgr::checkUpon() const {
    HWND hwndn = GetForegroundWindow();
    return hwnd == hwndn;
}

RECT ConsoleMgr::getConsolePos() const {
    RECT rect;
    GetWindowRect(hwnd, &rect); // windows API get the position of the console
    return rect;
}

POINT ConsoleMgr::getCursorPos() const { // get the raw cursor position
    POINT p;
    GetCursorPos(&p);
    return p;
}

void ConsoleMgr::setCharPixel(const CharPixel& cp, int row, int col) const {
    if(inScreen(row, col)) {
        charPixels[currentScreenId][row][col] = cp; // just copy is ok
    }
}

bool ConsoleMgr::inScreen(int row, int col) const {
    return
        0 <= row && row < mHeight &&
        0 <= col && col < mWidth; // check in X(row) and Y(col)
}

void ConsoleMgr::setOutputCursor(int row, int col) const { // set cursor pos
    COORD pos;
    pos.X = col * 2; pos.Y = row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void ConsoleMgr::setOutputColor(const CharColor& charColor) const { // set cursor color
    int colorId = charColor.getCharColorId();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colorId);
}

void ConsoleMgr::displayAll() { // display the chessboard in cache
    for(int row = 0; row < mHeight; row ++) {
        for(int col = 0; col < mWidth; col ++) {
            CharPixel  now = charPixels[currentScreenId][row][col];
            CharPixel last = charPixels[currentScreenId ^ 1][row][col];
            if(!now.equalTo(last)) { // two cache are not the same
                setOutputCursor(row, col);
                setOutputColor(now.getCharColor());
                now.outputChar();
            }
        }
    }
    currentScreenId ^= 1;
    clearCurrentScreen(); // clear current screen
}

void ConsoleMgr::clearCurrentScreen() {
    for(int row = 0; row < mHeight; row ++) {
        for(int col = 0; col < mWidth; col ++) {
            charPixels[currentScreenId][row][col] = CharPixel(); // make it to default
        }
    }
}

void ConsoleMgr::hideOutputCursor() const {
    CONSOLE_CURSOR_INFO i;
    i.bVisible = 0;
	i.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&i);// hide the cursor
}

void ConsoleMgr::fontInitialize() const {
    CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 24; // ! you need to change it in new versions
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

ConsoleMgr::ConsoleMgr() { // create a console manager
    modeInitialize();
    hideOutputCursor();

    hwnd = GetForegroundWindow(); // get this own window
    getWidthAndHeight();

    #ifdef DEBUG_MODE
        std::cout << "ConsoleMgr::ConsoleMgr() mWidth = " << mWidth;
        std::cout << ", mHeight = " << mHeight << std::endl; // output the screen size
        system("pause");
    #endif // DEBUG_MODE

    currentScreenId = 0;

    charPixels[0] = new CharPixel*[mWidth];
    charPixels[1] = new CharPixel*[mWidth];

    for(int row = 0; row < mHeight; row ++) {
        charPixels[0][row] = new CharPixel[mWidth];
        charPixels[1][row] = new CharPixel[mWidth]; // allocate memory

        for(int col = 0; col < mWidth; col ++) {
            const char now[] = {32, 32};
            // const char now[] = "¡õ"; // for test only
            const char nxt[] = {-1, -1};
            charPixels[0][row][col] = CharPixel(now); // clear in the first round
            charPixels[1][row][col] = CharPixel(nxt);
        }
    }
}

void ConsoleMgr::modeInitialize() const {
    DWORD mode;
	GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE),&mode);
    mode &= ~ENABLE_QUICK_EDIT_MODE;  // delete: quick insertion
    mode &= ~ENABLE_INSERT_MODE;      // delete: insertion
    mode &= ~ENABLE_MOUSE_INPUT;
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE),mode);
}

void ConsoleMgr::getWidthAndHeight() { // get the width and the height and save to mWidth/mHeight
    HANDLE hOut;
    CONSOLE_SCREEN_BUFFER_INFO bInfo;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE); // get the infomation of the windows
    GetConsoleScreenBufferInfo(hOut, &bInfo);

    mWidth  = bInfo.dwMaximumWindowSize.X / 2;
    mHeight = bInfo.dwMaximumWindowSize.Y / 2; // this will be modified later, by other algorithm
}
