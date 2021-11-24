// Police.h
#pragma once

#include "Walker.h"

class PoliceStation;
class Thief;

class Police: public Walker {
public:
	Police(PoliceStation& ps);
	Police& catchThief(Thief& thief);
	
private:
	PoliceStation* policeStation;
};

