// ViewMgr.cpp

#include <cstdio>
#include <cstdlib>

#include "CharPixel.h"
#include "ConsoleMgr.h"
#include "IMenu.h"
#include "ViewMgr.h"

typedef char Bytes[2]; // Bytes = char[2]
const Bytes EMPTY_SQUARE = {-95, -11};

ViewMgr& ViewMgr::getInstance() {
    static ViewMgr viewMgr;
    return viewMgr;
}

void ViewMgr::drawBox(const Rect& rect) const {
    for(int i = 0; i < rect.height; i ++) {
        for(int j = 0; j < rect.width; j ++) {
            int row = i + rect.row;
            int col = j + rect.col;
            Bytes bytes = {32, 32};
            if(rect.isMargin(row, col)) {
                for(int t = 0; t < CHAR_LENGTH; t ++) {
                    bytes[t] = EMPTY_SQUARE[t];
                }
            }else {
                // cover the empty space with space
            }
            ConsoleMgr::getInstance().setCharPixel(CharPixel(bytes), row, col);
        }
    }
}

void ViewMgr::loadMenu(const IMenu* imenu) const {

}

void ViewMgr::changeTitle(const char* title) const {
    char* stmp = new char[(int)strlen(title) + 7];
    sprintf(stmp, "title %s", title); // use system function from stdlib.h to change the title
    system(stmp);
    delete[] stmp;
}

void ViewMgr::updateScreen() const {
    ConsoleMgr::getInstance().displayAll(); // use consoleMgr to output the message
}
