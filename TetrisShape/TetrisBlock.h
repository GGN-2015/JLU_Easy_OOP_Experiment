#ifndef TETRISBLOCK_H
#define TETRISBLOCK_H

class TetrisBlock { // 用来描述俄罗斯方块中的一个块 
public:
    enum TetrisType {
        TypeZ, TypeT, TypeL, TypeI, TypeO // 俄罗斯方块的所有形状种类 
    };
    
    TetrisBlock(TetrisType type); // 构建一个俄罗斯方块的基本形状 
    
    void debugShow() const; // 在调试模式下，在命令行输出俄罗斯方块的形状 
    int maxDepth() const;   // 计算当前 mPos 中有方块位置的最大行号 
    
    void rotate();          // 对俄罗斯方块进行顺时针旋转 
    
private:
    void rotateFull();     // 对整个 4 * 4 矩形区域进行旋转 
    
    bool leftMost() const; // 判断图形是否贴在了左边界上 
    bool upMost() const;   // 判断图形是否贴在了上边界上 
    
    void moveLeft(); // 将图形向上移动一个单位 
    void moveUp();   // 将图形向左移动一个单位 
    
    bool mPos[4][4] {}; // 用于记录俄罗斯方块的形状 
};

#endif

