#include <QMessageBox>
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>
#include <QRectF>
#include <QPainter>
#include <qmath.h>
#include <stdlib.h>
#include <time.h>
#include "gamewidget.h"

GameWidget::GameWidget(QWidget *parent) ://constructor sets variables and randomizes board on start
    QWidget(parent),
    timer(new QTimer(this)),
    generations(-1),
    universeSize(20)
{
    timer->setInterval(300);
    m_masterColor = "#000";
    srand(time(NULL));
    universe = new bool[(universeSize + 2) * (universeSize + 2)];
    next = new bool[(universeSize + 2) * (universeSize + 2)];
    connect(timer, SIGNAL(timeout()), this, SLOT(newGen()));//connecting timer
    for(unsigned long i = 0; i<sizeof(universe);i++){//randomizing the starting field
        int num = rand()%100;
        if(num<50){
            next[i] = true;
            universe[i]=true;
        }else{
            next[i] = false;
            universe[i]=false;
        }
    }
}

GameWidget::~GameWidget()//deconstuctor
{
    delete [] universe;
    delete [] next;
}

void GameWidget::startGame(const int &number)//start button function
{
    generations = number;
    timer->start();
}

void GameWidget::stopGame()//stop button function
{
    timer->stop();
}



void GameWidget::step(){//function for step button
    newGen();
}


void GameWidget::clear()//clear button function
{
    for(int k = 1; k <= universeSize; k++) {
        for(int j = 1; j <= universeSize; j++) {
            universe[k*universeSize + j] = false;
        }
    }
    gameEnds(true);
    update();
}

bool GameWidget::isAlive(int k, int j)//takes in cell location and check surrounding cells to determine whether it should stay alive or not or vice versa
{
    int pow = 0;
    pow += universe[(k+1)*universeSize +  j];
    pow += universe[(k-1)*universeSize + j];
    pow += universe[k*universeSize + (j+1)];
    pow += universe[k*universeSize + (j-1)];
    pow += universe[(k+1)*universeSize + ( j-1)];
    pow += universe[(k-1)*universeSize + (j+1)];
    pow += universe[(k-1)*universeSize + (j-1)];
    pow += universe[(k+1)*universeSize +  (j+1)];//checking each cell around the input one to see whether it should stay alive or not
    if (((universe[k*universeSize + j] == true) && (pow == 2)) || (pow == 3))//returning true or false based on the rules of the game
           return true;
    return false;
}

void GameWidget::newGen()//this is the process for going from one generation to the next
{
    if(generations < 0)
        generations++;
    int noChange=0;
    for(int k=1; k <= universeSize; k++) {
        for(int j=1; j <= universeSize; j++) {
            next[k*universeSize + j] = isAlive(k, j);
            if(next[k*universeSize + j] == universe[k*universeSize + j])
                noChange++;
        }
    }
    if(noChange == universeSize*universeSize) {
        QMessageBox::information(this,
                                 tr("Game lost sense"),
                                 tr("The End. Now game finished because all the next generations will be the same."),
                                 QMessageBox::Ok);
        stopGame();
        gameEnds(true);
        return;
    }
    for(int k=1; k <= universeSize; k++) {
        for(int j=1; j <= universeSize; j++) {
            universe[k*universeSize + j] = next[k*universeSize + j];
        }
    }
    update();
    generations--;
    if(generations == 0) {
        stopGame();
        gameEnds(true);
        QMessageBox::information(this,
                                 tr("Game finished."),
                                 tr("Iterations finished."),
                                 QMessageBox::Ok,
                                 QMessageBox::Cancel);
    }
}

void GameWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    paintGrid(p);
    paintUni(p);
}

void GameWidget::mousePressEvent(QMouseEvent *e)
{
    emit environmentChanged(true);
    double cellWidth = (double)width()/universeSize;
    double cellHeight = (double)height()/universeSize;
    int k = floor(e->y()/cellHeight)+1;
    int j = floor(e->x()/cellWidth)+1;
    universe[k*universeSize + j] = !universe[k*universeSize + j];
    update();
}

void GameWidget::mouseMoveEvent(QMouseEvent *e)
{
    double cellWidth = (double)width()/universeSize;
    double cellHeight = (double)height()/universeSize;
    int k = floor(e->y()/cellHeight)+1;
    int j = floor(e->x()/cellWidth)+1;
    int currentLocation = k*universeSize + j;
    if(!universe[currentLocation]){                //if current cell is empty,fill in it
        universe [currentLocation]= !universe[currentLocation];
        update();
    }
}


void GameWidget::paintUni(QPainter &p)
{
    double cellWidth = (double)width()/universeSize;
    double cellHeight = (double)height()/universeSize;
    for(int k=1; k <= universeSize; k++) {
        for(int j=1; j <= universeSize; j++) {
            if(universe[k*universeSize + j] == true) { // if there is any sense to paint it
                qreal left = (qreal)(cellWidth*j-cellWidth); // margin from left
                qreal top  = (qreal)(cellHeight*k-cellHeight); // margin from top
                QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
                p.fillRect(r, QBrush(m_masterColor)); // fill cell with brush of main color
            }
        }
    }
}


void GameWidget::paintGrid(QPainter &p)
{
    QRect borders(0, 0, width()-1, height()-1); // borders of the universe
    QColor gridColor = m_masterColor; // color of the grid
    gridColor.setAlpha(10); // must be lighter than main color
    p.setPen(gridColor);
    double cellWidth = (double)width()/universeSize; // width of the widget / number of cells at one row
    for(double k = cellWidth; k <= width(); k += cellWidth)
        p.drawLine(k, 0, k, height());
    double cellHeight = (double)height()/universeSize; // height of the widget / number of cells at one row
    for(double k = cellHeight; k <= height(); k += cellHeight)
        p.drawLine(0, k, width(), k);
    p.drawRect(borders);
}


QColor GameWidget::masterColor()
{
    return m_masterColor;
}

void GameWidget::setMasterColor(const QColor &color)
{
    m_masterColor = color;
    update();
}
