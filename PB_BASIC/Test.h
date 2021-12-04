#ifndef TEST_H
#define TEST_H

#include "SyntaxChecker.h"

class Test { // ≤‚ ‘ø‚ 
public:
    static void testStringStream();
    static void testNumicSyntax();
    static void testNameSyntax();
    static void testCommentSyntax();
    static void testOperatorSyntax();
    static void testSyntaxChecker(bool = true);
    static void testVarType();
    static void outputSyntaxWordList(const SyntaxWordList&);
};

#endif

