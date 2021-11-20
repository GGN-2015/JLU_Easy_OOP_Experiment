// MergeSort.h

#ifndef ONLINE_JUDGE
	#pragma once
#endif

class SortElement;
class MergeSort {
public:
	static void mergeSort(SortElement** array, int elementCount);
	
private:
	static void merge(SortElement** arrLeft, SortElement** arrRight, int leftCount, int rightCount);
	
	MergeSort() = delete; // you can not make an object called merge sort
	MergeSort(const MergeSort&) = delete;
	MergeSort& operator= (const MergeSort&) = delete;
};

