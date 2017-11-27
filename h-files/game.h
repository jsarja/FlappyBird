#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QPushButton>
#include <QGraphicsTextItem>
#include <fstream>

#include "score.h"
#include "bird.h"


class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game();
    Bird* player;
    QGraphicsScene* scene;
    Score* score;
    QGraphicsTextItem* guideText;
    int highScore;
    bool ended;
    bool unpaused;

    void gameOver();
public slots:
    void startNew();
private:
    void loadHighScore();
    void updateHighScore();


};

#endif // GAME_H
