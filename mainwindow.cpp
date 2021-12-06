#include "mainwindow.h"

#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_player = new musicplayer(this);
    m_countTimer = new timer(this);
    initUI();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initUI()
{
    //replace raw points to smart points
    //clang tidy
    QWidget *window = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *bgmLayout = new QHBoxLayout;
    QHBoxLayout *timeLayout = new QHBoxLayout;
    QHBoxLayout *labelLayout = new QHBoxLayout;

    m_bgmLabel = new QLabel;
    m_bgmBox = new QComboBox;

    m_timeEdit = new QLineEdit;
    m_timeLabel = new QLabel;
    m_startbtn = new QPushButton;
    m_cancelbtn = new QPushButton;
    m_pausebtn = new QPushButton;

    m_minuteLabel = new QLabel;
    m_colonLabel = new QLabel;
    m_secondLabel = new QLabel;


    bgmLayout->addWidget(m_bgmLabel);
    bgmLayout->addWidget(m_bgmBox);

    timeLayout->addWidget(m_timeEdit);
    timeLayout->addWidget(m_timeLabel);
    timeLayout->addWidget(m_startbtn);
    timeLayout->addWidget(m_cancelbtn);
    timeLayout->addWidget(m_pausebtn);

    labelLayout->addWidget(m_minuteLabel);
    labelLayout->addWidget(m_colonLabel);
    labelLayout->addWidget(m_secondLabel);

    mainLayout->addLayout(bgmLayout);
    mainLayout->addLayout(timeLayout);
    mainLayout->addLayout(labelLayout);

    window->setLayout(mainLayout);
    setCentralWidget(window);


    m_bgmLabel->setText(tr("bgm"));
    m_bgmBox->addItem(tr("bgm1"));
    m_bgmBox->addItem(tr("bgm2"));
    m_bgmBox->addItem(tr("bgm3"));

    m_timeLabel->setText(tr("minute"));
    m_startbtn->setText(tr("start"));
    m_cancelbtn->setText(tr("cancel"));
    m_pausebtn->setText(tr("pause"));

    m_minuteLabel->setText(tr("00"));
    m_colonLabel->setText(tr(":"));
    m_secondLabel->setText(tr("00"));

    m_pausebtn->setEnabled(false);
    m_cancelbtn->setEnabled(false);

    connect(m_startbtn, &QPushButton::clicked, this, &MainWindow::onStartBtnClicked);
    connect(m_pausebtn, &QPushButton::clicked, this, &MainWindow::onPauseBtnClicked);
    connect(m_cancelbtn, &QPushButton::clicked, this, &MainWindow::onCancelBtnClicked);
//    connect(m_countTimer, &timer::countChanged, this, &MainWindow::setCountView);
//    connect(m_countTimer, &timer::timerFinished, this, &MainWindow::onCancelBtnClicked);
}

void MainWindow::onStartBtnClicked()
{
    m_player->setMusicNumber(m_bgmBox->currentIndex());
    m_countTimer->setCountDown(m_timeEdit->text().toInt());
    m_player->startMusic();
    m_countTimer->startTimer();
    m_startbtn->setEnabled(false);
    m_pausebtn->setEnabled(true);
    m_cancelbtn->setEnabled(true);
}

void MainWindow::onCancelBtnClicked()
{
    m_player->stopMusic();
    m_countTimer->stopTimer();
    m_startbtn->setEnabled(true);
    m_pausebtn->setEnabled(false);
    m_cancelbtn->setEnabled(false);
}

void MainWindow::onPauseBtnClicked()
{
    if (m_player->getPlayState() == QMediaPlayer::PlayingState)
    {
        m_player->pauseMusic();
        m_countTimer->pauseTimer();
        m_pausebtn->setText(tr("continue"));
    }
    else if (m_player->getPlayState() == QMediaPlayer::PausedState)
    {
        m_player->startMusic();
        m_countTimer->startTimer();
        m_pausebtn->setText(tr("pause"));
    }
    else
    {
        qCritical() << "play state error";
        return;
    }
}

void MainWindow::setCountView()
{

}
