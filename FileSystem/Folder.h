#pragma once

#include <string>
#include <vector>
#include "IObject.h"

const int FILE_NOT_FOUND = -1; // 错误代码 
const int SAME_NAME_ERROR = -2; // 重名错误 

class Folder: public IObject {
public:
    virtual std::string getObjectName() const;  // 文件名要求只有字母数字下划线 
    virtual void changeObjectName(std::string); // 修改文件名 
    virtual std::string getObjectType() const;  // DIR / FILE
    
    Folder(std::string fileName);  // 创建文件夹 
    ~Folder(); // 析构时记得递归析构子目录 
    
    bool exist(std::string) const; // 检查一个文件名是否已经使用过 
    bool deleteObjectByName(std::string); // 删除一个文件 / 文件夹 (递归删除) 
    int giveSonTo(Folder& folder, std::string); // 把自己的儿子转移给另一个文件夹 
    
    int changeSubName(std::string from, std::string to); // 修改子结构的名字 
    IObject* getObjectByName(std::string fileName);       // 获得子结构对象 
    
    virtual void show(int from = 0, int to = -1) const; // 显示文件夹中的内容 
    int getSubObjectCount() const; // 统计子文件个数 
    
    bool newFile(std::string); // 新建一个文件 
    bool newDir(std::string);  // 新建一个文件夹 
    
    IObject* getSubObjectByName(std::string);
    
protected:
    int getRealId(int index) const; // 根据 index 计算真实的下标 
    bool appendObject(IObject*);    // 在文件夹下插入一个文件 
    
    int getIdByName(std::string fileName) const; // 根据文件名获取文件 ID 
    void sortObjects(); // 给所有文件排序 
    static bool compareObject(IObject*, IObject*); // 用于排序的比较函数 

    std::string mFolderName;           // 文件名 
    std::vector<IObject*> mSubObjects; // 记录所有的子对象的内容 
};

