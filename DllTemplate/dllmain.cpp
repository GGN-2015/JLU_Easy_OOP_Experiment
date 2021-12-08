/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include <windows.h>

DllClass::DllClass()
{
    MessageBox(0, "(Construction)Hello World from DLL!\n","Hi",MB_ICONINFORMATION);
}

DllClass::~DllClass()
{
    MessageBox(0, "(Destruction)Hello World from DLL!\n","Hi",MB_ICONINFORMATION);
}

void DllClass::HelloWorld()
{
	MessageBox(0, "Hello World from DLL!\n","Hi",MB_ICONINFORMATION);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}

extern "C" DLLIMPORT DllClass* createDllClass() {
    return new DllClass; // 调用无参构造函数生成一个对象 
}

extern "C" DLLIMPORT void deleteDllClass(DllClass* dllClass) { 
    delete dllClass; // 析构 
}

extern "C" DLLIMPORT void HelloWorld(DllClass* dllClass) { // 老子直接重写一个 
    dllClass -> HelloWorld();
}

