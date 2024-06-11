#include "game.h"
#include<QIcon>
#include<QPainter>
#include<QTimer>
#include<QPixmap>
#include<QLabel>
#include<QString>
#include<QKeyEvent>
#include "end.h"
#include"Men1.h"
#include"Men2.h"
#include "Player.h"
#include "ball.h"
#include "light.h"
//定义两个玩家
Men1 *men1;
Men2 *men2;
Ball *ball;
End *ed;
Light *light1;
Light *light2;
int Px1 = 200;
int Py1 = 525;
int Px2  = 1000;
int Py2  = 500;
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
    setWindowIcon(QIcon("ico2.ico"));
    men1 = new Men1(Px1,Py1,"Player1_b.png");
    men2 = new Men2(Px2,Py2,"Player2.png");
    ball = new Ball(310,620,0.0,0.0,0.0,0.0,"Ball.png");
    light1 = new Light("Light1.png");
    light1->active = 0;
    light2 = new Light("Light2.png");
    light2->active = 0;
    ball->active = false;
//    la->setText("yes");
//    la->setGeometry(0, 0, 1280, 720);
}

//清理游戏
void Game::clearGame()
{

}

//更新游戏
void Game::updateGame()
{
    if(active == true && score1 == 7)
    {
        active = false;
        ed = new End;
        ed->over(score1);
    }
    else if(active == true && score2 == 7)
    {
        active = false;
        ed = new End;
        score2++;
        ed->over(score2);
    }
    if(active == true)
    {
        light1->position.setX(men1->position.x() + 45);
        light1->position.setY(men1->position.y() -5);
        light2->position.setX(men2->position.x() + 5);
        light2->position.setY(men2->position.y() +5);
        men1->update();
        men2->update();
        ball->update();
        if(ball->active == false)
        {
            ball->position.setX(men1->position.x() + 110);
            ball->position.setY(men1->position.y() + 95);
        }


        if(ball->position.y() > 640 && ball->position.y() <= 710)
            {

                //1.分数++ 2.restart
                if(ball->position.x() < 640)
                {
                    Px1 = men1->position.x();
                    Py1 = men1->position.y();
                    Px2  = men2->position.x();
                    Py2  = men2->position.y();
                    score2 += 1;
                    this->intiGame();
                }
                else if(ball->position.x() > 640)
                {

                    Px1 = men1->position.x();
                    Py1 = men1->position.y();
                    Px2  = men2->position.x();
                    Py2  = men2->position.y();
                    score1 += 1;
                    this->intiGame();
                }
            }
    }


}
bool Game::isWin()
{
    if(score1==7||score2==7)
        return true;
}
//绘制游戏
void Game::drawGame(QPainter* painter)
{
    men1->draw(painter);
    men2->draw(painter);
    ball->draw(painter);
    if(light1 -> active == 1)
    {
        light1->draw(painter);
    }
    if(light2 -> active == 1)
    {
        light2->draw(painter);
    }
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
    QPainter painter(this);
    if(isPlayerOneActive)
    {
        switch(ev->key())
        {
        case Qt::Key_Up:
            if(men2->position.y() == 500)
                men2->Vy = -10;
            break;
        case Qt::Key_Down:
            ball->kik2(men2->position.x()+50,men2->position.y());
//            Dx->setText(QString("Dx=") + QString("%1").arg(ball->dx));
//            Dx->setGeometry(0, 0, 1000, 620);
//            d->setText(QString("d=") + QString("%1").arg(ball->d));
//            d->setGeometry(0, 0, 1000, 820);
            light2->active = 1;
            break;
        case Qt::Key_Left:
            men2->velocity.setX(-2);
            break;
        case Qt::Key_Right:
            men2->velocity.setX(2);

            break;
        case Qt::Key_W:
            if(men1->position.y() == 525)
                men1->Vy = -10;
            break;
        case Qt::Key_S:
            if(ball->active == false)
            {
                ball -> active = true;
                ball->Vx = 10;
                ball->Vy =-16;
            }
            if(ball->act == 1)
            {
                ball->kik1(men1->position.x()+100,men1->position.y()-10);
            }
            light1->active = 1;
            break;
        case Qt::Key_A:
            men1->velocity.setX(-2);

            break;
        case Qt::Key_D:

            men1->velocity.setX(2);

            break;
        case Qt::Key_R:
            score1 = score2 = 0;
            active = true;
            Px1 = 200;
            Py1 = 525;
            Px2  = 1000;
            Py2  = 500;
            this->intiGame();
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
            light2->active = 0;

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
            men1->velocity.setY(0);
//            men1->gameloop();

            break;
        case Qt::Key_S:
            light1->active = 0;

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

//void Game::mouseMoveEvent(QMouseEvent *e)
//{
//    la->setText("("+QString::number(e->x())+","+QString::number(e->y())+")");
//}
