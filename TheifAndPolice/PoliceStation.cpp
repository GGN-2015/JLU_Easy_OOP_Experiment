// PoliceStation.cpp
#include "PoliceStation.h"

PoliceStation::PoliceStation(int baseReputation) {
	reputation = baseReputation;
}

void PoliceStation::addReputation() {
	reputation += 1;
}

int PoliceStation::getReputation() const {
	return reputation;	
}

