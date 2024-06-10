#include "ball.h"
#include"Entity.h"
#include<QVector2D>
#include "men1.h"
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
    if(Vx > 0 ){Ax = -0.04;}
    if(Vx < 0 ){Ax = 0.04;}
    if(Vy < 0 ){Ay = 0.4;}


    if((position.x() <= 130 && position.y() <= 640)|| (position.x() >= 1150 && position.y() <= 640))
    {
        //撞墙了
    }
   else if((position.x() >= 617 && position.x() <= 656) || (position.y() >= 546 && position.y() <= 710))
    {
        //撞网了
    }
    else if(position.y() > 640 && position.y() <= 710)
    {
        //落地了
    }
}

void Ball::draw(QPainter *painter)
{
    painter->drawPixmap(position.toPoint(),pixmap);
}
