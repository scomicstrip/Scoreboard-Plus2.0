#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QHotkey>
#include "scoreboardplus_scoreboard.h"
#include "scoreboardplus_file.h"
#include "scoreboardplus_audio.h"
#include "scoreboardplus_remote.h"
#include "scoreboardplus_update.h"
#include "scoreboardplus_stylesheet.h"
#include "sethotkey.h"

class ScoreboardPlus_Scoreboard;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void Home_Score_Fade_Out();
    void Home_Score_Fade_In();
    void Away_Score_Fade_Out();
    void Away_Score_Fade_In();
    void Period_Fade_Out();
    void Period_Fade_In();
    void Clock_Button_Fade_Out();
    void Clock_Button_Fade_In();
protected:

    void setMainWindowStyleSheet();

private slots:

    void on_HomeScoreUp_PushButton_clicked();

    void on_HomeScore2Up_PushButton_clicked();

    void on_HomeScoreDown_PushButton_clicked();

    void on_AwayScoreUp_PushButton_clicked();

    void on_AwayScore2Up_PushButton_clicked();

    void on_AwayScoreDown_PushButton_clicked();

    void on_PeriodUp_PushButton_clicked();

    void on_PeriodDown_PushButton_clicked();

    void on_Clock_PushButton_clicked();

    void on_SetHotkey_PushButton_clicked();

    void on_ResetClock_PushButton_clicked();

private:
    Ui::MainWindow *ui;
    ScoreboardPlus_Scoreboard *mainscoreboard;
    QGraphicsOpacityEffect *eff;
    QPropertyAnimation *animation;
    bool isClock = false;
    QString clockButton = "Start";
    setHotkey *sethotkey;
    QHotkey *hotkey;

    QKeySequence clockKey;
    QKeySequence homeKey;
    QKeySequence awayKey;
    QKeySequence periodKey;
    QKeySequence resetKey;
};

#endif // MAINWINDOW_H
