#ifndef CANNIBAL_H
#define CANNIBAL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "cannibalnrdialog.h"


class Cannibal : public QWidget
{
    Q_OBJECT

public:
    Cannibal(QWidget *parent = 0);
    ~Cannibal();


   //variables
   int SendCounter;
   int CanCounter;
   int BoatCapacity;

   int CanLeft;
   int CanRight;
   int CanBoat;

   int MissLeft;
   int MissRight;
   int MissBoat;

   bool BoatSide;


   //main layout
   QVBoxLayout *Main;

   //basic visual section for the representation of the current status
   QHBoxLayout *GameInfo;
   QVBoxLayout *GameInfoV1;
   QHBoxLayout *GameInfoV1H1;
   QHBoxLayout *GameInfoV1H2;
   QHBoxLayout *GameInfoV1H3;
   QHBoxLayout *GameInfoV1H4;

   QVBoxLayout *GameInfoV2;
   QHBoxLayout *GameInfoV2H1;
   QHBoxLayout *GameInfoV2H2;
   QHBoxLayout *GameInfoV2H3;
   QHBoxLayout *GameInfoV2H4;

   QVBoxLayout *GameInfoV3;
   QHBoxLayout *GameInfoV3H1;
   QHBoxLayout *GameInfoV3H2;
   QHBoxLayout *GameInfoV3H3;
   QHBoxLayout *GameInfoV3H4;

   //side marker section
   QHBoxLayout *SideL;

   //user interaction section
   QHBoxLayout *Action1;
   QHBoxLayout *Action2;

   //buttons and labels
   QPushButton *NewGame;

   //+/-
   QPushButton *PlusCan;
   QPushButton *MinusCan;
   QPushButton *PlusMiss;
   QPushButton *MinusMiss;

   //send button
   QPushButton *Send;

   //side marker
   QLabel *Side;
   QLabel *SideValue;

   //cannibals
   QLabel *Can1;
   QLabel *Can1Value;

   QLabel *Can2;
   QLabel *Can2Value;

   QLabel *Can3;
   QLabel *Can3Value;

   QLabel *Can4;
   QLabel *Can4Value;

   //missionaries
   QLabel *Miss1;
   QLabel *Miss1Value;

   QLabel *Miss2;
   QLabel *Miss2Value;

   QLabel *Miss3;
   QLabel *Miss3Value;

   QLabel *Miss4;
   QLabel *Miss4Value;


private slots:
   void setNewGame();
   void setBoatCP();
   void setBoatCM();
   void setBoatMP();
   void setBoatMM();
   void setSend();

private:
   CannibalNrDialog* _cannibalNrDialog;

};

#endif // CANNIBAL_H
