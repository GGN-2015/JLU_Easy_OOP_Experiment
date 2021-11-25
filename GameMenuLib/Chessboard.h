#ifndef CHESSBOARD_H
#define CHESSBOARD_H // ��¼һ������˹��������� 

const int CHESSBOARD_HEIGHT = 24;
const int CHESSBOARD_WIDTH  = 12; // ���̵Ĵ�С 

class TetrisBlock; // һ������˹����� 

class Chessboard {
public:
    Chessboard(); // ���������� 
    
    int getPosColor(int row, int col) const; // �õ�ĳһ��λ�õ���ɫ����Ե���� WHITE 
    bool checkAvailable(int x, int y, const TetrisBlock& tb) const; // ���ĳ��λ���Ϸ���һ�� Block �Ƿ�Ϸ� 
    void setTetrisBlock(int x, int y, const TetrisBlock& tb);       // �� TetrisBlock ����ͼ�� 
    
    void show() const; // ��ʾһ������, ֱ��ί�и� View �� 
    
private:
    int mScore = 0; // ��¼�÷� 
    int mColors[CHESSBOARD_HEIGHT][CHESSBOARD_WIDTH] {}; // ��¼������ÿ��λ�õ���ɫ, 0 ��ʾ�巽�� 
};

#endif

