#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "SnakeNode.h"

class Player: public QObject, public QGraphicsRectItem{

    Q_OBJECT

public:
    Player(); //for move slot
    void keyPressEvent(QKeyEvent* event);//to move the snake
    void addLink(); // add a link to the tail
    void updateTail(); //tail movement
    void updateTailEnd(SnakeNode*); //tail movement helper
    void checkCollisions(); // check for collisions with food and enemies
    void outOfBounds(); //move player back in bounds after going out
    void loseLink(); //lose a tail link
    void win();//winner message
    void lose(); //loser message
    void rules(); //rules box in beginning
private:
    int xvel;
    int yvel;
    SnakeNode *head;
    int count;
public slots:
    void move();
};

#endif // PLAYER_H
