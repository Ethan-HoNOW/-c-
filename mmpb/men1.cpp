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
