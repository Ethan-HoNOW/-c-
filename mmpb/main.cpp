#include <QApplication>
#include "game.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game game;
    game.run();
    game.intiGame();
    return a.exec();
}
