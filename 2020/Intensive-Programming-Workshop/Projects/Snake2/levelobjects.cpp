#include <QTimer>
#include <QGraphicsScene>
#include "levelobjects.h"
#include "snakeitem.h"
#include "Gameview.h"

extern GameView* game;
LevelObjects::LevelObjects()
{
    QTimer *foodTimer = new QTimer(), *enemyTimer = new QTimer();
    QObject::connect(foodTimer, SIGNAL(timeout()), this, SLOT(newFood()));//slot for food to pop up
    foodTimer->start(3000);
    QObject::connect(enemyTimer, SIGNAL(timeout()), this, SLOT(newEnemy()));// slot for enemies to pop up
    enemyTimer->start(3000);
}

bool LevelObjects::isEnemy()
{
    return enemy;
}

bool LevelObjects::isFood()
{
    return food;
}

void LevelObjects::newFood()//create food
{
    SnakeItem* food = new SnakeItem(true);
    game->scene->addItem(food);
}

void LevelObjects::newEnemy()//create enemy
{
    SnakeItem* enemy = new SnakeItem(false);
    game->scene->addItem(enemy);
}
