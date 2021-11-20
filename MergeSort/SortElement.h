// SortElement.h

#ifndef ONLINE_JUDGE
	#pragma once
#endif

class SortElement { // describe the element which can be sortted
public:
	SortElement(int intValue);
	SortElement(const SortElement&);			// these shoul be a copy constructor
	
	operator int() const;						// change a SortElement into Int
	
	virtual bool less(const SortElement&) const; 	// objA.less(objB): check if A is less than B
	virtual SortElement& swap(SortElement&);		// objA.swap(objB): swap the inner value of A and B
private:
	int testValue;
};

