#include "mainwindow.h"
#include "ui_mainwindow.h"

QString time = "00:00";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setMainWindowStyleSheet();
    this->setStyleSheet(ScoreboardPlus_Stylesheet::getWindowStyle());
    //this->setWindowFlags(Qt::FramelessWindowHint);
    mainscoreboard = new ScoreboardPlus_Scoreboard(0, 0, 1, "00:00");
    eff = new QGraphicsOpacityEffect(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMainWindowStyleSheet()
{
    //Setting all buttons
    /*ui->Minimize_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getMenuButtonStyle());
    ui->Minimize_PushButton->setText("—");
    ui->Maximize_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getMenuButtonStyle());
    ui->Maximize_PushButton->setText("□");
    ui->Close_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getMenuButtonStyle());
    ui->Close_PushButton->setText("X");*/
    //ui->Minimize_PushButton->setVisible(false);
    //ui->Maximize_PushButton->setVisible(false);
    //ui->Close_PushButton->setVisible(false);

    ui->UpdateTeam_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getPushButtonStyle());
    ui->UpdateTeam_PushButton->setText("Update Team");
    ui->ResetClock_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getPushButtonStyle());
    ui->ResetClock_PushButton->setText("Reset Clock");
    ui->Clock_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getClockButtonStyle());
    ui->Clock_PushButton->setText("Start");
    ui->ResetScore_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getPushButtonStyle());
    ui->ResetScore_PushButton->setText("Reset Score");
    ui->Swap_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getPushButtonStyle());
    ui->Swap_PushButton->setText("Swap Team");

    ui->HomeScore2Up_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getArrowButtonStyle());
    ui->HomeScore2Up_PushButton->setText("+2");
    ui->HomeScoreUp_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getArrowButtonStyle());
    ui->HomeScoreUp_PushButton->setText("\u25B3");
    ui->HomeScoreDown_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getArrowButtonStyle());
    ui->HomeScoreDown_PushButton->setText("\u25BD");

    ui->AwayScore2Up_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getArrowButtonStyle());
    ui->AwayScore2Up_PushButton->setText("+2");
    ui->AwayScoreUp_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getArrowButtonStyle());
    ui->AwayScoreUp_PushButton->setText("\u25B3");
    ui->AwayScoreDown_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getArrowButtonStyle());
    ui->AwayScoreDown_PushButton->setText("\u25BD");

    ui->PeriodUp_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getArrowButtonStyle());
    ui->PeriodUp_PushButton->setText("\u25B3");
    ui->PeriodDown_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getArrowButtonStyle());
    ui->PeriodDown_PushButton->setText("\u25BD");

    ui->SetHotkey_PushButton->setStyleSheet(ScoreboardPlus_Stylesheet::getMenuButtonStyle());

    //Setting labels
    ui->HomeScore_Label->setAlignment(Qt::AlignCenter);
    ui->HomeScore_Label->setText("0");
    ui->AwayScore_Label->setAlignment(Qt::AlignCenter);
    ui->AwayScore_Label->setText("0");
    ui->Period_Label->setAlignment(Qt::AlignCenter);
    ui->Period_Label->setText("1");
    ui->Clock_Label->setAlignment(Qt::AlignCenter);
    ui->Clock_Label->setText("00:00");
    ui->Colon_Label->setAlignment(Qt::AlignCenter);
    ui->Colon2_Label->setAlignment(Qt::AlignCenter);
}

/*void MainWindow::on_Close_PushButton_clicked()
{
    this->close();
    delete ui;
}*/

void MainWindow::on_HomeScoreUp_PushButton_clicked()
{
    mainscoreboard->addHomeScore();
    Home_Score_Fade_Out();
}

void MainWindow::on_HomeScore2Up_PushButton_clicked()
{
    mainscoreboard->addHomeSetScore(ScoreboardPlus_Scoreboard::Basketball);
    Home_Score_Fade_Out();
}

void MainWindow::on_HomeScoreDown_PushButton_clicked()
{
    mainscoreboard->minusHomeScore();
    Home_Score_Fade_Out();
}

void MainWindow::Home_Score_Fade_Out()
{
    ui->HomeScore_Label->setGraphicsEffect(eff);
    animation = new QPropertyAnimation(eff, "opacity");
    animation->setDuration(300);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::InBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
    connect(animation, SIGNAL(finished()), this, SLOT(Home_Score_Fade_In()));
    //delete eff;
    //delete animation;
}

