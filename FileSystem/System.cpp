#include <string>

#include "Folder.h"
#include "System.h"

System& System::getInstance() {
    static System sys;
    sys.mainFolder = new Folder("mainFolder");
    sys.folderStack.push(sys.mainFolder);
}

System::System() {
    
}

System::~System() {
    delete mainFolder; // ֱ��ɾ����Ŀ¼ 
}

void System::up() {
    if(folderStack.size() > 1) { // ���ٵñ�֤��Ŀ¼�������� 
        folderStack.pop();
    }
}

int System::down(std::string dirName) {
    if(!exist(dirName)) {
        return FILE_NOT_FOUND;
    }
    IObject* subObj = folderStack.top() -> getSubObjectByName(dirName);
    if(subObj -> getObjectType() == "DIR") {
        folderStack.push(dynamic_cast<Folder*>(subObj));
        return 0;
    }
    return -3;
}

int System::newFile(std::string fileName) {
    return folderStack.top() -> newFile(fileName);
}

int System::newDir(std::string fileName) {
    return folderStack.top() -> newDir(fileName);
}

bool System::exist(std::string fileName) const {
    return folderStack.top() -> exist(fileName);
}

bool System::deleteObject(std::string fileName) {
    return folderStack.top() -> deleteObjectByName(fileName);
}

// �ļ��༭���� 
void System::insertLineBeforeId(std::string fileName, int index, std::string) {
    if(exist(fileName)) {
        
    }
}

void deleteLineById    (std::string fileName, int index); // ���� index ɾ��ĳһ������ 
void showText          (std::string fileName, int from = 0, int to = -1) const; // ��ʾһ�������ڵ����� 
void appendText        (std::string fileName, std::string newLine); // ���ļ�β�������� 

IObject* getCurrentIObject() const;
