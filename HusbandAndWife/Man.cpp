// Man.cpp

#include "Man.h"
#include "Marriage.h"
#include "Woman.h"

Man::Man(): marriage(nullptr) {
	// man was born single
}

Man::~Man() {
	if(marriage != nullptr) {
		marriage -> divorce();
	}
}

bool Man::single() const {
	return marriage == nullptr;
}

Man& Man::marry(Woman& woman) {
	if(single() && woman.single()) {
		new Marriage(*this, woman); // create a marriage
	}
	return *this;
}

Man& Man::divorce() {
	if(marriage != nullptr) {
		marriage -> divorce();
	}
	return *this;
}

