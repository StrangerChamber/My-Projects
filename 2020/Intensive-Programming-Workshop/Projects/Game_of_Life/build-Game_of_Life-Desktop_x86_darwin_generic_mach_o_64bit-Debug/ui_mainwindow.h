/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *mainLayout;
    QVBoxLayout *gameLayout;
    QVBoxLayout *setLayout;
    QHBoxLayout *controlLayout;
    QPushButton *startButton;
    QPushButton *StepButton;
    QPushButton *stopButton;
    QPushButton *clearButton;
    QHBoxLayout *fileLayout;
    QPushButton *colorButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(700, 472);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mainLayout = new QHBoxLayout();
        mainLayout->setSpacing(6);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        gameLayout = new QVBoxLayout();
        gameLayout->setSpacing(6);
        gameLayout->setObjectName(QString::fromUtf8("gameLayout"));
        gameLayout->setContentsMargins(-1, -1, -1, 0);

        mainLayout->addLayout(gameLayout);

        setLayout = new QVBoxLayout();
        setLayout->setSpacing(6);
        setLayout->setObjectName(QString::fromUtf8("setLayout"));
        controlLayout = new QHBoxLayout();
        controlLayout->setSpacing(6);
        controlLayout->setObjectName(QString::fromUtf8("controlLayout"));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        controlLayout->addWidget(startButton);

        StepButton = new QPushButton(centralWidget);
        StepButton->setObjectName(QString::fromUtf8("StepButton"));

        controlLayout->addWidget(StepButton);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        controlLayout->addWidget(stopButton);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        controlLayout->addWidget(clearButton);


        setLayout->addLayout(controlLayout);

        fileLayout = new QHBoxLayout();
        fileLayout->setSpacing(6);
        fileLayout->setObjectName(QString::fromUtf8("fileLayout"));

        setLayout->addLayout(fileLayout);

        colorButton = new QPushButton(centralWidget);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));

        setLayout->addWidget(colorButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        setLayout->addItem(verticalSpacer);


        mainLayout->addLayout(setLayout);


        horizontalLayout->addLayout(mainLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Conway's Game of Life", nullptr));
        startButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
        StepButton->setText(QApplication::translate("MainWindow", "Step", nullptr));
        stopButton->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        colorButton->setText(QApplication::translate("MainWindow", "Select color for cells", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
