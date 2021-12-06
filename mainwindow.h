#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "musicplayer.h"
#include "timer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initUI();

private slots:
    void onStartBtnClicked();
    void onCancelBtnClicked();
    void onPauseBtnClicked();
    void setCountView();

private:
    musicplayer *m_player;
    timer *m_countTimer;
    QLabel *m_bgmLabel;
    QComboBox *m_bgmBox;
    QLineEdit *m_timeEdit;
    QLabel *m_timeLabel;
    QPushButton *m_startbtn;
    QPushButton *m_cancelbtn;
    QPushButton *m_pausebtn;
    QLabel *m_minuteLabel;
    QLabel *m_colonLabel;
    QLabel *m_secondLabel;
};

#endif // MAINWINDOW_H
