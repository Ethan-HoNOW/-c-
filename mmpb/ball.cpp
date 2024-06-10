#include "ball.h"
#include"Entity.h"
#include<QVector2D>
Ball::Ball()
{

}

Ball::Ball(int x,int y,int vx,int vy,const QString &name)
{
    position.setX(x);
    position.setY(y);
    Vx = vx;
    Vy = vy;
    pixmap.load(name);
}

void Ball::update()
{
    position += QVector2D(1,1);
}

void Ball::draw(QPainter *painter)
{
    painter->drawPixmap(position.toPoint(),pixmap);
}
