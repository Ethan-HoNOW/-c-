#ifndef GAME_H
#define GAME_H

#include <QWidget>

class Game : public QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    //运行
    void run();
    //初始化游戏
    void intiGame();
    //清理游戏
    void clearGame();
    //更新游戏
    void updateGame();
    //绘制游戏
    void drawGame(QPainter* painter);

protected:
    virtual void paintEvent(QPaintEvent* ev)override;
    virtual void closeEvent(QCloseEvent* ev)override;

private:
    int score1 = 0;//玩家一得分
    int score2 = 0;//玩家二得分

};

#endif // GAME_H
