#include "ball.h"
#include"Entity.h"
#include<QVector2D>
#include <math.h>

Ball::Ball()
{

}

Ball::Ball(int x, int y, double vx, double vy, double ax, double ay, const QString &name)
{
    position.setX(x);
    position.setY(y);
    Vx = vx;
    Vy = vy;
    Ax = ax;
    Ay = ay;

    pixmap.load(name);
}


void Ball::update()
{
    position.setX(position.x() + Vx);
    position.setY(position.y() + Vy);
    Vx += Ax;
    Vy += Ay;
    if(Vx > 0 ){Ax = -0.05;}
    if(Vx < 0 ){Ax = 0.05;}
    if(Vy < 0 ){Ay = 0.4;}

    if((position.x() <= 130 && position.y() <= 640) || (position.x() >= 1150 && position.y() <= 640))
    {
        //撞墙了
        Vx = -0.8*Vx;
    }
    if((position.x() >= 617 && position.x() <= 656) && (position.y() >= 546 && position.y() <= 710))
    {
        Vx = -0.8*Vx;

    }
    if(position.x() > 640)
    {
        act = 1;
    }
    if(position.y() <0)
    {
        //撞墙了
        position.setY(0);
        Vy = - 0.6*Vy;
    }

}

void Ball::draw(QPainter *painter)
{
    painter->drawPixmap(position.toPoint(),pixmap);
}

void Ball::kik1(double px, double py)
{
    d = sqrt((position.x() - px)*(position.x() - px)+(position.y() - py)*(position.y() - py));
    double V = sqrt(Vx*Vx+Vy*Vy);//合速度
    dx = (position.x() - px) / d;
    dy = (position.y() - py) / d;
    if(d < 150 && position.x() + 20 > px)
    {
        Vx = dx*V*1.3;
        Vy = dy*V*1.3;
    }

}

void Ball::kik2(double px, double py)
{
    d = sqrt((position.x() - px)*(position.x() - px)+(position.y() - py)*(position.y() - py));//距离
    double V = sqrt(Vx*Vx+Vy*Vy);//合速度
    dx = (position.x() - px) / d;
    dy = (position.y() - py) / d;
    if(d < 150 && position.x() - 20 < px)
    {
        Vx = dx*V*1.3;
        Vy = dy*V*1.3;
    }
}
