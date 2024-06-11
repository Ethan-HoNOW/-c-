#include "light.h"

Light::Light()
{

}

Light::Light(const QString &name)
{
    pixmap.load(name);
}

void Light::update()
{

}

void Light::draw(QPainter *painter)
{
    painter->drawPixmap(position.toPoint(),pixmap);
}

