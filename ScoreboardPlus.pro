#-------------------------------------------------
#
# Project created by QtCreator 2016-11-22T18:47:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ScoreboardPlus
TEMPLATE = app

include(C:/Users/Ian/Google Drive/Library/QHotkey-1.1.0/qhotkey.pri)

SOURCES += main.cpp\
        mainwindow.cpp \
    scoreboardplus_audio.cpp \
    scoreboardplus_file.cpp \
    scoreboardplus_remote.cpp \
    scoreboardplus_scoreboard.cpp \
    scoreboardplus_update.cpp \
    scoreboardplus_stylesheet.cpp \
    sethotkey.cpp

HEADERS  += mainwindow.h \
    scoreboardplus_audio.h \
    scoreboardplus_file.h \
    scoreboardplus_remote.h \
    scoreboardplus_scoreboard.h \
    scoreboardplus_update.h \
    scoreboardplus_stylesheet.h \
    sethotkey.h

FORMS    += mainwindow.ui \
    sethotkey.ui

win32: LIBS += -L$$PWD/../../Library/bass24/c/ -lbass

INCLUDEPATH += $$PWD/../../Library/bass24/c
DEPENDPATH += $$PWD/../../Library/bass24/c


