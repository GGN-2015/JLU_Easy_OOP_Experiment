#include <iostream>
#include <typeinfo>

#include "BraceSyntax.h"
#include "CommaSyntax.h"
#include "CommentSyntax.h"
#include "EmptySyntax.h"
#include "ErrorMgr.h"
#include "NameSyntax.h"
#include "NumicSyntax.h"
#include "OperatorSyntax.h"
#include "QuoteSyntax.h"

#include "StringStream.h"
#include "SyntaxChecker.h"

SyntaxChecker::SyntaxChecker() {
    mAllSyntax.push_back(CommentSyntax    ::getInstance()); // ע��һ��Ҫ����������ȼ��� 
    mAllSyntax.push_back(QuoteSyntax      ::getInstance()); // ˫�������� 
    mAllSyntax.push_back(LeftBraceSyntax  ::getInstance()); // ������ 
    mAllSyntax.push_back(RightBraceSyntax ::getInstance()); // ������ 
    mAllSyntax.push_back(CommaSyntax      ::getInstance()); // ���� 
    mAllSyntax.push_back(EmptySyntax      ::getInstance()); // �հ��ַ� 
    mAllSyntax.push_back(NameSyntax       ::getInstance()); // �ؼ��� �� ���� 
    mAllSyntax.push_back(NumicSyntax      ::getInstance()); // ��ֵ 
    mAllSyntax.push_back(OperatorSyntax   ::getInstance()); // ˫Ŀ����� 
}

SyntaxChecker::~SyntaxChecker() {
    // ����ʱ�����ͷſռ� 
}

int SyntaxChecker::syntaxCheck(std::string sline, SyntaxWordList& syntaxList, int lineId) const {
    syntaxList.clear();     // ���һ�� vector 
    StringStream ss(sline); // ����һ���ַ��� 
    
    while(!ss.empty()) {
        bool fail = true;
        for(auto ptr: mAllSyntax) {
            if(ptr -> check(ss)) { // �ɹ�ƥ����һ���﷨ 
                fail = false;
                int colId = ss.position(); // ��¼ƥ��λ�õ��к� 
                
                std::string stmp = ptr -> match(ss);
                if(ptr -> vital()) { // �������Ҫ���Ͳ�Ҫ����������ȥ 
                    syntaxList.push_back({lineId, colId, stmp, ptr -> getSyntaxName()});
                }
                break;
            }
        }
        if(fail) {
            char stmp[15]; sprintf(stmp, "%d", ss.position());
            ErrorMgr::getInstance().push(__FILE__, __LINE__, "�� " + std::string(stmp) + " ���޷����дʷ�����"); 
            return ss.position(); // �� ss.position λ��ƥ��ʧ�� 
        }
    }
    return -1; // �ɹ�����˴ʷ����� 
}


void SyntaxChecker::inputAndCheckSyntax(SyntaxWordLineList& swll) const {
    int rowCnt = 0;
    swll.clear();
    while(!std::cin.eof()) { // �������������Ļ� 
        std::string line;
        std::getline(std::cin, line); // �ӱ�׼����������һ������ 
        SyntaxWordList slist {};
        syntaxCheck(line, slist, rowCnt); // �����﷨��� 
        if(!ErrorMgr::getInstance().checkEmpty()) {
            ErrorMgr::getInstance().show(rowCnt); // ��ʾ������Ϣ 
            ErrorMgr::getInstance().clear();
            system("pause"); exit(0); // ���������ֹͣ�ʷ����� 
        }
        rowCnt ++;
        if(!slist.empty()) {
            swll.push_back(slist); // ��֤ÿһ�ж�������һ�����ţ����лᱻ���� 
        }
    }
}

SyntaxChecker& SyntaxChecker::getInstance() {
    static SyntaxChecker sc;
    return sc;
}
