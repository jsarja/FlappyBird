#ifndef BIRD_H
#define BIRD_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QTimer>
#include <math.h>
#include <QKeyEvent>
#include <QList>
#include <typeinfo>
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsScene>

#include "pipes.h"
#include "spawner.h"


class Bird : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bird();
    void keyPressEvent(QKeyEvent* event);
    bool GameStarted;
    Spawner* spawn;
    QTimer* ajastin;
public slots:
    void move();
private:
    int imagine_x;
};

#endif // BIRD_H
