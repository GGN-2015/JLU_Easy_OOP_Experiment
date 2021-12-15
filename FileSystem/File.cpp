#include <algorithm>
#include <iostream>

#include "File.h"
#include "Utility.h"

File::File(std::string fileName) { // �ļ�һ��Ҫ���ļ��� 
    mFileName = fileName;
}

std::string File::getObjectName() const {
    return mFileName;
}

std::string File::getObjectType() const { // "DIR" / "FILE"
    return "FILE";
}

void File::changeObjectName(std::string newName) { // ����֮ǰҪ��֤��ǰ�������û�б�ռ�� 
    mFileName = newName;
}

int File::getLineCount() const { // �ļ��е����� 
    return mText.size();
}

std::string File::getLineById(int index) const {
    int lineId = getRealLineId(index); // ���� vector �еĴ洢λ�� 
    if(lineId == EOF) {
        return "<LINE_NOT_FOUND>";
    }else {
        return mText[lineId]; 
    }
}

bool File::insertLineBeforeId(int index, std::string newLine) {
    int lineCnt = getLineCount();
    if(lineCnt != EOF) {
        mText.insert(mText.begin() + index, newLine); // ��ĳ��ǰ������ 
        return true;
    }
    return false;
}

int File::getRealLineId(int index) const {
    int lineCnt = getLineCount();
    if(0 <= index && index < lineCnt) { // �кŴ� 0 ��ʼ 
        return index;
    }
    if(-lineCnt <= index && index < 0) { // �кŴ� - lineCnt ��ʼ 
        return index + lineCnt;
    }
    return EOF; // û�ҵ���Ӧ���� 
}

void File::show(int from, int to) const {
    int lineCnt = getLineCount();
    from = getRealLineId(from);
    to   = getRealLineId(to);   // ����õ�ʵ�ʵ��±� 
    std::cout << "---------- " << getObjectName();
    std::cout << " " << getLineMessage(from, to) << " ----------"; // ����к���Ϣ 
    std::cout << std::endl;
    if(from > to) {
        std::swap(from, to);
    }
    if(from == EOF) { // �޷���� 
        return;
    }
    int prelen = Utility::bitCount(to) + 1; // ͳ���ж��ٸ�ʮ����λ 
    if(0 <= from && from <= to && to < lineCnt) { // �ڿ���ʾ��Χ�� 
        for(int i = from; i <= to; i ++) {
            showLine(prelen, i);
        }
    }
}

void File::showLine(int prelen, int lineId) const {
    std::string sLineId = std::to_string(lineId); // ʮ�������� 
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

void File::deleteLineById(int index) { // ɾ��һ������ 
    index = getRealLineId(index);
    if(index != EOF) {
        mText.erase(mText.begin() + index);
    }
}

