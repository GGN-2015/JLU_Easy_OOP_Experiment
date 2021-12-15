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
    for(auto ptr: mSubObjects) { // �ݹ����������Ӷ��� 
        delete ptr;
    }
}

bool Folder::appendObject(IObject* iObject) { // ��β��׷��һ���Ӷ��� 
    if(!exist(iObject -> getObjectName())) {
        mSubObjects.push_back(iObject);
        return true; // ����ɹ� 
    }else {
        return false; // �ļ�����ͻ����ʧ�� 
    }
}

bool Folder::exist(std::string fileName) const {
    return !(getIdByName(fileName) == FILE_NOT_FOUND);
}

int Folder::getIdByName(std::string fileName) const {
    // �����ļ�������ö����������е��±� 
    for(int i = 0; i < (int)mSubObjects.size(); i ++) {
        if(mSubObjects[i] -> getObjectName() == fileName) {
            return i;
        }
    }
    return FILE_NOT_FOUND; // û�ҵ� 
}

bool Folder::deleteObjectByName(std::string fileName) {
    if(exist(fileName)) { // �ļ����ڣ�����ɾ�� 
        int id = getIdByName(fileName);
        delete mSubObjects[id];
        mSubObjects.erase(mSubObjects.begin() + id); // ��Ҫ��������Ҫɾ������ 
    }else {
        return false; // ��Ϊ�ļ������ڣ������޷�ɾ�� 
    }
}

int Folder::giveSonTo(Folder& folder, std::string fileName) {
    if(&folder == this) {
        // Ŀ���ļ��к͵�ǰ�ļ�����ͬһ���ļ��� 
        return 0; // ֱ�ӳɹ� 
    }
    if(!exist(fileName)) {
        return FILE_NOT_FOUND; // ��ǰ�ļ�����û��������ֵ��ļ� 
    }
    if(folder.exist(fileName)) {
        return SAME_NAME_ERROR; // ����ƶ�����Ŀ���ļ������� 
    }
    // ��������Ϊ�����ƶ���ʵ���������һ���ļ����ƶ����Լ������ļ���Ҳ���� 
    // ��Ҫ��� shell ��ʱ����д��� 
    int id = getIdByName(fileName);
    folder.appendObject(this -> mSubObjects[id]); // ����µ����� 
    mSubObjects.erase(mSubObjects.begin() + id);  // ���ԭ�������� 
    return 0;
}

int Folder::changeSubName(std::string nameFrom, std::string nameTo) {
    // �޸���Ŀ¼���ļ������� 
    if(!exist(nameFrom)) {
        return FILE_NOT_FOUND; // û���ҵ���Ӧ���ļ� 
    }
    if(exist(nameTo)) {
        return SAME_NAME_ERROR; // ����޸Ļᵼ���������� 
    }
    // ���ִ�е�������˵�������޸� 
    int id = getIdByName(nameFrom);
    mSubObjects[id] -> changeObjectName(nameTo);
}

IObject* Folder::getObjectByName(std::string fileName) {
    int id = getIdByName(fileName);
    if(id == FILE_NOT_FOUND) { // �ļ��Ҳ��� 
        return nullptr;
    }else {
        return mSubObjects[id];
    }
}

void Folder::show(int from, int to) const {
    (const_cast<Folder*>(this)) -> sortObjects();
    from = getRealId(from);
    to   = getRealId(to);   // ���һ�������ϵ���Ϣ 
    if(from > to) {
        std::swap(from, to);
    }
    if(0 <= from && from <= to && to < getSubObjectCount()) {
        std::cout << "---------- [Folder] " << getObjectName() << " ---------- " << std::endl;
        int maxlen = 0; // ��¼� 
        int prelen = Utility::bitCount(to) + 1;
        for(int i = from; i <= to; i ++) {
            maxlen = std::max(maxlen, (int)mSubObjects[i] -> getObjectName().length());
        }
        for(int i = from; i <= to; i ++) { // ��������ļ� 
            std::cout << Utility::fillSpace(std::to_string(i), prelen);
            std::cout << " | " << Utility::fillSpace(mSubObjects[i] -> getObjectName(), maxlen + 1);
            std::cout << " | " << Utility::fillSpace(mSubObjects[i] -> getObjectType(), 5);
            std::cout << std::endl;
        }
    }
}

int Folder::getSubObjectCount() const {
    return mSubObjects.size(); // ͳ���Ӷ���ĸ��� 
}

int Folder::getRealId(int index) const { // �����ʵ�±� 
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
    sort(mSubObjects.begin(), mSubObjects.end(), compareObject); // ���� 
}

bool Folder::compareObject(IObject* aObj, IObject* bObj) {
    if(aObj -> getObjectType() != bObj -> getObjectType()) {
        return aObj -> getObjectType() < bObj -> getObjectType();
    }
    return aObj -> getObjectName() < bObj -> getObjectName();
}

bool Folder::newFile(std::string fileName) {
    if(exist(fileName)) {
        return false; // �ļ������� 
    }
    return appendObject(new File(fileName));
}

bool Folder::newDir(std::string fileName) {
    if(exist(fileName)) {
        return false; // �ļ������� 
    }
    return appendObject(new Folder(fileName));
}
