// main.cpp

#include <iostream>

#ifndef ONLINE_JUDGE // because I want to test this program on luogu
	#include "SortElement.h"
	#include "DoubleSortElement.h"
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
		std::cout << "Input " << n << " floats:";
	#endif
	
	for(int i = 0; i < n; i ++) {
		double tmp; std::cin >> tmp; // input all numbers
		array[i] = new DoubleSortElement(tmp);
	}
	
	MergeSort::mergeSort(array, n); // ! function less can not do what I want
	
	#ifndef ONLINE_JUDGE
		std::cout << "[sorted]: ";
	#endif
	
	for(int i = 0; i < n; i ++) { // output the sortted values
		array[i] -> showData(std::cout);
		std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}

