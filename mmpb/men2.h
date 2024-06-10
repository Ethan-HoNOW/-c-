#ifndef MEN2_H
#define MEN2_H
#include"player.h"

class Men2 : public Player
{
public:
    Men2();
    Men2(int x,int y,const QString &name);
    void update();
};

#endif // MEN2_H
