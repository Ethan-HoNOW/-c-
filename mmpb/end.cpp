#include "end.h"
#include <QPixmap>
#include "game.h"
End::End(QWidget *parent) : QWidget(parent)
{

}


void End::over()
{


    // 初始化
    QLabel *scoreLabel = new QLabel("恭喜你，获得了胜利",this);
    scoreLabel->move(540,320);
    QPushButton *replayButton = new QPushButton("退出",this);
    replayButton->move(540,420);

    //设置窗口
    setFixedSize(1280,720);
    setWindowTitle("End");

    this->show();

    // 连接信号和槽
    connect(replayButton, &QPushButton::clicked, [this]()
    {
        this->close();
    });


}



void End::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);

    // 加载并绘制背景图片（如果图片是静态的，考虑在构造函数中加载）
    QPixmap pix;
    pix.load("pic.jpg");
    painter.drawPixmap(0, 0, 1280, 720, pix);

    // 其他绘制操作（如果需要）
}
