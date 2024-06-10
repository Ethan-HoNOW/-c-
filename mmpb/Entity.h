#ifndef ENTITY_H
#define ENTITY_H
#include<QPainter>

//实体类 所有实体的基类
class Entity
{
public:
    Entity(){};
    virtual void update() = 0;//刷新实体
    virtual void draw(QPainter *painter) = 0;//绘制实体

    virtual bool isActive()const {return active;}//判断实体是否存在
    virtual void destroy(){active = false;};//可以理解为输掉了

    inline int which(){return which_en;}
    inline void setEn(int n){which_en = n;}
    bool active = true;
private:
//flag记录实体状态
    int which_en = 0;//flag区分哪一个实体 初始值为0号实体
};

#endif // ENTITY_H
