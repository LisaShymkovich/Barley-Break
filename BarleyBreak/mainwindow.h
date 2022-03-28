#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();
    void timeRestart();

private slots:

    void on_toBarleyBreak_cellClicked(int row, int column);

    void on_menuNewGame_triggered();

    void on_menuRestart_triggered();

    void on_menuExit_triggered();

    void TimerSlot();



private:
    Ui::MainWindow *ui;
    QTableWidgetItem *itBarleyBreak = new QTableWidgetItem ; // не забываем подключить библиотеку
    QTableWidgetItem *itEmpty = new QTableWidgetItem;
    QTimer *timer;
    int sec;
    int min;
    void showTable();
};
#endif // MAINWINDOW_H
