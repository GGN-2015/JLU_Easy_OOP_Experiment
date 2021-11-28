#include <string>
#include <vector>

#include "App.h"
#include "Controller.h"
#include "LoadMenu.h"
#include "View.h"

std::string LoadMenu::getTitle() const {
    return "LoadMenu";
}

const std::vector<std::string>& LoadMenu::getTerms() const {
    static std::vector<std::string> terms;
    terms.clear();
    terms = App::getStorageList(); // ��ȡ�浵�ļ����� 
    terms.push_back("Back");       // �ص����˵� 
    return terms;
}

void LoadMenu::show() const {
    View::showLoadMenu(this);
}

void LoadMenu::process() {
    Controller::processLoadMenu(this); 
}

