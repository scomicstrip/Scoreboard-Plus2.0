#ifndef SCOREBOARDPLUS_SCOREBOARD_H
#define SCOREBOARDPLUS_SCOREBOARD_H

#include <QString>
#include <QDebug>
#include <QTimer>
#include <QObject>

extern QString time;

class ScoreboardPlus_Scoreboard
{
    Q_OBJECT
public:
    enum SportScore{
        Basketball = 2
    };

    ScoreboardPlus_Scoreboard();

    ScoreboardPlus_Scoreboard(int h_score, int a_score, int period, QString clock);

    void setHomeScore(int score);

    void setAwayScore(int score);

    void addHomeScore();

    void addAwayScore();

    void minusHomeScore();

    void minusAwayScore();

    void setPeriod(int period);

    void setClock(QString clock);

    void scoreboardReset();

    int getHomeScore();

    int getAwayScore();

    int getPeriod();

    QString getClock();

    void addHomeSetScore(int score);

    void addAwaySetScore(int score);

    void addPeriod();

    void minusPeriod();

    void setTimer(int minutes, int seconds);

    void startTimer(int msec);

    void setStopWatch(int minutes, int seconds);

    void startStopWatch(int msec);

private slots:
    void Timer();

    void StopWatch();

private:
    int Minute = 0;
    int Second = 0;
    int Period = 0;
    int Home_Score;
    int Away_Score;

    QString Clock_str = "00:00";

    QTimer *timer;

    QTimer *stopwatch;
};

#endif // SCOREBOARDPLUS_SCOREBOARD_H
