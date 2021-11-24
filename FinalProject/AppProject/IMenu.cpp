// IMenu.cpp

#include <string>
#include <vector>

#include "IMenu.h"

IMenu::IMenu(const Rect& rect): mRect(rect) {}
IMenu::~IMenu() {}// just do nothing

const Rect& IMenu::getRect() const {
    static Rect rect = {0, 20, 20, 20}; // set the rect of the IMenu
    return rect;
}

bool IMenu::process() {
    return true;
}

const std::string& IMenu::getTitle() const {
    return "Title Undefined.";
}

const std::vector<std::string>& IMenu::getTerms() const {
    static std::vector<std::string> terms = {"Term 1", "Term 2"};
    return terms;
}

int IMenu::getActiveTermId() const {
    return -1;
}
