// Paginate.cpp

#include <algorithm>
#include <cstdio>

#include "Paginate.h"

Paginate::Paginate(int totalPages) {
	mPageNow = 1;
	mTotalPages = totalPages;
}

Paginate& Paginate::prev() {
	mPageNow = std::max(mPageNow - 1, 1);
	return *this;
}

Paginate& Paginate::next() {
	mPageNow = std::min(mPageNow + 1, mTotalPages);
	return *this;
}

Paginate& Paginate::prevN() {
	printf("prevN(): input n:");
	int n; scanf("%d", &n);
	if(n >= 0) {
		mPageNow = std::max(mPageNow - n, 1);
	}
	return *this;
}

Paginate& Paginate::nextN() {
	printf("nextN(): input n:");
	int n; scanf("%d", &n);
	if(n >= 0) {
		mPageNow = std::min(mPageNow + n, mTotalPages);
	}
	return *this;
}

void Paginate::showTerm(int id) const {
	if(id == mPageNow) {
		printf("[%3d]", id); // high light current page
	}else {
		printf(" %3d ", id);
	}
}

Paginate& Paginate::setPage(int newPage, int totalPages) {
	mPageNow = newPage;
	if(totalPages > 0) {
		mTotalPages = totalPages;
	}
	return *this;
}

Paginate& Paginate::setPage(int newPage) {
	mPageNow = newPage;
	return *this;
}

void Paginate::getShowSegment(int& left, int& right) const {
	int half = MAX_SHOW / 2; // MAX_SHOW must be even number
	left = mPageNow - half + 1;
	right = mPageNow + half; // show [left, right]
	if(left < 1) {
		int delta = 1 - left;
		left += delta;
		right += delta;
	}
	if(right > mTotalPages) {
		int delta = right - mTotalPages;
		right -= delta;
		left -= delta;
	}
	left = std::max(left, 1);
	right = std::min(right, mTotalPages);
}

void Paginate::show() const {
	printf(" prev ");
	if(mTotalPages <= MAX_SHOW) {
		for(int i = 1; i <= mTotalPages; i ++) {
			showTerm(i);
		}
	}else {
		int left, right;
		getShowSegment(left, right);
		if(left > 1) {
			showTerm(1);
			if(left > 2) printf(" ... ");
		}
		for(int i = left; i <= right; i ++) {
			showTerm(i);
		}
		if(right < mTotalPages) {
			if(right < mTotalPages - 1) printf(" ... ");
			showTerm(mTotalPages);
		}
		
	}
	printf(" next \n");
}

