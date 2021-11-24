// Marriage.h
#pragma once

class Man;
class Woman;

class Marriage {
public:
	Marriage(Man& man, Woman& woman);
	void divorce();
	
private:
	~Marriage();
	
	Man* mMan;
	Woman* mWoman;
};

