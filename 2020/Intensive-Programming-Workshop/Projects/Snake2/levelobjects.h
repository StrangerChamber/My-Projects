#ifndef LEVELOBJECTS_H
#define LEVELOBJECTS_H

#include <QObject>
#include <QGraphicsRectItem>

class LevelObjects: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    LevelObjects();//contructor for slots
    bool isEnemy();
    bool isFood();
private:
    bool food;//to grow the snake
    bool enemy;//to shorten the snake
public slots:
    void newFood();
    void newEnemy();
};

#endif // LEVELOBJECTS_H
