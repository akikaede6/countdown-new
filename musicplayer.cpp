#include "musicplayer.h"

musicplayer::musicplayer(QWidget * parent) : QWidget(parent)
{
    m_musicPlayer = new QMediaPlayer(this);
    m_musicPlayerList = new QMediaPlaylist(this);
    m_musicPlayerList->addMedia(QUrl::fromLocalFile("/home/aki/1.mp3"));
    m_musicPlayerList->addMedia(QUrl::fromLocalFile("/home/aki/2.mp3"));
    m_musicPlayerList->addMedia(QUrl::fromLocalFile("/home/aki/3.mp3"));
    m_musicPlayer->setPlaylist(m_musicPlayerList);
    m_musicPlayerList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
}

void musicplayer::startMusic()
{
    m_musicPlayer->play();
}

void musicplayer::stopMusic()
{
    m_musicPlayer->stop();
}

void musicplayer::pauseMusic()
{
    m_musicPlayer->pause();
}

QMediaPlayer::State musicplayer::getPlayState() const
{
    return m_musicPlayer->state();
}

int musicplayer::musicNumber() const
{
    return m_musicNumber;
}

void musicplayer::setMusicNumber(int musicNumber)
{
    m_musicNumber = musicNumber;
    m_musicPlayerList->setCurrentIndex(m_musicNumber);
    qInfo() << m_musicNumber;
}
