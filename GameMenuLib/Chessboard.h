#ifndef CHESSBOARD_H
#define CHESSBOARD_H // 记录一个俄罗斯方块的棋盘 

const int CHESSBOARD_HEIGHT = 24;
const int CHESSBOARD_WIDTH  = 12; // 棋盘的大小 

class TetrisBlock; // 一个俄罗斯方块的 

class Chessboard {
public:
    Chessboard(); // 创建空棋盘 
    
    int getPosColor(int row, int col) const; // 得到某一个位置的颜色，边缘返回 WHITE 
    bool checkAvailable(int x, int y, const TetrisBlock& tb) const; // 检测某个位置上放置一个 Block 是否合法 
    void setTetrisBlock(int x, int y, const TetrisBlock& tb);       // 把 TetrisBlock 放在图上 
    
    void show() const; // 显示一个棋盘, 直接委托给 View 做 
    
private:
    int mScore = 0; // 记录得分 
    int mColors[CHESSBOARD_HEIGHT][CHESSBOARD_WIDTH] {}; // 记录棋盘上每个位置的颜色, 0 表示五方块 
};

#endif

