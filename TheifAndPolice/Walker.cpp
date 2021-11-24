// Walker.cpp
#include "Walker.h"

Walker::Walker(int initialMoney): money(initialMoney) {
	if(money < 0) money = 0; // negative money is not allowed
}

int Walker::getMoney() const {
	return money;
}

int Walker::setMoney(int newMoney) {
	money = newMoney;
	if(money < 0) money = 0;
}

int Walker::addMoney(int addMoney) {
	money += addMoney;
	if(money < 0) money = 0;
}

