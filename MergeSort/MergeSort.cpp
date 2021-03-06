// MergeSort.cpp 

#ifndef ONLINE_JUDGE
	#include <algorithm>
	
	#include "DoubleSortElement.h"
	#include "SortElement.h"
	#include "MergeSort.h"
#endif

void MergeSort::mergeSort(SortElement** array, int elementCount) { // sort [0 .. n-1]
	// if elementCount <= 1, you do not need to sort
	if(elementCount > 1) {
		if(elementCount == 2) {
			if((array[1]) -> less(*array[0])) { // right is less than left
				std::swap(array[0], array[1]);
			}
		}else {
			int mid = elementCount >> 1; // divide into [0 .. mid - 1], [mid, r]
			mergeSort(array, mid);
			mergeSort(array + mid, elementCount - mid);
			merge(array, array + mid, mid, elementCount - mid); // merge two array 
		}
	}
}

void MergeSort::merge(SortElement** arrLeft, SortElement** arrRight, int leftCount, int rightCount) {
	int totalCount = leftCount + rightCount;
	int totalUsed = 0, leftUsed = 0, rightUsed = 0;
	
	SortElement** arrTmp = new SortElement*[totalCount];
	while(leftUsed < leftCount && rightUsed < rightCount) {
		if(arrRight[rightUsed] -> less(*arrLeft[leftUsed])) { // right side is less than right side
			arrTmp[totalUsed ++] = arrRight[rightUsed ++];
		}else {
			arrTmp[totalUsed ++] = arrLeft[leftUsed ++];
		}
	}
	while(leftUsed < leftCount) {
		arrTmp[totalUsed ++] = arrLeft[leftUsed ++];
	}
	while(rightUsed < rightCount) {
		arrTmp[totalUsed ++] = arrRight[rightUsed ++];
	}
	
	for(int i = 0; i < totalCount; i ++) {
		arrLeft[i] = arrTmp[i]; // copy the new array into the old array
	}
	delete[] arrTmp; // remember to clear memory
}

