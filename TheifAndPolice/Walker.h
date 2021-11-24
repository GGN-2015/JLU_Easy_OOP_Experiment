// Walker.h
#pragma once

class Walker {
public:
	Walker(int initialMoney);
	
	int getMoney() const;
	int setMoney(int newMoney);
	int addMoney(int addMoney);
	
private:
	int money;
};

