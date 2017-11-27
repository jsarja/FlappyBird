#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QFont>


class Score : public QGraphicsTextItem {
public:
    Score();
    void update();
    int getScore();
private:
    float ammount;
};

#endif // SCORE_H
