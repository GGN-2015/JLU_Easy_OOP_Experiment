// Thief.h
#pragma once

#include "Walker.h"

class Thief: public Walker { // Walker means normal man
public:
	Thief(int initialMoney);
	Thief& steal(Walker& walker);
};

