#include <QApplication>

#include "h-files/game.h"

Game* newGame;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    newGame = new Game();
    newGame->show();

    return a.exec();
}
