#ifndef MEN1_H
#define MEN1_H
#include"player.h"

class Men1 :  public Player
{
public:
    Men1();
    Men1(int x,int y,const QString &name);
    void update();
};

#endif // MEN1_H
