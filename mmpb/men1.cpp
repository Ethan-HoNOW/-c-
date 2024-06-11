#include "men1.h"

Men1::Men1()
{

}

Men1::Men1(int x, int y,const QString &name)
{
    position.setX(x);
    position.setY(y);
    pixmap.load(name);
}
void Men1::update()
{
    position += speed * velocity;

    if(position.y() <525 ){Ay = 0.4;}
    if(position.y() >525 ){Ay = 0;Vy = 0;position.setY(525);}
    Vy += Ay;
    position.setY(position.y() + Vy);
    if(position.x() > 480)
        position.setX(480);
    if(position.x() < 0)
        position.setX(0);
}
