#include "Man.h"
#include "Marriage.h"
#include "Woman.h"

int main(int argc, char** argv) {
	Man* m1 = new Man;
	Man* m2 = new Man;
	Woman* w1 = new Woman;
	Woman* w2 = new Woman;
	
	m1 -> marry(*w1);
	delete w1;
	
	w2 -> marry(*m1);
	delete m1;
	
	w2 -> marry(*m2);
	delete w2;
	delete m2;
	return 0;
}

