#include "men2.h"
Men2::Men2()
{

}

Men2::Men2(int x, int y,const QString &name)
{
    position.setX(x);
    position.setY(y);
    pixmap.load(name);
}
void Men2::update()
{
    position += speed * velocity;

    if(position.y() <500 ){Ay = 0.4;}
    if(position.y() >500 ){Ay = 0;Vy = 0;position.setY(500);}
    Vy += Ay;
    position.setY(position.y() + Vy);
    if(position.x() > 1180)
        position.setX(1180);
    if(position.x() < 625)
        position.setX(625);
}
