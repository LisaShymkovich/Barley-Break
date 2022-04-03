#include "mainwindow.h"
#include "barley_break.h"
#include "ui_mainwindow.h"
#include "digitalclock.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QTime>


Barley_Break bb;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    timeRestart();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerSlot()));
    timer->start(1000);

    for (auto i=0; i< 4; i++)
    {
        ui->toBarleyBreak->setColumnWidth(i,100);
        ui->toBarleyBreak->setRowHeight(i,100);

    }
    ui->toBarleyBreak->setEditTriggers(0);
    showTable();
}


void MainWindow::showTable()
{
    for(auto i=0;i<4;i++)
    {
        for(auto j=0;j<4; j++)
        {
            QTableWidgetItem* item = new QTableWidgetItem(*itBarleyBreak);
            item->setText(QString::number(bb.getItem(i,j)));
            ui->toBarleyBreak->setItem(i,j,item);
        }
    }
    ui->toBarleyBreak->setItem(bb.getEmptyR(), bb.getEmptyC(), new QTableWidgetItem(*itEmpty));
    ui->toMoves->setText("Moves: " + QString::number(bb.getMovesNumber()));
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_toBarleyBreak_cellClicked(int row, int column)
{

    bb.reCalc(row, column);
    showTable();

    if(bb.isFinished())
    {

        QMessageBox::information(this, "Игра закончена!", "Победа!");
        QApplication::quit();
    }

}

void MainWindow::TimerSlot()
{
    sec++;
    if(sec >=60)
    {
        sec=0;
        min++;
    }
    if(sec<10)
    {
          ui->DigitalClock->setText(QString::number(min)+ " : " + "0" + QString::number(sec));
    }
    else  ui->DigitalClock->setText(QString::number(min)+ " : " +QString::number(sec));
}

void MainWindow::timeRestart()
{
    sec=0;
    min=0;
}


void MainWindow::on_menuNewGame_triggered()
{

    timeRestart();
    bb.startGame();
    showTable();
}



void MainWindow::on_menuRestart_triggered()
{
    timeRestart();
    bb.restartGame();
    showTable();
}

void MainWindow::on_menuExit_triggered()
{
    QApplication::quit();
}


