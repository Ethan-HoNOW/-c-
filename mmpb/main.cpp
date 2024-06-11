#include <QApplication>
#include "game.h"
#include "start.h"
#include "end.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game game;
    game.run();
    game.intiGame();
    
    Start s;
    s.run();

    return a.exec();

}
