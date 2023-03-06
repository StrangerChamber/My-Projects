#ifndef SNAKENODE_H
#define SNAKENODE_H

#include <QGraphicsRectItem>

//struct used to create snake using linked list
struct SnakeNode: public QGraphicsRectItem
{
public:
    SnakeNode* next;
    SnakeNode();
};

inline SnakeNode::SnakeNode():next(nullptr){}

#endif // SNAKENODE_H
