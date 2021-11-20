// main.cpp

#include <iostream>

#ifndef ONLINE_JUDGE // because I want to test this program on luogu
	#include "SortElement.h"
	#include "MergeSort.h"
#endif

int main() {
	#ifdef ONLINE_JUDGE
		std::ios::sync_with_stdio(false); // quick input and output when using online judge
	#endif
	
	#ifndef ONLINE_JUDGE
		std::cout << "Input the number of integers:";
	#endif
	
	int n; std::cin >> n;
	SortElement** array = new SortElement*[n]; // create an N elements array
	
	#ifndef ONLINE_JUDGE
		std::cout << "Input " << n << " integers:";
	#endif
	
	for(int i = 0; i < n; i ++) {
		int tmp; std::cin >> tmp; // input all numbers
		array[i] = new SortElement(tmp);
	}
	
	MergeSort::mergeSort(array, n);
	
	#ifndef ONLINE_JUDGE
		std::cout << "[sorted]: ";
	#endif
	
	for(int i = 0; i < n; i ++) { // output the sortted values
		int tmp = int(*array[i]);
		std::cout << tmp << " ";
	}
	std::cout << std::endl;
	return 0;
}

