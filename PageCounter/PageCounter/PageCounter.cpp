//
//  PageCounter.cpp
//  PageCounter
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#include "PageCounter.hpp"

PageCounter::PageCounter(int totalPage) {
    if(totalPage < 0) {
        throw "PageCounter::PageCount totalPage < 0 when initialize.";
    }
    this -> mTotalPage = totalPage;
    this -> mCovered = 0;
}

int PageCounter::getTotalPage() const {
    return this -> mTotalPage;
}

int PageCounter::getCovered() const {
    return this -> mCovered;
}

int PageCounter::getUncovered() const {
    return this -> mTotalPage - this -> mCovered;
}

PageCounter& PageCounter::readToday(int pageCount) { // read some page today
    if(pageCount < 0) {
        throw "PageCounter::readToday pageCount < 0.";
    }
    if(pageCount > this -> getUncovered()) {
        throw "PageCounter::getUncovered pageCount > uncovered count.";
    }
    this -> mCovered += pageCount;
    return *this; // chain call
}
