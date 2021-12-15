#include <algorithm>
#include <iostream>

#include "Folder.h"
#include "File.h"
#include "Utility.h"

std::string Folder::getObjectName() const {
    return mFolderName;
}

void Folder::changeObjectName(std::string newName) {
    mFolderName = newName;
}

std::string Folder::getObjectType() const {
    return "DIR";
}

Folder::Folder(std::string fileName) {
    mFolderName = fileName;
}

Folder::~Folder() {
    for(auto ptr: mSubObjects) { // 递归析构所有子对象 
        delete ptr;
    }
}

bool Folder::appendObject(IObject* iObject) { // 在尾部追加一个子对象 
    if(!exist(iObject -> getObjectName())) {
        mSubObjects.push_back(iObject);
        return true; // 插入成功 
    }else {
        return false; // 文件名冲突插入失败 
    }
}

bool Folder::exist(std::string fileName) const {
    return !(getIdByName(fileName) == FILE_NOT_FOUND);
}

int Folder::getIdByName(std::string fileName) const {
    // 根据文件名，获得对象在数组中的下标 
    for(int i = 0; i < (int)mSubObjects.size(); i ++) {
        if(mSubObjects[i] -> getObjectName() == fileName) {
            return i;
        }
    }
    return FILE_NOT_FOUND; // 没找到 
}

bool Folder::deleteObjectByName(std::string fileName) {
    if(exist(fileName)) { // 文件存在，可以删除 
        int id = getIdByName(fileName);
        delete mSubObjects[id];
        mSubObjects.erase(mSubObjects.begin() + id); // 既要析构，又要删除索引 
    }else {
        return false; // 因为文件不存在，所以无法删除 
    }
}

int Folder::giveSonTo(Folder& folder, std::string fileName) {
    if(&folder == this) {
        // 目标文件夹和当前文件夹是同一个文件夹 
        return 0; // 直接成功 
    }
    if(!exist(fileName)) {
        return FILE_NOT_FOUND; // 当前文件夹下没有这个名字的文件 
    }
    if(folder.exist(fileName)) {
        return SAME_NAME_ERROR; // 如果移动会在目标文件夹重名 
    }
    // 否则则认为可以移动，实际上如果把一个文件夹移动到自己的子文件夹也不行 
    // 需要设计 shell 的时候进行处理 
    int id = getIdByName(fileName);
    folder.appendObject(this -> mSubObjects[id]); // 添加新的索引 
    mSubObjects.erase(mSubObjects.begin() + id);  // 清楚原来的索引 
    return 0;
}

int Folder::changeSubName(std::string nameFrom, std::string nameTo) {
    // 修改子目录或文件的名字 
    if(!exist(nameFrom)) {
        return FILE_NOT_FOUND; // 没有找到对应的文件 
    }
    if(exist(nameTo)) {
        return SAME_NAME_ERROR; // 如果修改会导致重名错误 
    }
    // 如果执行到这里则说明可以修改 
    int id = getIdByName(nameFrom);
    mSubObjects[id] -> changeObjectName(nameTo);
}

IObject* Folder::getObjectByName(std::string fileName) {
    int id = getIdByName(fileName);
    if(id == FILE_NOT_FOUND) { // 文件找不到 
        return nullptr;
    }else {
        return mSubObjects[id];
    }
}

void Folder::show(int from, int to) const {
    (const_cast<Folder*>(this)) -> sortObjects();
    from = getRealId(from);
    to   = getRealId(to);   // 输出一个区间上的信息 
    if(from > to) {
        std::swap(from, to);
    }
    if(0 <= from && from <= to && to < getSubObjectCount()) {
        std::cout << "---------- [Folder] " << getObjectName() << " ---------- " << std::endl;
        int maxlen = 0; // 记录最长 
        int prelen = Utility::bitCount(to) + 1;
        for(int i = from; i <= to; i ++) {
            maxlen = std::max(maxlen, (int)mSubObjects[i] -> getObjectName().length());
        }
        for(int i = from; i <= to; i ++) { // 输出所有文件 
            std::cout << Utility::fillSpace(std::to_string(i), prelen);
            std::cout << " | " << Utility::fillSpace(mSubObjects[i] -> getObjectName(), maxlen + 1);
            std::cout << " | " << Utility::fillSpace(mSubObjects[i] -> getObjectType(), 5);
            std::cout << std::endl;
        }
    }
}

int Folder::getSubObjectCount() const {
    return mSubObjects.size(); // 统计子对象的个数 
}

int Folder::getRealId(int index) const { // 获得真实下标 
    int fileCnt = getSubObjectCount();
    if(0 <= index && index < fileCnt) {
        return index;
    }
    if(-fileCnt <= index && index < 0) {
        return index + fileCnt;
    }
    return FILE_NOT_FOUND;
}

void Folder::sortObjects() {
    sort(mSubObjects.begin(), mSubObjects.end(), compareObject); // 排序 
}

bool Folder::compareObject(IObject* aObj, IObject* bObj) {
    if(aObj -> getObjectType() != bObj -> getObjectType()) {
        return aObj -> getObjectType() < bObj -> getObjectType();
    }
    return aObj -> getObjectName() < bObj -> getObjectName();
}

bool Folder::newFile(std::string fileName) {
    if(exist(fileName)) {
        return false; // 文件名重名 
    }
    return appendObject(new File(fileName));
}

bool Folder::newDir(std::string fileName) {
    if(exist(fileName)) {
        return false; // 文件名重名 
    }
    return appendObject(new Folder(fileName));
}
