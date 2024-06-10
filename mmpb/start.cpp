#include "start.h"
#include"game.h"
#include<QPushButton>
#include<QDebug>
#include<QProcess>

Start::Start(QWidget *parent) : QWidget(parent)
{

}

void Start::run()
{
//1.界面初始化
    this->show();

    setFixedSize(1280,720);
    setWindowTitle("Match Man Play Badminton");
    //设置图标
    /*
       !!!!!!!!!

    */

//2.放置按钮
    btn_begin->move(560,500);
    btn_Ins->move(560,600);
    btn_begin->resize(200,80);
    btn_Ins->resize(200,80);



//3.设置按钮
    //游戏开始
    connect(btn_begin,&QPushButton::clicked,this,[=](){
        this->close();
        begin_flag = 1;
        qDebug() << "first" << begin_flag;
        return ;
  });
    //游戏说明
    connect(btn_Ins,&QPushButton::clicked,this, [=](){
        this->openDocxFile();
        qDebug() << "docxxxxx";
  });
}

void Start::paintEvent(QPaintEvent* ev)
{
    QPainter painter(this);

    //绘制背景图片
    QPixmap pix;
    pix.load("start.png");
    painter.drawPixmap(0,0,1280,720,pix);
}


