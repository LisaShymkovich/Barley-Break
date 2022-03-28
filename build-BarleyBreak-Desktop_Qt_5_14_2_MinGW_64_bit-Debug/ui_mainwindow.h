/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *menuNewGame;
    QAction *menuRestart;
    QAction *menuExit;
    QWidget *centralwidget;
    QTableWidget *toBarleyBreak;
    QTextEdit *toMoves;
    QLineEdit *DigitalClock;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 700);
        menuNewGame = new QAction(MainWindow);
        menuNewGame->setObjectName(QString::fromUtf8("menuNewGame"));
        menuRestart = new QAction(MainWindow);
        menuRestart->setObjectName(QString::fromUtf8("menuRestart"));
        menuExit = new QAction(MainWindow);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        toBarleyBreak = new QTableWidget(centralwidget);
        if (toBarleyBreak->columnCount() < 4)
            toBarleyBreak->setColumnCount(4);
        if (toBarleyBreak->rowCount() < 4)
            toBarleyBreak->setRowCount(4);
        toBarleyBreak->setObjectName(QString::fromUtf8("toBarleyBreak"));
        toBarleyBreak->setGeometry(QRect(200, 150, 402, 402));
        toBarleyBreak->setRowCount(4);
        toBarleyBreak->setColumnCount(4);
        toBarleyBreak->horizontalHeader()->setVisible(false);
        toBarleyBreak->horizontalHeader()->setMinimumSectionSize(28);
        toBarleyBreak->horizontalHeader()->setHighlightSections(false);
        toBarleyBreak->verticalHeader()->setVisible(false);
        toBarleyBreak->verticalHeader()->setHighlightSections(false);
        toMoves = new QTextEdit(centralwidget);
        toMoves->setObjectName(QString::fromUtf8("toMoves"));
        toMoves->setGeometry(QRect(200, 80, 201, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        toMoves->setFont(font);
        DigitalClock = new QLineEdit(centralwidget);
        DigitalClock->setObjectName(QString::fromUtf8("DigitalClock"));
        DigitalClock->setGeometry(QRect(430, 80, 171, 41));
        QFont font1;
        font1.setPointSize(24);
        DigitalClock->setFont(font1);
        DigitalClock->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(menuNewGame);
        menu->addAction(menuRestart);
        menu->addAction(menuExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        menuNewGame->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217", nullptr));
        menuRestart->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\321\201\321\202\320\260\321\200\321\202", nullptr));
        menuExit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\230\320\263\321\200\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
