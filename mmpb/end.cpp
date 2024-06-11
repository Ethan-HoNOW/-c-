#include "end.h"
#include <QPixmap>
#include "game.h"
End::End(QWidget *parent) : QWidget(parent)
{

}


void End::over(int a)
{
    // 初始化
//    QLabel *scoreLabel = new QLabel("恭喜你，获得了胜利",this);
//    scoreLabel->move(540,320);
    QPushButton *replayButton = new QPushButton("退出",this);
    replayButton->move(540,300);
    replayButton->resize(200,80);

    //设置窗口
    setFixedSize(1280,720);
    setWindowTitle("End");

    this->show();

    // 连接信号和槽
    connect(replayButton, &QPushButton::clicked, [this]()
    {
        this->close();
    });

    if(a == 7)
    flag = 1;
    else if(a == 8)
    flag = 2;

}

void End::draw_win1(QPainter* painter)
{
    // 加载并绘制背景图片
    QPixmap pix;
    pix.load("win1.png");
    painter->drawPixmap(0, 0, 1280, 720, pix);
}

void End::draw_win2(QPainter* painter)
{
    // 加载并绘制背景图片
    QPixmap pix;
    pix.load("win2.png");
    painter->drawPixmap(0, 0, 1280, 720, pix);
}


void End::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);

    if(flag == 1)
    draw_win1(&painter);
    else if(flag == 2)
    draw_win2(&painter);



    // 其他绘制操作（如果需要）
}
