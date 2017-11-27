#include "sethotkey.h"
#include "ui_sethotkey.h"

setHotkey::setHotkey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setHotkey)
{
    ui->setupUi(this);
    //connect(ui->keySequenceEdit, SIGNAL(editingFinished()), this, SLOT(shortcut()));
    //connect(ui->keySequenceEdit_2, SIGNAL(editingFinished()), this, SLOT(shortcut()));
    //connect(ui->keySequenceEdit_3, SIGNAL(editingFinished()), this, SLOT(shortcut()));
    //connect(ui->keySequenceEdit_4, SIGNAL(editingFinished()), this, SLOT(shortcut()));
    //connect(ui->keySequenceEdit_5, SIGNAL(editingFinished()), this, SLOT(shortcut()));
    timer = new QTimer;
    timer->start(1);
    connect(timer, SIGNAL(timeout()), this, SLOT(shortcut()));
}

setHotkey::~setHotkey()
{
    delete ui;
}

void setHotkey::setKey(QKeySequence clock, QKeySequence home, QKeySequence away, QKeySequence period, QKeySequence reset)
{
    ui->keySequenceEdit->setKeySequence(clock);
    ui->keySequenceEdit_2->setKeySequence(home);
    ui->keySequenceEdit_3->setKeySequence(away);
    ui->keySequenceEdit_4->setKeySequence(period);
    ui->keySequenceEdit_5->setKeySequence(reset);
}

void setHotkey::shortcut()
{
    int value = ui->keySequenceEdit->keySequence()[0];
    QKeySequence shortcut(value);
    ui->keySequenceEdit->setKeySequence(shortcut);

    int value2 = ui->keySequenceEdit_2->keySequence()[0];
    QKeySequence shortcut2(value2);
    ui->keySequenceEdit_2->setKeySequence(shortcut2);

    int value3 = ui->keySequenceEdit_3->keySequence()[0];
    QKeySequence shortcut3(value3);
    ui->keySequenceEdit_3->setKeySequence(shortcut3);

    int value4 = ui->keySequenceEdit_4->keySequence()[0];
    QKeySequence shortcut4(value4);
    ui->keySequenceEdit_4->setKeySequence(shortcut4);

    int value5 = ui->keySequenceEdit_5->keySequence()[0];
    QKeySequence shortcut5(value5);
    ui->keySequenceEdit_5->setKeySequence(shortcut5);
}

QKeySequence setHotkey::getClockKey()
{
    return ui->keySequenceEdit->keySequence();
}

QKeySequence setHotkey::getHomeKey()
{
    return ui->keySequenceEdit_2->keySequence();
}

QKeySequence setHotkey::getAwayKey()
{
    return ui->keySequenceEdit_3->keySequence();
}

QKeySequence setHotkey::getPeriodKey()
{
    return ui->keySequenceEdit_4->keySequence();
}

QKeySequence setHotkey::getResetKey()
{
    return ui->keySequenceEdit_5->keySequence();
}


