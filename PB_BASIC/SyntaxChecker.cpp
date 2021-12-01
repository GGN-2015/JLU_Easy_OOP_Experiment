#include <iostream>
#include <typeinfo>

#include "BraceSyntax.h"
#include "CommaSyntax.h"
#include "CommentSyntax.h"
#include "EmptySyntax.h"
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

int SyntaxChecker::syntaxCheck(std::string sline, SyntaxWordList& syntaxList) const {
    syntaxList.clear();     // ���һ�� vector 
    StringStream ss(sline); // ����һ���ַ��� 
    
    while(!ss.empty()) {
        bool fail = true;
        for(auto ptr: mAllSyntax) {
            if(ptr -> check(ss)) { // �ɹ�ƥ����һ���﷨ 
                fail = false;
                
                std::string stmp = ptr -> match(ss);
                if(ptr -> vital()) { // �������Ҫ���Ͳ�Ҫ����������ȥ 
                    syntaxList.push_back(SyntaxWord(stmp, ptr));
                }
                break;
            }
        }
        if(fail) {
            return ss.position(); // �� ss.position λ��ƥ��ʧ�� 
        }
    }
    return -1; // �ɹ�����˴ʷ����� 
}

