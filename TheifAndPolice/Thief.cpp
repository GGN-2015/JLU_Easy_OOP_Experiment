// Thief.cpp

#include "Thief.h"

Thief::Thief(int initialMoney): Walker(initialMoney) {
	// don't need to do anything
}

Thief& Thief::steal(Walker& walker) {
	int walkerMoney = walker.getMoney();
	walker.setMoney(0); 		   // clear walker money
	this -> addMoney(walkerMoney); // add thief money
	return *this;
}

