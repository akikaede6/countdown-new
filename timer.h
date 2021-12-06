#ifndef TIMER_H
#define TIMER_H
#include <QWidget>
#include <QTimer>

class timer: public QWidget
{
public:
    explicit timer(QWidget * parent = nullptr);

    int countDown();
    void setCountDown(int countDown);

signals:
//    void timerFinished();
    void countChanged();

public slots:
    void startTimer();
    void stopTimer();
    void pauseTimer();
    void onTimerOut();

private:
    QTimer *m_timer;
    int m_countDown;
};

#endif // TIMER_H
