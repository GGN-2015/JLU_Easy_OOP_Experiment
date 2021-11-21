// DoubleSortElement.cpp

#ifndef ONLINE_JUDGE
	#include <algorithm>
	#include <iostream>
	
	#include "SortElement.h"
	#include "DoubleSortElement.h"
#endif

DoubleSortElement::DoubleSortElement(double val) {
	doubleValue = val;
}

bool DoubleSortElement::less(const SortElement& rhs) const {
	const DoubleSortElement& nrhs = dynamic_cast<const DoubleSortElement&>(rhs);
	// std::cout << "DoubleSortElement::less(const DoubleSortElement& rhs)" << std::endl;
	return doubleValue < nrhs.doubleValue;	
}

void DoubleSortElement::showData(std::ostream& out) const {
	out << doubleValue;
}

