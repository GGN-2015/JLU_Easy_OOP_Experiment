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
    auto hf = GetProcAddress(hmod, "createDllClass"); // 获取一个函数的入口地址 
    auto gf = GetProcAddress(hmod, "deleteDllClass");
    auto helloF = GetProcAddress(hmod, "HelloWorld"); // hello world 
    if (hf == NULL)
    {
        cout << "Get funtion failed.";
        FreeLibrary(hmod);
        return 0;
    }
    cout << "Hello" << endl;
    
    typedef DllClass* (*pf)();     // 构造函数类型 
    typedef void (*df)(DllClass*); // 析构函数类型 
    
    DllClass* pClass = reinterpret_cast<pf>(hf)();
    reinterpret_cast<df>(helloF)(pClass); // 调用对象方法， 
    
    reinterpret_cast<df>(gf)(pClass); // 析构 
    FreeLibrary(hmod);
    return 0;
}
