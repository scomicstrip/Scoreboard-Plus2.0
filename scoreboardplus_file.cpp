#include "scoreboardplus_file.h"

struct Default{
    QString directory = "C:\\";
};

ScoreboardPlus_File::ScoreboardPlus_File()
{

}

bool ScoreboardPlus_File::outToFile(QString directory, const ScoreboardPlus_Scoreboard *score)
{
    Default defaults;
    if(directory == "")
    return 0;
    //directory = defaults.directory;

    QFile file(directory);
    return 1;
}

inline void ScoreboardPlus_File::setDirectory(const QString directory)
{
    this->directory = directory;
}

inline void ScoreboardPlus_File::setScoreboard(ScoreboardPlus_Scoreboard *scoreboard)
{
    this->scoreboard = scoreboard;
}