void MainWindow::Home_Score_Fade_In()
{
    ui->HomeScore_Label->setGraphicsEffect(eff);
    animation = new QPropertyAnimation(eff, "opacity");
    animation->setDuration(300);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setEasingCurve(QEasingCurve::OutBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
    ui->HomeScore_Label->setText(QString::number(mainscoreboard->getHomeScore()));
    //delete eff;
    //delete animation;
}

void MainWindow::on_AwayScoreUp_PushButton_clicked()
{
    mainscoreboard->addAwayScore();
    Away_Score_Fade_Out();
}

void MainWindow::on_AwayScore2Up_PushButton_clicked()
{
    mainscoreboard->addAwaySetScore(2);
    Away_Score_Fade_Out();
}

void MainWindow::on_AwayScoreDown_PushButton_clicked()
{
    mainscoreboard->minusAwayScore();
    Away_Score_Fade_Out();
}

void MainWindow::Away_Score_Fade_Out()
{
    ui->AwayScore_Label->setGraphicsEffect(eff);
    animation = new QPropertyAnimation(eff, "opacity");
    animation->setDuration(300);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::InBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
    connect(animation, SIGNAL(finished()), this, SLOT(Away_Score_Fade_In()));
    //delete eff;
    //delete animation;
}

void MainWindow::Away_Score_Fade_In()
{
    ui->AwayScore_Label->setGraphicsEffect(eff);
    animation = new QPropertyAnimation(eff, "opacity");
    animation->setDuration(300);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setEasingCurve(QEasingCurve::OutBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
    ui->AwayScore_Label->setText(QString::number(mainscoreboard->getAwayScore()));
    //delete eff;
    //delete animation;
}

void MainWindow::on_PeriodUp_PushButton_clicked()
{
    mainscoreboard->addPeriod();
    Period_Fade_Out();
}

void MainWindow::on_PeriodDown_PushButton_clicked()
{
    mainscoreboard->minusPeriod();
    Period_Fade_Out();
}

void MainWindow::Period_Fade_Out()
{
    ui->Period_Label->setGraphicsEffect(eff);
    animation = new QPropertyAnimation(eff, "opacity");
    animation->setDuration(300);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::InBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
    connect(animation, SIGNAL(finished()), this, SLOT(Period_Fade_In()));
}

void MainWindow::Period_Fade_In()
{
    ui->Period_Label->setGraphicsEffect(eff);
    animation = new QPropertyAnimation(eff, "opacity");
    animation->setDuration(300);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setEasingCurve(QEasingCurve::OutBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
    ui->Period_Label->setText(QString::number(mainscoreboard->getPeriod()));
}


void MainWindow::on_Clock_PushButton_clicked()
{
    if(isClock == false)
    {
        clockButton = "Stop";
        Clock_Button_Fade_Out();
        isClock = true;
    }else{
        clockButton = "Start";
        Clock_Button_Fade_Out();
        isClock = false;
    }
}

void MainWindow::on_ResetClock_PushButton_clicked()
{

}

void MainWindow::Clock_Button_Fade_Out()
{
    ui->Clock_PushButton->setGraphicsEffect(eff);
    animation = new QPropertyAnimation(eff, "opacity");
    animation->setDuration(300);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::InBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
    connect(animation, SIGNAL(finished()), this, SLOT(Clock_Button_Fade_In()));
}

void MainWindow::Clock_Button_Fade_In()
{
    ui->Clock_PushButton->setGraphicsEffect(eff);
    animation = new QPropertyAnimation(eff, "opacity");
    animation->setDuration(300);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setEasingCurve(QEasingCurve::OutBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
    ui->Clock_PushButton->setText(clockButton);
}

void MainWindow::on_SetHotkey_PushButton_clicked()
{

    sethotkey = new setHotkey;

    sethotkey->setKey(clockKey, homeKey, awayKey, periodKey, resetKey);

    sethotkey->exec();

    clockKey = sethotkey->getClockKey();
    homeKey = sethotkey->getHomeKey();
    awayKey = sethotkey->getAwayKey();
    periodKey = sethotkey->getPeriodKey();
    resetKey = sethotkey->getResetKey();

    hotkey = new QHotkey;
    hotkey->setShortcut(clockKey, true);
    connect(hotkey, SIGNAL(activated()), this, SLOT(on_Clock_PushButton_clicked()));

    hotkey = new QHotkey;
    hotkey->setShortcut(homeKey, true);
    connect(hotkey, SIGNAL(activated()), this, SLOT(on_HomeScoreUp_PushButton_clicked()));

    hotkey = new QHotkey;
    hotkey->setShortcut(awayKey, true);
    connect(hotkey, SIGNAL(activated()), this, SLOT(on_AwayScoreUp_PushButton_clicked()));

    hotkey = new QHotkey;
    hotkey->setShortcut(periodKey, true);
    connect(hotkey, SIGNAL(activated()), this, SLOT(on_PeriodUp_PushButton_clicked()));

    hotkey = new QHotkey;
    hotkey->setShortcut(resetKey, true);
    connect(hotkey, SIGNAL(activated()), this, SLOT(on_ResetClock_PushButton_clicked()));

    delete sethotkey;
}
