#include "player.h"
#include"Entity.h"
#include<QVector2D>
Player::Player()
{

}


Player::Player(int x,int y,QString &name)
{
    position.setX(x);
    position.setY(y);
    pixmap.load(name);
}

void Player::update()
{
   // position += QVector2D(1,1);
    position += speed * velocity; // 3 * (1/-1/0)

}
void Player::draw(QPainter *painter)
{
    painter->drawPixmap(position.toPoint(),pixmap);
}


