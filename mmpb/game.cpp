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
    men1 = new Men1(200,500,"Player.png");
    men2 = new Men2(1000,500,"Player.png");
}

//清理游戏
void Game::clearGame()
{

}

//更新游戏
void Game::updateGame()
{
    men1->update();
    men2->update();
}

//绘制游戏
void Game::drawGame(QPainter* painter)
{
    men1->draw(painter);
    men2->draw(painter);
}

void Game::paintEvent(QPaintEvent* ev)
{
    QPainter painter(this);


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

    drawGame(&painter);
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

            break;
        case Qt::Key_Down:


            break;
        case Qt::Key_Left:
            men2->velocity.setX(-2);

            break;
        case Qt::Key_Right:
            men2->velocity.setX(2);

            break;
        case Qt::Key_W:


            break;
        case Qt::Key_S:


            break;
        case Qt::Key_A:
            men1->velocity.setX(-2);

            break;
        case Qt::Key_D:
            men1->velocity.setX(2);

            break;
        }
    }
}

void Game::keyReleaseEvent(QKeyEvent*ev)
{

        switch(ev->key())
        {
        case Qt::Key_Up:


            break;
        case Qt::Key_Down:


            break;
        case Qt::Key_Left:
            men2->velocity.setX(0);
            //men1->moveBy(-1,0);
            break;
        case Qt::Key_Right:
            men2->velocity.setX(0);
            //men1->moveBy(1,0);
            break;
        case Qt::Key_W:


            break;
        case Qt::Key_S:


            break;
        case Qt::Key_A:
            men1->velocity.setX(0);
            //men2->moveBy(-1,0);
            break;
        case Qt::Key_D:
            men1->velocity.setX(0);
            //men2->moveBy(1,0);
            break;
        }
}

