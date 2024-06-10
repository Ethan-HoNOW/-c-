#ifndef BALL_H
#define BALL_H
#include"Entity.h"
#include<QVector2D>

class Ball : public Entity
{
public:
    Ball();
    Ball(int x,int y,int vx,int vy,const QString &name);
    void update()override;
    void draw(QPainter *painter)override;

    QVector2D position;//坐标
    QPixmap pixmap;//图像
    int Vx;
    int Vy;
};

#endif // BALL_H
