#include "Utility.h"

int Utility::bitCount(int val) {
    if(val < 0) {
        val = - val * 10;
    }
    int cnt = 0;
    if(val == 0) {
        return 1;
    }
    while(val > 0) {
        cnt ++;
        val /= 10;
    }
    return cnt; // 统计十进制位的个数 
}

std::string Utility::fillSpace(std::string str, int len) {
    while((int)str.length() < len) {
        str = " " + str;
    }
    return str;
}

