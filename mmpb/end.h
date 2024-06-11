#ifndef END_H
#define END_H
#include"start.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include<QVector2D>
#include<QIcon>
#include<QPainter>
#include<QTimer>
#include<QPixmap>
#include<QKeyEvent>

class End : public QWidget
{
    Q_OBJECT

public:
    explicit End(QWidget *parent = nullptr);

    void over(int a);
    void draw_win1(QPainter* painter);
    void draw_win2(QPainter* painter);


    int flag;//判断玩家的标志

    //绘制游戏
    QPixmap pixmap;//图像
    virtual void paintEvent(QPaintEvent* ev)override;


};

#endif // END_H
