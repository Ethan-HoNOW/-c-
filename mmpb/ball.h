#ifndef BALL_H
#define BALL_H
#include"Entity.h"
#include<QVector2D>
#include<QLabel>

class Ball : public Entity
{
public:
    Ball();
    Ball(int x,int y,double vx,double vy,double ax,double ay,const QString &name);
    void update()override;
    void draw(QPainter *painter)override;
    QVector2D position;//坐标
    QPixmap pixmap;//图像
    double Vx;
    double Vy;
    double Ax;
    double Ay;
    bool act = 0;
    void kik1(double px,double py);
    void kik2(double px,double py);

    double dx;
    double dy;
    double d;

};

#endif // BALL_H
