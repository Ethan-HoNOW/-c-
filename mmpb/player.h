#ifndef PLAYER_H
#define PLAYER_H
#include"Entity.h"
#include<QVector2D>
class Player : public Entity
{
public:
    Player();
    Player(int x,int y,QString &name);
    void update()override;
    void draw(QPainter *painter);
    QVector2D position;//坐标
    QPixmap pixmap;//图像

    void moveBy(int dx,int dy);//偏移多少距离

    QVector2D velocity;
    int speed = 4; //速度
    double Vy = 0;
    double Ay = 0;

};

#endif // PLAYER_H
