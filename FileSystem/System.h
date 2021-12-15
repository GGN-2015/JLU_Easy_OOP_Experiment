#pragma once

#include <stack>
#include <string>

#include "File.h"
#include "Folder.h"

class System { // 使用 System 描述文件系统 
public:
    static System& getInstance();
    
    void up(); // 移动到父目录上 
    int down(std::string dirName); // 得保证是个 DIR 才行 
    
    int newFile(std::string); // 新建文件 
    int newDir(std::string); // 新建子目录 
    bool exist(std::string) const;  // 检查当前目录上是否存在一个名字 
    int deleteObject(std::string); // 删除子对象 
    
    // 文件编辑操作 
    void insertLineBeforeId(std::string fileName, int index, std::string); // 在某行前插入内容 
    void deleteLineById    (std::string fileName, int index); // 根据 index 删除某一行内容 
    void showText          (std::string fileName, int from = 0, int to = -1) const; // 显示一个区间内的内容 
    void appendText        (std::string fileName, std::string newLine); // 在文件尾插入内容 

private:
    IObject* getCurrentIObject() const; // 得到栈顶 
    
    System();
    ~System();
    
    Folder* mainFolder;         // 主文件夹 
    std::stack<Folder*> folderStack; // 文件路径栈 
};

