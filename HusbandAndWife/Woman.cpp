// Woman.cpp

#include "Man.h"
#include "Marriage.h"
#include "Woman.h"

Woman::Woman(): marriage(nullptr) {
	// woman was also born single
}

Woman::~Woman() {
	if(marriage != nullptr) {
		marriage -> divorce();
	}
}

bool Woman::single() const {
	return marriage == nullptr;
}

Woman& Woman::marry(Man& man) {
	if(single() && man.single()) {
		new Marriage(man, *this);
	}
	return *this;
}

Woman& Woman::divorce() {
	if(marriage != nullptr) {
		marriage -> divorce();
	}
	return *this;
}

