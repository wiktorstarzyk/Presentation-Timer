#include "mainwindow.h"

#include <QTime>
#include <QString>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->showFullScreen();

    cur_time = 0; // Keeps track of the seconds elapsed since the timer was started
    running = false;

    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));

    // Create the label that displays the time
    time_label = new QLabel();
    time_label->setAlignment(Qt::AlignCenter);
    time_label->setFont(QFont("Helvetical", 200));
    time_label->setText("00:00");
    time_label->setAutoFillBackground(true);
    time_label->setStyleSheet("QLabel { background-color : rgb(85, 255, 127) }");
    setCentralWidget(time_label);

    setWindowTitle("Presentation Timer");
    this->setFocus();
}


MainWindow::~MainWindow()
{

}

/*
 * This method updates the current time and the label that displays the time.
 */
void MainWindow::updateTime()
{
    // Increment the number of seconds elapsed
    cur_time += 1;

    // Convert the number of seconds to minutes and seconds
    int min = cur_time / 60.0;
    int sec = cur_time - (min * 60);

    // Update the label that displays the time
    QTime time = QTime(0, min, sec);
    QString text = time.toString("mm:ss");
    time_label->setText(text);

    // Change the background color based on the time.
    if (min == 1 && sec == 30)
    {
        time_label->setStyleSheet("QLabel { background-color : rgb(255, 255, 127) }");
    }
    else if (min == 1 && sec == 45)
    {
        time_label->setStyleSheet("QLabel { background-color : rgb(255, 116, 24) }");
    }
    else if (min == 2 && sec == 0)
    {
        time_label->setStyleSheet("QLabel { background-color : rgb(255, 0, 0) }");
    }
}


void MainWindow::closeEvent(QCloseEvent *event){
    QMainWindow::closeEvent(event);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // The spacebar is used to toggle the timer
    if (event->key() == Qt::Key_Space)
    {
        if(running)
        {
            timer->stop();
            running = false;
        }
        else
        {
            timer->start(1000);
            running = true;
        }
    }
    // The R key is used to reset the timer
    else if (event->key() == Qt::Key_R)
    {
        cur_time = 0;
        timer->stop();
        time_label->setText("00:00");
        time_label->setStyleSheet("QLabel { background-color : rgb(255, 255, 127) }");
    }
    // The Q key is used to quite the application
    else if (event->key() == Qt::Key_Q)
    {
        exit(0);
    }
    QMainWindow::keyPressEvent(event);
}
