#include <iostream>
#include <cstdlib>
#include <ctime>

#include "App.h" // App �������к��ļ���صĲ����Լ��������еĿ�� 
#include "Event.h"
#include "GameMenu.h"
#include "IMenu.h"
#include "MenuMgr.h"
#include "UnfinishedMenu.h"

const int App::mVersion = 20211125; // ��ǰ�İ汾�� 

App::App() {
    // �����ڲ��� App ������֯���֣���ʱ��û��ʲô��Ҫ���� 
}

void App::initialize() {
    system("title Tetris");
    system("cls");
    std::cout << " * App::initialize() ... " << std::endl;
    bool resource = checkResource();
    bool version  = checkVersion ();
    if(!resource) { // �����ļ���ȫ 
        std::cout << "App::initialize(): resource damaged!" << std::endl;
    }
    if(!version) { // �汾�� 
        std::cout << "App::initialize(): version not match with resource!" << std::endl;
    }
    system("pause");
    system("cls");
    Event::inActivate(); // �ս��� App ʱ����ʧ�� 
}

void App::run() { // �������� App 
    while(true) {
        IMenu* imenu = MenuMgr::getInstance().getActiveMenu();
        if(imenu == nullptr) break;
        else {
            imenu -> show();    // ��ʾҳ����Ϣ 
            imenu -> process(); // ����ҳ���¼� 
        }
    }
}

void App::terminate() {
    system("cls");
    saveData(); // ������д���ļ� 
    // system("pause");
}

bool App::checkResource() { // ��������ļ��Ƿ����� 
    std::cout << " * checking resource ... \t";
    std::cout << "[OK]" << std::endl;
    return true;
}

bool App::checkVersion() { // ���汾��Ϣ�Ƿ�ƥ�� 
    std::cout << " * checking version ... \t";
    std::cout << "[OK]" << std::endl;
    return true;
}
void App::saveData() { // д�������ļ� 
    std::cout << " * saving Data ... \t";
    std::cout << "[OK]" << std::endl;
}

std::string App::getDateTime(){
    char stime[256] = {0};
    
    time_t now_time;
    time(&now_time);
    
    strftime(stime, sizeof(stime), "%Y-%m-%d %H-%M-%S", localtime(&now_time));
    return stime;
}

int App::getVersion() {
    return mVersion;
}

void App::saveGameMenu(const GameMenu* gameMenu) {
    std::string fileName = "./storage/" + getDateTime() + ".dat";  // getDateTime ��ȡ���ں�ʱ�� 
    FILE* fp = fopen(fileName.c_str(), "wb");       // ����Ϸ����д���ļ� 
    
    fwrite(&mVersion, sizeof(int), 1, fp);          // �����Ϸ�İ汾�� 
    fwrite(&CHESSBOARD_HEIGHT, sizeof(int), 1, fp);
    fwrite(&CHESSBOARD_WIDTH , sizeof(int), 1, fp); // �����Ϸ���̵ĳ��Ϳ� 
    
    for(int i = 0; i < CHESSBOARD_HEIGHT; i ++) {
        for(int j = 0; j < CHESSBOARD_WIDTH; j ++) {
            // ��������е�ÿһ��λ�õĶ�����ֵ 
            int val = gameMenu -> getChessboard() -> getPosColor(i, j); // ��¼�Ѿ��̻�����Ϸ���� 
            fwrite(&val, sizeof(int), 1, fp);          // ���һ������������ 
        }
    }
    
    int scoreNow = gameMenu -> getScore(); // �����ǰ�ĵ÷� 
    fwrite(&scoreNow, sizeof(int), 1, fp);
    fclose(fp);
}

void App::loadGameMenu(std::string fileName, GameMenu* gameMenu) { // ���ļ�������Ϸ 
    FILE* fpin = fopen(fileName.c_str(), "rb");
    
    if(fpin == nullptr) {
        MenuMgr::getInstance().pushMenuStack(new UnfinishedMenu("LoadFileError"));
        return; // TODO: ����Ӧ����ʾһ���ļ�����ʧ�ܵ�ҳ�� 
    }
    
    int sVersion; fread(&sVersion, sizeof(int), 1, fpin); // ����汾�� 
    
    if(sVersion > getVersion()) { // ����汾�ȵ�ǰ�汾�� 
        MenuMgr::getInstance().pushMenuStack(new UnfinishedMenu("LoadVersionError"));
        return; // TODO: ����Ӧ����ʾһ���ļ�����ʧ�ܵ�ҳ�� 
    }
    
    int chessboard_height; fread(&chessboard_height, sizeof(int), 1, fpin);
    int chessboard_width;  fread(&chessboard_width , sizeof(int), 1, fpin);
    
    if(
        chessboard_height != CHESSBOARD_HEIGHT ||
        chessboard_width  != CHESSBOARD_WIDTH
    ) {
        MenuMgr::getInstance().pushMenuStack(new UnfinishedMenu("ChessboardSizeError"));
        return; // TODO: ����Ӧ����ʾһ���ļ�����ʧ�ܵ�ҳ�� 
    }
    
    for(int i = 0; i < CHESSBOARD_HEIGHT; i ++) {
        for(int j = 0; j < CHESSBOARD_WIDTH; j ++) {
            int color;
            fread(&color, sizeof(int), 1, fpin); // ����һ��λ�õ���ɫ 
            gameMenu -> getChessboard() -> setPosColor(i, j, color);
        }
    }
    
    int scoreNow; 
    fread(&scoreNow, sizeof(int), 1, fpin); // ����һ����ǰ�ɼ� 
    gameMenu -> setScore(scoreNow);
    
    // ����ɹ����ͱ���ʾʲôҳ���� 
}

const std::vector<std::string>& App::getAboutMessage() {
    char sVersion[15]; sprintf(sVersion, "%d", mVersion); // ��ȡ�汾�� 
    
    static std::vector<std::string> terms
    {
        "Presented by GGN_2015",
        "", // �м��һ�� 
        "Version:" + std::string(sVersion)
    };
    return terms;
}

