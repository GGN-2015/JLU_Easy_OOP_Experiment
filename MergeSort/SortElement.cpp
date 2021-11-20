// SortElement.cpp

#include <algorithm>

#ifndef ONLINE_JUDGE
	#include "SortElement.h"
#endif

SortElement::SortElement(int intValue) {
	testValue = intValue; // test constructor
}

SortElement::SortElement(const SortElement& rhs) {
	testValue = rhs.testValue;
}

SortElement::operator int() const {
	return this -> testValue; // just return the int value
}

bool SortElement::less(const SortElement& rhs) const {
	return testValue < rhs.testValue; // compare
}

SortElement& SortElement::swap(SortElement& rhs) {
	std::swap(this -> testValue , rhs.testValue);
	return *this;
}

