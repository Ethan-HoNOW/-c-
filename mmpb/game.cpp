#include "game.h"
#include<QIcon>
#include<QPainter>
#include<QTimer>
#include<QPixmap>
#include<QLabel>
#include<QString>
#include<QKeyEvent>

#include"Men1.h"
#include"Men2.h"
#include "Player.h"

//定义两个玩家
Men1 *men1;
Men2 *men2;

Game::Game(QWidget *parent) : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    timer->callOnTimeout(this,[=](){
        updateGame();//刷新游戏
        update();//刷新绘图事件
    });
    timer->start(1000/60);//帧率
}

void Game::run()
{
    this->show();
}

void Game::intiGame()
{
    setFixedSize(1280,720);
    setWindowTitle("Match Man Play Badminton");
    men1 = new Men1(20,20,"Player.png");
    men2 = new Men2(20,20,"Player.png");
}

//清理游戏
void Game::clearGame()
{

}

//更新游戏
void Game::updateGame()
{

}

//绘制游戏
void Game::drawGame(QPainter* painter)
{

}

void Game::paintEvent(QPaintEvent* ev)
{
    QPainter painter(this);
    drawGame(&painter);

    //绘制背景图片
    QPixmap pix;
    pix.load("pic.jpg");
    painter.drawPixmap(0,0,1280,720,pix);

    //绘制得分板
    QPainter pen;
    QFont fonthead("黑体",30,20,0);
    pen.setFont(fonthead);
    painter.setFont(fonthead);
    painter.drawText(590,80,QString("%1").arg(score1) + QString(":") + QString("%2").arg(score2));
}

void Game::closeEvent(QCloseEvent* ev)
{
    clearGame();
}

void Game::keyPressEvent(QKeyEvent*ev)
{
    if(isPlayerOneActive)
    {
        switch(ev->key())
        {
        case Qt::Key_Up:
            men1->velocity.setY(-1);//加速
            //men1->moveBy(0,-1);太慢
            break;
        case Qt::Key_Down:
            men1->velocity.setY(1);

            break;
        case Qt::Key_Left:
            men1->velocity.setX(-1);

            break;
        case Qt::Key_Right:
            men1->velocity.setX(1);

            break;
        }
    }
    else
    {
        switch(ev->key())
        {
        case Qt::Key_Q:
            men2->velocity.setY(-1);

            break;
        case Qt::Key_W:
            men2->velocity.setY(1);

            break;
        case Qt::Key_E:
            men2->velocity.setX(-1);

            break;
        case Qt::Key_S:
            men2->velocity.setX(1);

            break;
        }
    }
}

void Game::keyReleaseEvent(QKeyEvent*ev)
{

    if(isPlayerOneActive)
    {
        switch(ev->key())
        {
        case Qt::Key_Up:
            men1->velocity.setY(0);//加速
            //men1->moveBy(0,-1);太慢
            break;
        case Qt::Key_Down:
            men1->velocity.setY(0);
            //men1->moveBy(0,1);
            break;
        case Qt::Key_Left:
            men1->velocity.setX(0);
            //men1->moveBy(-1,0);
            break;
        case Qt::Key_Right:
            men1->velocity.setX(0);
            //men1->moveBy(1,0);
            break;
        }
    }
    else
    {
        switch(ev->key())
        {
        case Qt::Key_Q:
            men2->velocity.setY(0);
            //men2->moveBy(0,-1);
            break;
        case Qt::Key_W:
            men2->velocity.setY(0);
            //men2->moveBy(0,1);
            break;
        case Qt::Key_E:
            men2->velocity.setX(0);
            //men2->moveBy(-1,0);
            break;
        case Qt::Key_S:
            men2->velocity.setX(0);
            //men2->moveBy(1,0);
            break;
        }
    }
}

