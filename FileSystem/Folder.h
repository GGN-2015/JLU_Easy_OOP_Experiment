#pragma once

#include <string>
#include <vector>
#include "IObject.h"

const int FILE_NOT_FOUND = -1; // ������� 
const int SAME_NAME_ERROR = -2; // �������� 

class Folder: public IObject {
public:
    virtual std::string getObjectName() const;  // �ļ���Ҫ��ֻ����ĸ�����»��� 
    virtual void changeObjectName(std::string); // �޸��ļ��� 
    virtual std::string getObjectType() const;  // DIR / FILE
    
    Folder(std::string fileName);  // �����ļ��� 
    ~Folder(); // ����ʱ�ǵõݹ�������Ŀ¼ 
    
    bool exist(std::string) const; // ���һ���ļ����Ƿ��Ѿ�ʹ�ù� 
    bool deleteObjectByName(std::string); // ɾ��һ���ļ� / �ļ��� (�ݹ�ɾ��) 
    int giveSonTo(Folder& folder, std::string); // ���Լ��Ķ���ת�Ƹ���һ���ļ��� 
    
    int changeSubName(std::string from, std::string to); // �޸��ӽṹ������ 
    IObject* getObjectByName(std::string fileName);       // ����ӽṹ���� 
    
    virtual void show(int from = 0, int to = -1) const; // ��ʾ�ļ����е����� 
    int getSubObjectCount() const; // ͳ�����ļ����� 
    
    bool newFile(std::string); // �½�һ���ļ� 
    bool newDir(std::string);  // �½�һ���ļ��� 
    
    IObject* getSubObjectByName(std::string);
    
protected:
    int getRealId(int index) const; // ���� index ������ʵ���±� 
    bool appendObject(IObject*);    // ���ļ����²���һ���ļ� 
    
    int getIdByName(std::string fileName) const; // �����ļ�����ȡ�ļ� ID 
    void sortObjects(); // �������ļ����� 
    static bool compareObject(IObject*, IObject*); // ��������ıȽϺ��� 

    std::string mFolderName;           // �ļ��� 
    std::vector<IObject*> mSubObjects; // ��¼���е��Ӷ�������� 
};

