#include "timer.h"
#include <QDebug>

timer::timer(QWidget * parent) : QWidget(parent)
{
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    connect(m_timer, &QTimer::timeout, this, &timer::onTimerOut);
}

void timer::startTimer()
{
    m_timer->start();
}

void timer::stopTimer()
{
    m_timer->stop();
}

void timer::pauseTimer()
{
    m_timer->stop();
}

void timer::onTimerOut()
{
    if (m_countDown > 0)
    {
        m_countDown--;
        emit countChanged();
    }
    else
    {
//        emit timerFinished();
        return;
    }
    qInfo() << m_countDown;
}

int timer::countDown()
{
    return m_countDown;
}

void timer::setCountDown(int countDown)
{
    m_countDown = countDown * 60;
}
