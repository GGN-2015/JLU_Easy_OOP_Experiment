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
        std::cout << " - �޷����﷨�ļ� " << fileName << std::endl;
        quit();
    }else {
        while(!fin.eof()) { // ֻҪ���ܶ�ȡ���� 
            std::string lineMsg, stmp, unfinishedName; // unfinishedName ���ս������ 
            std::getline(fin, lineMsg);                // ����һ������ 
            std::stringstream ss; ss << lineMsg;       // ʹ�� stingstream ��� 
            std::vector<std::string> svec;             // ��¼�ָ������� 
            while(ss >> stmp) {
                svec.push_back(stmp);
            }
            if(svec.size() == 0) { // ��������� 
                continue; 
            }
            if(svec.size() <= 2) {
                std::cout << " - һ�����ݲ�������������Ϊ" << std::endl;
                for(auto str: svec) std::cout << " " << str;
                std::cout << std::endl;
                quit();
            }
            if(!isUnfinished(svec[0])) {
                std::cout << " - һ�еĵ�һ�����Ų����ս�� " << std::endl;
                for(auto str: svec) std::cout << " " << str;
                std::cout << std::endl;
                quit();
            }
            if(svec[1] != "::=") {
                std::cout << " - һ�еĵڶ������Ų��� ::= ���� " << std::endl;
                for(auto str: svec) std::cout << " " << str;
                std::cout << std::endl;
                quit();
            }
            unfinishedName = svec[0];
            svec.erase(svec.begin());
            svec.erase(svec.begin()); // ����ɾ��ǰ����Ԫ�� 
            if(mMatchMethods.count(unfinishedName)) {
                // �Ѿ���������һ��ƥ�䷽ʽ 
                mMatchMethods[unfinishedName].push_back(svec);
            }else {
                // ��������ƥ�䷽ʽ 
                mMatchMethods[unfinishedName] = {};
                mMatchMethods[unfinishedName].push_back(svec);
            }
        }
        // �﷨�ļ���ȡ�ɹ� 
        std::cout << " - �﷨�ļ� " << fileName << " ��ȡ�ɹ�" << std::endl;
        // outputMap();
        fin.close(); 
    }
}

bool Grammar::isUnfinished(std::string str) {
    return 
        str.length() >= 2 && 
        str[0] == '<' && 
        str[str.length() - 1] == '>'; // ����Ƿ��Ƿ��ս�� 
}

void Grammar::quit() {
    std::cout << " - �﷨�����ֹ" << std::endl;
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
        return nullptr; // ƥ���ͷ�� 
    }
    if(!isUnfinished(matchName)) {
        if(svec[pos] == matchName) {
            maxPos = std::max(maxPos, pos);
            pos ++;
            return new GrammarTree(matchName, 0, pos - 1); // ���س����﷨�� 
        }else {
            return nullptr; // ƥ��ʧ�� 
        }
    }
    // �� pos λ�ÿ�ʼƥ��һ���ķ����Ŵ� 
    if(!mMatchMethods.count(matchName)) {
        std::cout << " -  ƥ��ʧ�� " << matchName << " δ���� " << std::endl;
        std::cout << " pos = " << pos << std::endl;
        exit(0); // ��������˵���﷨����������� 
    }else {
        int methodCnt = 0;
        for(auto method: mMatchMethods[matchName]) {
            std::vector<std::string>& mthd = method; // �ڶ���������һ�� vector 
            GrammarTree* grammarTree = new GrammarTree(matchName, methodCnt, pos);
            int posNow = pos; // ��ʱ�洢һ�� pos 
            bool flag = true; // �ж��Ƿ������ʧ�� 
            for(auto str: mthd) {
                GrammarTree* subGrammarTree = match(svec, str, pos); // ���﷨�� 
                if(subGrammarTree != nullptr) {
                    // Ϊ�����﷨������һ�����ӽڵ� 
                    grammarTree -> addSon(subGrammarTree);
                }else {
                    flag = false; // ƥ��ʧ�� 
                }
                if(!flag) {
                    break; // ƥ��ʧ����Ҫ���� 
                }
            }
            if(flag) {
                return grammarTree;  // ƥ��ɹ�����Ҫ���� 
            }else {
                delete grammarTree;
                pos = posNow; // ʹ��������������ƥ�� 
            }
            methodCnt ++;
        }
        return nullptr; // ������ζ��޷�ƥ�䣬���� 
    }
}

int Grammar::getMaxPos() const { // ����ս�������ƥ��λ�� 
    return maxPos;
}

void Grammar::inputText(std::string fileName, std::vector<std::string>& svec) {
    svec.clear();
    std::ifstream fin(fileName);
    if(!fin.is_open()) {
        std::cout << " - �޷����﷨�ļ� " << fileName << std::endl;
        quit();
    }else {
        std::string stmp;
        while(fin >> stmp) {
            svec.push_back(stmp); // ��β��׷�ӷ��� 
        }
        fin.close();
    }
}

