#ifndef SPAWNER_H
#define SPAWNER_H

#include <QObject>
#include <QTimer>


class Spawner: public QObject {
    Q_OBJECT
public:
    Spawner();
    QTimer* ajastin;
public slots:
    void addPipes();
    void deleteMsg();
};

#endif // SPAWNER_H
