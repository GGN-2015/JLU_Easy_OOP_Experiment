#ifndef TETRISBLOCK_H
#define TETRISBLOCK_H

class TetrisBlock { // ������������˹�����е�һ���� 
public:
    enum TetrisType {
        TypeZ, TypeT, TypeL, TypeI, TypeO // ����˹�����������״���� 
    };
    
    TetrisBlock(TetrisType type); // ����һ������˹����Ļ�����״ 
    
    void debugShow() const; // �ڵ���ģʽ�£����������������˹�������״ 
    int maxDepth() const;   // ���㵱ǰ mPos ���з���λ�õ�����к� 
    
    void rotate();          // �Զ���˹�������˳ʱ����ת 
    
private:
    void rotateFull();     // ������ 4 * 4 �������������ת 
    
    bool leftMost() const; // �ж�ͼ���Ƿ���������߽��� 
    bool upMost() const;   // �ж�ͼ���Ƿ��������ϱ߽��� 
    
    void moveLeft(); // ��ͼ�������ƶ�һ����λ 
    void moveUp();   // ��ͼ�������ƶ�һ����λ 
    
    bool mPos[4][4] {}; // ���ڼ�¼����˹�������״ 
};

#endif

