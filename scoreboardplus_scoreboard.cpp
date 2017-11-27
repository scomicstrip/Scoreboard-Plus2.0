#include "scoreboardplus_scoreboard.h"
#define D_HScore 0;
#define D_AScore 0;
#define D_Period 1;
#define D_Clock "00:00";

/*struct Default{
    const int h_score = 0;
    const int a_score = 0;
    const int period = 1;
    const int clock = 0;
    const QString clock_str = "00:00";
};*/

/*struct Home{
    static int Score = 0;
    static int Foul = 0;
    int Bonus = 0;
    int Time_Outs_Left = 0;
};*/

/*struct Away{

};*/

ScoreboardPlus_Scoreboard::ScoreboardPlus_Scoreboard()
{
    timer = new QTimer;
    stopwatch = new QTimer;
}

ScoreboardPlus_Scoreboard::ScoreboardPlus_Scoreboard(int h_score, int a_score, int period, QString clock) :
    Home_Score(h_score),
    Away_Score(a_score),
    Period(period),
    Clock_str(clock)

{

    //if(Home::Score == -1 || Away_Score == -1 || Period == 0 || Clock_str == "-0:00")
    {
        //throw "non whole number input";
        //return;
    }
}

/*inline*/void ScoreboardPlus_Scoreboard::setHomeScore(int score)
{
    Home_Score = score;
}

/*inline*/void ScoreboardPlus_Scoreboard::setAwayScore(int score)
{
    Away_Score = score;
}

/*inline*/void ScoreboardPlus_Scoreboard::addHomeScore()
{
    Home_Score = Home_Score + 1;
}

/*inline*/void ScoreboardPlus_Scoreboard::addAwayScore()
{
    Away_Score = Away_Score + 1;
}

/*inline*/void ScoreboardPlus_Scoreboard::addHomeSetScore(int score)
{
    Home_Score = Home_Score + score;
}

/*inline*/void ScoreboardPlus_Scoreboard::addAwaySetScore(int score)
{
    Away_Score = Away_Score + score;
}

/*inline*/void ScoreboardPlus_Scoreboard::minusHomeScore()
{
    Home_Score = Home_Score - 1;
}

/*inline*/void ScoreboardPlus_Scoreboard::minusAwayScore()
{
    Away_Score = Away_Score - 1;
}

/*inline*/void ScoreboardPlus_Scoreboard::addPeriod()
{
    Period = Period + 1;
}

/*inline*/void ScoreboardPlus_Scoreboard::minusPeriod()
{
    Period = Period - 1;
}

/*inline*/void ScoreboardPlus_Scoreboard::setPeriod(int period)
{
    Period = period;
}

/*inline*/void ScoreboardPlus_Scoreboard::setClock(QString clock)
{
    Clock_str = clock;
}

void ScoreboardPlus_Scoreboard::scoreboardReset()
{
    //Default defaults;
    Home_Score = D_HScore;
    Away_Score = D_AScore;
    Period = D_Period;
    //Clock = defaults.clock;
    Clock_str = D_Clock;
}

int ScoreboardPlus_Scoreboard::getHomeScore()
{
    return Home_Score;
}

int ScoreboardPlus_Scoreboard::getAwayScore()
{
    return Away_Score;
}

/*inline*/int ScoreboardPlus_Scoreboard::getPeriod()
{
    return Period;
}

QString ScoreboardPlus_Scoreboard::getClock()
{
    return Clock_str;
}

void ScoreboardPlus_Scoreboard::setTimer(int minutes, int seconds)
{
    Minute = minutes;
    Second = seconds;
}

void ScoreboardPlus_Scoreboard::startTimer(int msec)
{
    connect(timer, SIGNAL(timeout()), this, SLOT(Timer()));
    if(msec == 0)
    timer->start(1000);
    else
    timer->start(msec);
}

void ScoreboardPlus_Scoreboard::Timer()
{
    if()
}

void ScoreboardPlus_Scoreboard::setStopWatch(int minutes, int seconds)
{
    Minute = minutes;
    Second = seconds;
}

void ScoreboardPlus_Scoreboard::startStopWatch(int msec)
{
    connect(stopwatch, SIGNAL(timeout()), this, SLOT(Timer()));
    if(msec == 0)
    stopwatch->start(1000);
    else
    stopwatch->start(msec);
}

void ScoreboardPlus_Scoreboard::StopWatch()
{

}
