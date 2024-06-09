#include "P.h"

Character::Character()
{

}


Character::Character(int x,int y,QString &name)
{
    position.setX(x);
    position.setY(y);
    pixmap.load(name);
}

void Character::update()
{
    position += QVector2D(1,1);
}
void Character::draw(QPainter *painter)
{
    painter->drawPixmap(position.toPoint(),pixmap);
}
