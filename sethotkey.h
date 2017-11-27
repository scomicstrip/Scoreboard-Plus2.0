#ifndef SETHOTKEY_H
#define SETHOTKEY_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class setHotkey;
}

class setHotkey : public QDialog
{
    Q_OBJECT

public:
    explicit setHotkey(QWidget *parent = 0);

    ~setHotkey();

    void setKey(QKeySequence clock, QKeySequence home, QKeySequence away, QKeySequence period, QKeySequence reset);

    QKeySequence getClockKey();

    QKeySequence getHomeKey();

    QKeySequence getAwayKey();

    QKeySequence getPeriodKey();

    QKeySequence getResetKey();

public slots:
    void shortcut();

private:
    Ui::setHotkey *ui;
    QTimer *timer;
};

#endif // SETHOTKEY_H
