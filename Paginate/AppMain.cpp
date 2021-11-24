#include <iostream>

#include "Paginate.h"

int main()
{
    Paginate pager(13);
    for(int i=1;i<=13;++i) {
        pager.setPage(i,13).show();
    }
    
    std::cout<<"start move..."<<std::endl;
    
    pager.setPage(13).show();
    pager.next().show();
    pager.prev().show();
    pager.nextN().show();
    pager.next().show();
    pager.prevN().show();
    return 0;
}
