#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Grammar.h"
#include "GrammarTree.h"

Grammar::Grammar(std::string fileName) {
    maxPos = 0;
    std::ifstream fin(fileName);
    if(!fin.is_open()) {
        std::cout << " - 无法打开语法文件 " << fileName << std::endl;
        quit();
    }else {
        while(!fin.eof()) { // 只要还能读取内容 
            std::string lineMsg, stmp, unfinishedName; // unfinishedName 非终结符名字 
            std::getline(fin, lineMsg);                // 读出一行内容 
            std::stringstream ss; ss << lineMsg;       // 使用 stingstream 拆分 
            std::vector<std::string> svec;             // 记录分割后的内容 
            while(ss >> stmp) {
                svec.push_back(stmp);
            }
            if(svec.size() == 0) { // 不处理空行 
                continue; 
            }
            if(svec.size() <= 2) {
                std::cout << " - 一行内容不足两个，内容为" << std::endl;
                for(auto str: svec) std::cout << " " << str;
                std::cout << std::endl;
                quit();
            }
            if(!isUnfinished(svec[0])) {
                std::cout << " - 一行的第一个符号不是终结符 " << std::endl;
                for(auto str: svec) std::cout << " " << str;
                std::cout << std::endl;
                quit();
            }
            if(svec[1] != "::=") {
                std::cout << " - 一行的第二个符号不是 ::= 符号 " << std::endl;
                for(auto str: svec) std::cout << " " << str;
                std::cout << std::endl;
                quit();
            }
            unfinishedName = svec[0];
            svec.erase(svec.begin());
            svec.erase(svec.begin()); // 连续删除前两个元素 
            if(mMatchMethods.count(unfinishedName)) {
                // 已经存在至少一种匹配方式 
                mMatchMethods[unfinishedName].push_back(svec);
            }else {
                // 还不存在匹配方式 
                mMatchMethods[unfinishedName] = {};
                mMatchMethods[unfinishedName].push_back(svec);
            }
        }
        // 语法文件读取成功 
        std::cout << " - 语法文件 " << fileName << " 读取成功" << std::endl;
        // outputMap();
        fin.close(); 
    }
}

bool Grammar::isUnfinished(std::string str) {
    return 
        str.length() >= 2 && 
        str[0] == '<' && 
        str[str.length() - 1] == '>'; // 检测是否是非终结符 
}

void Grammar::quit() {
    std::cout << " - 语法检查终止" << std::endl;
    system("pause"); exit(0);
}

Grammar& Grammar::getInstance() {
    static Grammar grammar("Grammar.txt");
    return grammar;
}

void Grammar::outputMap() const {
    for(auto vecvec: mMatchMethods) {
        std::cout << vecvec.first << " ::= " <<  std::endl;
        for(auto vec: vecvec.second) {
            std::cout << "    ";
            for(auto str: vec) std::cout << str << "\t";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

GrammarTree* Grammar::match(std::vector<std::string> svec, std::string matchName, int& pos) {
    // std::cout << "pos = " << pos << " " << matchName << std::endl;
    if(pos >= svec.size()) {
        return nullptr; // 匹配过头了 
    }
    if(!isUnfinished(matchName)) {
        if(svec[pos] == matchName) {
            maxPos = std::max(maxPos, pos);
            pos ++;
            return new GrammarTree(matchName, 0, pos - 1); // 返回抽象语法树 
        }else {
            return nullptr; // 匹配失败 
        }
    }
    // 从 pos 位置开始匹配一个文法符号串 
    if(!mMatchMethods.count(matchName)) {
        std::cout << " -  匹配失败 " << matchName << " 未定义 " << std::endl;
        std::cout << " pos = " << pos << std::endl;
        exit(0); // 致命错误，说明语法定义的有问题 
    }else {
        int methodCnt = 0;
        for(auto method: mMatchMethods[matchName]) {
            std::vector<std::string>& mthd = method; // 第二个参数是一个 vector 
            GrammarTree* grammarTree = new GrammarTree(matchName, methodCnt, pos);
            int posNow = pos; // 暂时存储一份 pos 
            bool flag = true; // 判断是否出现了失配 
            for(auto str: mthd) {
                GrammarTree* subGrammarTree = match(svec, str, pos); // 子语法树 
                if(subGrammarTree != nullptr) {
                    // 为抽象语法树新增一个儿子节点 
                    grammarTree -> addSon(subGrammarTree);
                }else {
                    flag = false; // 匹配失败 
                }
                if(!flag) {
                    break; // 匹配失败需要回溯 
                }
            }
            if(flag) {
                return grammarTree;  // 匹配成功不需要回溯 
            }else {
                delete grammarTree;
                pos = posNow; // 使用其他方法继续匹配 
            }
            methodCnt ++;
        }
        return nullptr; // 无论如何都无法匹配，回溯 
    }
}

int Grammar::getMaxPos() const { // 获得终结符的最大匹配位置 
    return maxPos;
}

void Grammar::inputText(std::string fileName, std::vector<std::string>& svec) {
    svec.clear();
    std::ifstream fin(fileName);
    if(!fin.is_open()) {
        std::cout << " - 无法打开语法文件 " << fileName << std::endl;
        quit();
    }else {
        std::string stmp;
        while(fin >> stmp) {
            svec.push_back(stmp); // 向尾部追加符号 
        }
        fin.close();
    }
}

