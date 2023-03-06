#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsObject>

#include "player.h"
#include "levelobjects.h"

class GameView: public QGraphicsView
{
public:
    //Constructor
    GameView();

    //Game variables
    QGraphicsScene* scene; //used for displaying and removing objects
    Player* player; //object the player is
    LevelObjects* objects; //food and enemy objects
};

#endif // GAMEVIEW_H
