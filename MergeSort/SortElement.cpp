// SortElement.cpp

#include <iostream>
#include <algorithm>

#ifndef ONLINE_JUDGE
	#include "SortElement.h"
#endif

SortElement::SortElement(int intValue) {
	testValue = intValue; // test constructor
}

void SortElement::showData(std::ostream& out) const {
	out << testValue;
}

bool SortElement::less(const SortElement& rhs) const {
	// std::cout << "SortElement::less(const SortElement& rhs)" << std::endl;
	return testValue < rhs.testValue; // compare
}

