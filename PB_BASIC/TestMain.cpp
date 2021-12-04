#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <typeinfo>

#include "CommentSyntax.h"
#include "ErrorMgr.h"
#include "GrammarChecker.h"
#include "MemberMap.h"
#include "NameSyntax.h"
#include "NumicSyntax.h"
#include "OperatorSyntax.h"
#include "StringStream.h"
#include "SyntaxChecker.h"
#include "TypeMgr.h"   
#include "VarType.h"
#include "Test.h"

int main(int argc, char** argv) {
    SyntaxChecker& sc = SyntaxChecker::getInstance();
    SyntaxWordLineList swll;
    sc.inputAndCheckSyntax(swll);
    
    //GrammarChecker& gc = GrammarChecker::getInstance();
    //gc.checkGrammar(swll); // 进行语法检查 
	return 0;
}

