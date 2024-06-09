#include "game.h"
#include<QIcon>
#include<QPainter>
#include<QTimer>

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
    setFixedSize(1600,1000);
    setWindowTitle("Match Man Play Badminton");
    //QIcon = ;
    //setWindowIcon();
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
}

void Game::closeEvent(QCloseEvent* ev)
{
    clearGame();
}


