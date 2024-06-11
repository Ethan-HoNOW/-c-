#ifndef LIGHT_H
#define LIGHT_H
#include"Entity.h"
#include<QVector2D>


class Light : public Entity
{
public:
    Light();
    Light(const QString &name);
    void update()override;
    void draw(QPainter *painter)override;
    QVector2D position;//坐标
    QPixmap pixmap;//图像
};

#endif // LIGHT_H
