#include <iostream>

#include "TetrisBlock.h"

int main(int argc, char** argv) { // ���ڲ��Զ���˹�������״�����㷨 
    for(int type = 0; type < 5; type ++) {
        TetrisBlock tb((TetrisBlock::TetrisType)type);
        for(int j = 0; j < 4; j ++) {
            tb.debugShow();
            tb.rotate();
        }
    }
	return 0;
}

