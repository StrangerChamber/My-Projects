#include <cstdlib>
#include <QGraphicsScene>

#include "snakeitem.h"
#include "Gameview.h"

extern GameView* game;

SnakeItem::SnakeItem(bool isFood)
{
    int randWidth = rand()%(static_cast<int>(game->scene->width()));
    int randHeight = rand()%(static_cast<int>(game->scene->height()));
    setRect(randWidth,randHeight,12,12);

    // Set attribute to either a food or enemy
    if(isFood){
        food = true;
        enemy = false;
        this->setBrush(QColor(0, 0, 255, 150));
    }
    else {
        food = false;
        enemy = true;
        this->setBrush(QColor(255, 0, 0, 150));
    }
}

bool SnakeItem::isFood()
{
    return food;
}

bool SnakeItem::isEnemy()
{
    return enemy;
}
