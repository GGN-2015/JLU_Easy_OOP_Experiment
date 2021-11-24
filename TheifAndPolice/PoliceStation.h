// PoliceStation.h
#pragma once

class PoliceStation {
public:
	PoliceStation(int baseReputation);
	
	int getReputation() const;
	void addReputation(); // reputation ++
	
private:
	int reputation;
};

