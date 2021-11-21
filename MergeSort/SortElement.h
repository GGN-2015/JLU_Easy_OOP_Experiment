// SortElement.h

#ifndef ONLINE_JUDGE
	#pragma once
	#include <iostream> 
#endif

class SortElement { // describe the element which can be sortted
public:
	SortElement(int intValue = 0);

	virtual void showData(std::ostream&) const;
	virtual bool less(const SortElement&) const; 	// objA.less(objB): check if A is less than B
	
private:
	int testValue;
};

