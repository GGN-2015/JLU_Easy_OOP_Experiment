// Police.cpp
#include "Police.h"
#include "PoliceStation.h"
#include "Thief.h"

Police::Police(PoliceStation& ps)
	: Walker(0), policeStation(&ps) {
	// don't do anything
}

Police& Police::catchThief(Thief& thief) {
	thief.setMoney(0);
	this -> addMoney(100);
	this -> policeStation -> addReputation();
	return *this;
}

