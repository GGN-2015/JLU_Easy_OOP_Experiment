#ifndef APP_H
#define APP_H

#include <string>

class App {
public:
    App();
    
    void initialize(); // ��ʼ�� 
    void run();        // ���� 
    void terminate();  // ��ֹ���� 
    
    bool checkResource(); // ���������е���Դ�ļ��Ƿ���ȱʧ 
    bool checkVersion();  // �����������ļ��İ汾�� exe �ļ��İ汾�Ƿ���� 
    void saveData();      // ������д���ļ� 
    
    std::string getVersion() const; // ��ȡ exe �İ汾����Ϣ 
    
private:
    static std::string mVersion; // ��¼��ǰ�汾 
    
    App(const App&) = delete;
    App& operator= (const App&) = delete; // ��ֹ�����͸�ֵ 
};

#endif

