#include <algorithm>
#include <iostream>

#include "File.h"
#include "Utility.h"

File::File(std::string fileName) { // 文件一定要有文件名 
    mFileName = fileName;
}

std::string File::getObjectName() const {
    return mFileName;
}

std::string File::getObjectType() const { // "DIR" / "FILE"
    return "FILE";
}

void File::changeObjectName(std::string newName) { // 改名之前要保证当前这个名字没有被占用 
    mFileName = newName;
}

int File::getLineCount() const { // 文件中的行数 
    return mText.size();
}

std::string File::getLineById(int index) const {
    int lineId = getRealLineId(index); // 返回 vector 中的存储位置 
    if(lineId == EOF) {
        return "<LINE_NOT_FOUND>";
    }else {
        return mText[lineId]; 
    }
}

bool File::insertLineBeforeId(int index, std::string newLine) {
    int lineCnt = getLineCount();
    if(lineCnt != EOF) {
        mText.insert(mText.begin() + index, newLine); // 在某行前插入行 
        return true;
    }
    return false;
}

int File::getRealLineId(int index) const {
    int lineCnt = getLineCount();
    if(0 <= index && index < lineCnt) { // 行号从 0 开始 
        return index;
    }
    if(-lineCnt <= index && index < 0) { // 行号从 - lineCnt 开始 
        return index + lineCnt;
    }
    return EOF; // 没找到对应的行 
}

void File::show(int from, int to) const {
    int lineCnt = getLineCount();
    from = getRealLineId(from);
    to   = getRealLineId(to);   // 计算得到实际的下标 
    std::cout << "---------- " << getObjectName();
    std::cout << " " << getLineMessage(from, to) << " ----------"; // 获得行号信息 
    std::cout << std::endl;
    if(from > to) {
        std::swap(from, to);
    }
    if(from == EOF) { // 无法输出 
        return;
    }
    int prelen = Utility::bitCount(to) + 1; // 统计有多少个十进制位 
    if(0 <= from && from <= to && to < lineCnt) { // 在可显示范围内 
        for(int i = from; i <= to; i ++) {
            showLine(prelen, i);
        }
    }
}

void File::showLine(int prelen, int lineId) const {
    std::string sLineId = std::to_string(lineId); // 十进制整数 
    while(sLineId.length() < prelen) sLineId = " " + sLineId;
    sLineId += " |";
    
    std::cout << sLineId << mText[lineId] << std::endl;
}

void File::append(std::string newLine) {
    mText.push_back(newLine);
}

std::string File::getLineMessage(int from, int to) const {
    int lineCnt = getLineCount();
    if(from == 0 && to == lineCnt - 1) {
        return "<ALL from " + std::to_string(lineCnt) + " page(s)>";
    }else {
        return "<" + std::to_string(from) + " to " + 
            std::to_string(to) + " from " + std::to_string(lineCnt) + " page(s)>";
    }
}

void File::deleteLineById(int index) { // 删除一行内容 
    index = getRealLineId(index);
    if(index != EOF) {
        mText.erase(mText.begin() + index);
    }
}

