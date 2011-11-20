#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QCloseEvent>
#include <QKeyEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *);
    void keyPressEvent(QKeyEvent *);
private:
    QLabel *time_label;
    QTimer *timer;
    int cur_time;
    bool running;
private slots:
    void updateTime();

};

#endif // MAINWINDOW_H
