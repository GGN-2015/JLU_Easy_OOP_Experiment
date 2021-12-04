#include <iostream>
#include <string>
#include <vector>

#include "Grammar.h"
#include "GrammarTree.h"

std::vector<std::string> svec;

int main(int argc, char** argv) {
    Grammar::inputText("SyntaxList.ssv", svec);
    int pos = 0;
    GrammarTree* grammarTree = Grammar::getInstance().match(svec, "<����EOF>", pos);
    if(grammarTree != nullptr) {
        std::cout << "ƥ��ɹ� maxPos = " << Grammar::getInstance().getMaxPos() << std::endl;
        //grammarTree -> show(); // ��ʾƥ���� 
    }else {
        std::cout << "ƥ��ʧ�� maxPos = " << Grammar::getInstance().getMaxPos() << std::endl;
    }
    return 0;
}

