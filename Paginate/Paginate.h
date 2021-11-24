// Paginate.h
#pragma once

class Paginate {
public:
	Paginate(int totalPages);
	
	Paginate& prev();
	Paginate& next();
	
	Paginate& prevN();
	Paginate& nextN();
	
	Paginate& setPage(int newPage, int totalPages);
	
	void show() const;
	Paginate& setPage(int newPage);
	
	static const int MAX_SHOW = 6; // max show terms

private:
	void showTerm(int id) const;
	void getShowSegment(int& left, int& right) const;
	
	int mPageNow;
	int mTotalPages;
};

