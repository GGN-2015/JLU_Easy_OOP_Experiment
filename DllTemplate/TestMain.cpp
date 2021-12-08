#include <Windows.h>
#include <iostream>

#include "dll.h"
using namespace std;

int main()
{
    auto hmod = LoadLibrary("DemoDLL.dll");
    if (hmod == NULL)
    {
        cout << "Load dll failed.";
        FreeLibrary(hmod);
        return 0;
    }
    auto hf = GetProcAddress(hmod, "createDllClass"); // ��ȡһ����������ڵ�ַ 
    auto gf = GetProcAddress(hmod, "deleteDllClass");
    auto helloF = GetProcAddress(hmod, "HelloWorld"); // hello world 
    if (hf == NULL)
    {
        cout << "Get funtion failed.";
        FreeLibrary(hmod);
        return 0;
    }
    cout << "Hello" << endl;
    
    typedef DllClass* (*pf)();     // ���캯������ 
    typedef void (*df)(DllClass*); // ������������ 
    
    DllClass* pClass = reinterpret_cast<pf>(hf)();
    reinterpret_cast<df>(helloF)(pClass); // ���ö��󷽷��� 
    
    reinterpret_cast<df>(gf)(pClass); // ���� 
    FreeLibrary(hmod);
    return 0;
}
