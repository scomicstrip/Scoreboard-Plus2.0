#include "scoreboardplus_stylesheet.h"



QString ScoreboardPlus_Stylesheet::getPushButtonStyle()
{
   return "QPushButton{"
          "padding: 10px 10px;"
          "font-size: 15px;"
          "color: white;"
          "border: 1px solid #292929; "
          "}"
          "QPushButton:pressed{"
          "color:orange;"
          "}";
}

QString ScoreboardPlus_Stylesheet::getArrowButtonStyle()
{
   return "QPushButton{"
          "padding: 10px 10px;"
          "font-size: 25px;"
          "color: white;"
          "border: none;"
          "}"
          "QPushButton:pressed{"
          "color:orange;"
          "}";
}

QString ScoreboardPlus_Stylesheet::getClockButtonStyle()
{
   return "QPushButton{"
          "padding: 20px 10px;"
          "font-size: 28px;"
          "color: white;"
          "border: 1px solid #292929; "
          "}"
          "QPushButton:pressed{"
          "color:orange;"
          "}";
}

QString ScoreboardPlus_Stylesheet::getWindowStyle()
{
    return "QWidget { "
           "background-color: #454545; "
           "border: 1px solid black; "
           "}";
}

QString ScoreboardPlus_Stylesheet::getMenuButtonStyle()
{
   return "QPushButton{"
          "padding-left: 0px;"
          "padding-right: 0px;"
          "padding-top: 2px;"
          "padding-bottom: 2px;"
          "border: 1px solid #292929; "
          "font-size: 10px;"
          "color: white;"
          "}"

          "QPushButton:pressed{"
          "color:orange;"
          "}";
}

QString ScoreboardPlus_Stylesheet::getLabelStyle()
{
    return "QLabel{"
           "qproperty-alignment: 'AlignVCenter | AlignLeft'"
           "qproperty-wordWrap: true;";
}


