#pragma once

class Expression;

class IMatcher { // ³éÏóÆ¥ÅäÆ÷ 
public:
    virtual bool check(SyntaxWord**, int length, int posNow);         // ¼ì²âÄÜ·ñÆ¥Åä 
    virtual Expression* match(SyntaxWord**, int length, int& posNow); // ½øĞĞÆ¥Åä 
};

