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
    delete mainFolder; // 直接删除根目录 
}

void System::up() {
    if(folderStack.size() > 1) { // 至少得保证根目录不被弹出 
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

// 文件编辑操作 
void System::insertLineBeforeId(std::string fileName, int index, std::string) {
    if(exist(fileName)) {
        
    }
}

void deleteLineById    (std::string fileName, int index); // 根据 index 删除某一行内容 
void showText          (std::string fileName, int from = 0, int to = -1) const; // 显示一个区间内的内容 
void appendText        (std::string fileName, std::string newLine); // 在文件尾插入内容 

IObject* getCurrentIObject() const;
