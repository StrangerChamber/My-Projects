#include <QTimer>
#include "Gameview.h"


GameView::GameView()
{
    // Create game environment variables
    scene = new QGraphicsScene();
    player = new Player();

    // Set up the game scene
    scene->addItem(player);
    this->setScene(scene);
    this->setFixedSize(800, 600);
    scene->setSceneRect(0,0,this->width(), this->height());

    // Set up the player
    player->setRect(scene->width()/2, scene->height()/2, 15,15);
    player->setBrush(QColor(0, 0, 0, 150));
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Prevent Scrolling
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Add food and enemies
    objects = new LevelObjects();
}
