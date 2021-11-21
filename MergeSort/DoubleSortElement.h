// DoubleSortElement.h

#pragma once

#include <iostream>
#include "SortElement.h"

class DoubleSortElement: public SortElement { // generate a new sub-class
public:
	DoubleSortElement(double);
	
	bool less(const SortElement& rhs) const;
	void showData(std::ostream&) const;
	
private:
	double doubleValue;
};

