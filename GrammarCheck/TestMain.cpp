#include <iostream>
#include <string>
#include <vector>

#include "Grammar.h"
#include "GrammarTree.h"

std::vector<std::string> svec;

int main(int argc, char** argv) {
    Grammar::inputText("SyntaxList.ssv", svec);
    int pos = 0;
    GrammarTree* grammarTree = Grammar::getInstance().match(svec, "<≥Ã–ÚEOF>", pos);
    if(grammarTree != nullptr) {
        std::cout << "∆•≈‰≥…π¶ maxPos = " << Grammar::getInstance().getMaxPos() << std::endl;
        //grammarTree -> show(); // œ‘ æ∆•≈‰ ˜ 
    }else {
        std::cout << "∆•≈‰ ß∞‹ maxPos = " << Grammar::getInstance().getMaxPos() << std::endl;
    }
    return 0;
}

