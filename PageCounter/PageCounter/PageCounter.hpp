//
//  PageCounter.hpp
//  PageCounter
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#ifndef PageCounter_hpp
#define PageCounter_hpp

class PageCounter {
public:
    PageCounter(int totalPage);
    
    int getTotalPage()  const;
    int getCovered  ()  const;
    int getUncovered()  const;
    
    PageCounter& readToday(int pageCount);
private:
    int mTotalPage;
    int mCovered; // the count fo pages that has been read.
};

#endif /* PageCounter_hpp */
