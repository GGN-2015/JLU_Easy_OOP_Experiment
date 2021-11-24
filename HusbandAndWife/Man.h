// Man.h
#pragma once

class Marriage; // relationship class
class Woman;

class Man {
public:
	friend class Marriage;
	
	Man();
	~Man();
	
	bool single() const;
	
	Man& marry(Woman& woman);
	Man& divorce();
	
private:
	Marriage* marriage;
	
	Man(const Man&) = delete;
	Man& operator= (const Man&) = delete;
};

