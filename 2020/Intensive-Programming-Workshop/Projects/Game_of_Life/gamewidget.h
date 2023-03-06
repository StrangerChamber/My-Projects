#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QColor>
#include <QWidget>

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);


signals:

    void environmentChanged(bool ok);//lock size when a cell has been changed

    void gameEnds(bool ok);//signal for game is over

public slots:

    void clear(); //clear

    void step(); //step

    void startGame(const int &number = -1); //start

    void stopGame(); // finish

    QColor masterColor(); // color of the cells

    void setMasterColor(const QColor &color); // set color of the cells

private slots:
    void paintGrid(QPainter &p);
    void paintUni(QPainter &p);
    void newGen();//heavy duty function where most of the work for computing the next generation is done

private:
    QColor m_masterColor;
    QTimer* timer;
    int generations;
    bool* universe; // map
    bool* next; // map
    int universeSize;//used for above maps
    bool isAlive(int k, int j); // return true if universe[k][j] accept rules
};

#endif // GAMEWIDGET_H
