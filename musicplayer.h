#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class musicplayer: public QWidget
{
    Q_OBJECT
public:
    explicit musicplayer(QWidget * parent = nullptr);

    void setMusicNumber(int musicNumber);
    int musicNumber() const;

    QMediaPlayer::State getPlayState() const;

public slots:
    void startMusic();
    void stopMusic();
    void pauseMusic();

private:
    QMediaPlayer *m_musicPlayer;
    QMediaPlaylist *m_musicPlayerList;
    int m_musicNumber;
};

#endif // MUSICPLAYER_H
