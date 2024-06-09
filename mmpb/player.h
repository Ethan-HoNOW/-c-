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
};

#endif // PLAYER_H
