#ifndef PIPES_H
#define PIPES_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class pipes :public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    pipes();
    bool counted;
    QTimer* ajastin;
public slots:
    void move();
    void unpauseTimer();
};

#endif // PIPES_H
