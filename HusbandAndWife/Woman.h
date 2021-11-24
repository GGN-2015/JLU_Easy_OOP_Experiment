// Woman.h
#pragma once

class Man;
class Marriage;

class Woman {
public:
	friend class Marriage;
	
	Woman();
	~Woman();
	
	bool single() const;
	
	Woman& marry(Man& man);
	Woman& divorce();
	
private:
	Marriage* marriage;
};

