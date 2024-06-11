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

//定义两个玩家
Men1 *men1;
Men2 *men2;
Ball *ball;
End *ed;

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
    men1 = new Men1(200,525,"Player1_b.png");
    men2 = new Men2(1000,500,"Player2.png");
    ball = new Ball(310,620,0.0,0.0,0.0,0.0,"Ball.png");
    ball->active = false;
        la->setText("yes");
        la->setGeometry(0, 0, 1280, 720);
}

//清理游戏
void Game::clearGame()
{

}

//更新游戏
void Game::updateGame()
{
    if(active == true && (score1 == 100 || score2 == 100))
    {
        active = false;
        ed = new End;
        ed->over();

    }
    if(active == true)
    {
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

                //1.鍒嗘暟++ 2.閲嶅紑涓€灞€
                if(ball->position.x() < 640)
                {
                    score2 += 1;
                    this->intiGame();
                }
                else if(ball->position.x() > 640)
                {
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
            if(men2->position.y() == 500)
                men2->Vy = -10;
            break;
        case Qt::Key_Down:
            ball->kik2(men2->position.x()+50,men2->position.y()-10);
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
                ball->kik1(men1->position.x()+100,men1->position.y()-20);
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
            men1->velocity.setY(0);
//            men1->gameloop();

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

void Game::mouseMoveEvent(QMouseEvent *e)
{
    la->setText("("+QString::number(e->x())+","+QString::number(e->y())+")");
}
