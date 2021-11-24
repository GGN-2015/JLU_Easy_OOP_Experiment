//Marriage.cpp
#include <iostream>

#include "Man.h"
#include "Marriage.h"
#include "Woman.h"

Marriage::Marriage(Man& man, Woman& woman):
	mMan(&man), mWoman(&woman) {
	// create a Marriage
	std::cout << "Marriage(" << mMan << ", " << mWoman << ")" << std::endl;
	
	man.marriage = this;
	woman.marriage = this; // set links
}

Marriage::~Marriage() {
	// just do nothing is ok.
}

void Marriage::divorce() {
	std::cout << "delete Marriage(" << mMan << ", " << mWoman << ")" << std::endl;
	mMan -> marriage = nullptr;
	mWoman -> marriage = nullptr;
	delete this;
}

