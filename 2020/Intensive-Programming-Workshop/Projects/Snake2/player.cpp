#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <QDebug>
#include <cstdlib>
#include <QMessageBox>
#include "player.h"
#include "snakeitem.h"

// Constructor
Player::Player(): xvel(4), yvel(0), head(nullptr), count(0)
{
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));//slot for the game play of the snake
    timer->start(10);


}

void Player::rules(){//display message box with rules
    QMessageBox Msgbox;
    Msgbox.setText("So you've decided to play my snake game. The rules are as follows: hit a blue square and your snake gains one box, hit a red square and you lose one box. To win you need 25 boxes. If your snake loses it's whole tail you lose. Use your arrow keys to direct the snake and GOOD LUCK :) ");
    Msgbox.exec();
}

// Adds a tail
void Player::addLink()
{
    SnakeNode* node = head;
    if(node == nullptr){
        head = new SnakeNode();
        scene()->addItem(head);
        head->setRect(0, 0, 15, 15);
    }
    else{
        while(node->next != nullptr){
            node = node->next;
        }
        node->next = new SnakeNode();
        node->next->setRect(0, 0, 15, 15);
        scene()->addItem(node->next);
    }
}

// Move the tail following the player
void Player::updateTail()
{
 SnakeNode* node = head;
 if(head != nullptr){
     updateTailEnd(node);
     head->setPos(x()+scene()->width()/2, y()+ scene()->height()/2);
 }
}

// Recursively move the tail following the player
void Player::updateTailEnd(SnakeNode * node)
{
    if(node->next != nullptr){
        updateTailEnd(node->next);
        node->next->setPos(node->x(), node->y());
    }
}

void Player::checkCollisions()
{
    // Check Collision with enemies
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0; i < colliding_items.size(); i++){

        if(typeid(*colliding_items[i]) == typeid (SnakeItem)){

            if(static_cast<SnakeItem*>(colliding_items[i])->isFood()){//if collide with food add a link and check if they have enough links to win

               scene()->removeItem(colliding_items[i]);

               delete colliding_items[i];

               addLink();

               win();
            }
            else{//hit an enemy shorten the tail and check if whole tail is lost

                loseLink();

                scene()->removeItem(colliding_items[i]);

                delete colliding_items[i];
            }
        }
    }
}


//lose sequence message
void Player::lose(){
        QMessageBox Msgbox;
        Msgbox.setText("You have lost! You lost everything but your head! You can now keep trying again. Better luck next time");
        Msgbox.exec();
        return;
}

//win sequence

void Player::win(){
    SnakeNode* node = head;
    int counter = 0;
    while(node->next != nullptr){//count how many links there are with counter
        counter++;
        node = node->next;
    }
    if(counter >= 25){//if greater than 24 you win!
        QMessageBox Msgbox;
        Msgbox.setText("You have won! Congratulations now try and get 25 more links!");
        Msgbox.exec();
        //win game with winner message
    }
    return;
}


//lose a tail link
void Player::loseLink(){
    SnakeNode* node = head;
    if(head->next == nullptr){
        lose();
        return;
    }
    while(node->next->next != nullptr){
        node = node->next;
    }
    scene()->removeItem(node->next);
    delete (node->next);
    node->next = NULL;
    return;
}



void Player::outOfBounds()
{
    // Move the character back in bounds if they attempt to go out
    if(x() > scene()->width()/2 - this->rect().width()){
        setPos(-scene()->width()/2, y()+yvel);
    }
    else if( y() > scene()->height()/2 - this->rect().height()){
        setPos(x(), -scene()->height()/2);
    }
    else if( x() < -scene()->width()/2){
        setPos(scene()->width()/2, y()+yvel);
    }
    else if( y() < -scene()->height()/2){
        setPos(x(), scene()->height()/2);
    }
}

void Player::move()
{
    //display rules upon start
    if(count == 0){
        rules();
        count++;
    }

    // keep the player in the playing rectangle
    outOfBounds();

    // check for any hits with enemy or food
    checkCollisions();

    // update tail movement with player
    updateTail();

    //correct player position
    setPos(x()+xvel, y()+yvel);
    this->setFocus();

}

// Change direction if the player presses an arrow key
void Player::keyPressEvent(QKeyEvent* event)
{
    qDebug() << event->key() << " pressed.";
    if(event->key() == Qt::Key_Right && xvel == 0){
        xvel = 4; yvel = 0;
    }
    else if(event->key() == Qt::Key_Left && xvel == 0){
        xvel = -4; yvel = 0;
    }
    else if(event->key() == Qt::Key_Down && yvel == 0){
        xvel = 0; yvel = 4;
    }
    else if(event->key() == Qt::Key_Up && yvel == 0){
        xvel = 0; yvel = -4;
    }
}
