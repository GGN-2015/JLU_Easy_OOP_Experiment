#define TREEITEM_H
#ifndef TREEITEM_H

#include <string>
#include <vector>

class ErrorClass; // ������Ϣ�� 

class TreeItem {
public:
    TreeItem(std::string itemName, TreeItem* fatherItem); // ÿһ�����ڵ㶼Ҫ��һ������ 
    ~TreeItem();
    
    TreeItem* getFatherItem() const;                     // ��ȡ������ָ�� 
    const std::vector<TreeItem*> getBrotherList() const; // ��ȡ�ֵܱ� 
    
    ErrorClass* addSonItem(TreeItem*);         // ���һ�����ӽ�� 
    ErrorClass* delSonItemByName(std::string); // ɾ��һ�����ӽ�� 
    
private:
    bool findNameInSonList(std::string) const; // ���������Ƿ��и��������� 
    
    TreeItem* mFatherIteml           // ��¼��������˭ 
    std::vector<TreeItem*> mSonList; // �ӽڵ��б� 
    std::string mItemName;           // ��¼��ǰ��������� 
};

#endif

