#ifndef SCOREBOARDPLUS_FILE_H
#define SCOREBOARDPLUS_FILE_H

#include <QString>
#include <QFile>
#include "scoreboardplus_scoreboard.h"

class ScoreboardPlus_File
{
public:
    ScoreboardPlus_File();

    static bool outToFile(const QString directory, const ScoreboardPlus_Scoreboard *scoreboard);

    void setDirectory(const QString directory);

    void setScoreboard(ScoreboardPlus_Scoreboard *scoreboard);

private:
     ScoreboardPlus_Scoreboard *scoreboard;
     QString directory;

};

#endif // SCOREBOARDPLUS_FILE_H
