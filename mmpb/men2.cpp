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
