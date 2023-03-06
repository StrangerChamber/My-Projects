#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include <QColor>
#include <QColorDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) ://constructor to bring everything together at the start of each instance
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentColor(QColor("#000")),
    game(new GameWidget(this))
{
    ui->setupUi(this);

    QPixmap icon(16, 16);
    icon.fill(currentColor);
    ui->colorButton->setIcon( QIcon(icon) );

    connect(ui->startButton, SIGNAL(clicked()), game,SLOT(startGame()));//connecting all my buttons
    connect(ui->stopButton, SIGNAL(clicked()), game,SLOT(stopGame()));
    connect(ui->clearButton, SIGNAL(clicked()), game,SLOT(clear()));
    connect(ui->colorButton, SIGNAL(clicked()), this, SLOT(selectMasterColor()));
    connect(ui->StepButton, SIGNAL(clicked()), game, SLOT(step()));

    ui->mainLayout->setStretchFactor(ui->gameLayout, 8);
    ui->mainLayout->setStretchFactor(ui->setLayout, 2);
    ui->gameLayout->addWidget(game);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::selectMasterColor()//for my next feature
{
    QColor color = QColorDialog::getColor(currentColor, this, tr("Select color of figures"));
    if(!color.isValid())
        return;
    currentColor = color;
    game->setMasterColor(color);
    QPixmap icon(16, 16);
    icon.fill(color);
    ui->colorButton->setIcon( QIcon(icon) );
}

