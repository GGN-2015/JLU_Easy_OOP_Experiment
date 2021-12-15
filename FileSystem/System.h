#pragma once

#include <stack>
#include <string>

#include "File.h"
#include "Folder.h"

class System { // ʹ�� System �����ļ�ϵͳ 
public:
    static System& getInstance();
    
    void up(); // �ƶ�����Ŀ¼�� 
    int down(std::string dirName); // �ñ�֤�Ǹ� DIR ���� 
    
    int newFile(std::string); // �½��ļ� 
    int newDir(std::string); // �½���Ŀ¼ 
    bool exist(std::string) const;  // ��鵱ǰĿ¼���Ƿ����һ������ 
    int deleteObject(std::string); // ɾ���Ӷ��� 
    
    // �ļ��༭���� 
    void insertLineBeforeId(std::string fileName, int index, std::string); // ��ĳ��ǰ�������� 
    void deleteLineById    (std::string fileName, int index); // ���� index ɾ��ĳһ������ 
    void showText          (std::string fileName, int from = 0, int to = -1) const; // ��ʾһ�������ڵ����� 
    void appendText        (std::string fileName, std::string newLine); // ���ļ�β�������� 

private:
    IObject* getCurrentIObject() const; // �õ�ջ�� 
    
    System();
    ~System();
    
    Folder* mainFolder;         // ���ļ��� 
    std::stack<Folder*> folderStack; // �ļ�·��ջ 
};

