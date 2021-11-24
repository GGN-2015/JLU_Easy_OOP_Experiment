#include <iostream>

#include "Police.h"
#include "PoliceStation.h"
#include "Thief.h"
#include "Walker.h"

int main(int argc, char** argv) {
	PoliceStation S(100);
	Police p1(S), p2(S), p3(S);
	Thief t1(500), t2(300), t3(800), t4(1000);
	
	p1.catchThief(t2).catchThief(t3);
	p2.catchThief(t4);
	
	std::cout << "S.reputation = " << S.getReputation() << std::endl;
	std::cout << "p1.money = " << p1.getMoney() << std::endl;
	std::cout << "p2.money = " << p2.getMoney() << std::endl;
	std::cout << "p3.money = " << p3.getMoney() << std::endl; // output
	
	return 0;
}

