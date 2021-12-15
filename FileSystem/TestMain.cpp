#include <iostream>

#include "File.h"
#include "Folder.h"

int main(int argc, char** argv) {
    using std::cout;
    using std::cin;
    using std::endl; 
    
    Folder folder("main"); // Ö÷ÎÄ¼þ¼Ð 
    folder.newFile("Hello_World");
    folder.newDir("submain");
    folder.show();
	return 0;
}

