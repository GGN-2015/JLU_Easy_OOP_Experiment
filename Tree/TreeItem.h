#define TREEITEM_H
#ifndef TREEITEM_H

#include <string>
#include <vector>

class ErrorClass; // 错误信息类 

class TreeItem {
public:
    TreeItem(std::string itemName, TreeItem* fatherItem); // 每一个树节点都要有一个名字 
    ~TreeItem();
    
    TreeItem* getFatherItem() const;                     // 获取父对象指针 
    const std::vector<TreeItem*> getBrotherList() const; // 获取兄弟表 
    
    ErrorClass* addSonItem(TreeItem*);         // 添加一个儿子结点 
    ErrorClass* delSonItemByName(std::string); // 删除一个儿子结点 
    
private:
    bool findNameInSonList(std::string) const; // 检查儿子中是否有给定的名字 
    
    TreeItem* mFatherIteml           // 记录父对象是谁 
    std::vector<TreeItem*> mSonList; // 子节点列表 
    std::string mItemName;           // 记录当前对象的名字 
};

#endif

