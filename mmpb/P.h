#ifndef CHARACTER_H
#define CHARACTER_H
#include"Entity.h"
#include<QVector2D>
class Character : public Entity
{
    Q_OBJECT
public:
    Character();
    Character(int x,int y,QString &name);
    void update()override;
    void draw(QPainter *painter);
    QVector2D position;//坐标
    QPixmap pixmap;//图像

};

#endif // CHARACTER_H
