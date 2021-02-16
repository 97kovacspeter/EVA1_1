#include "cannibal.h"
#include <QMessageBox>
#include <QDebug>

Cannibal::Cannibal(QWidget *parent) : QWidget(parent)
{

    //title
    setWindowTitle("Cannibals and Missionaries");

    //variables
    {
    SendCounter=0; //how many trips we counted
    CanCounter=2; //2 to 5 cannibals and missionaries
    BoatCapacity=2; //2 to 5 max capacity on the boat

    CanLeft=0;
    CanRight=2;
    CanBoat=0;

    MissLeft=0;
    MissRight=2;
    MissBoat=0;
    }
    //left(false) or right(true) side of the river
    BoatSide=true;

    //main layout
    Main=new QVBoxLayout();

    //basic visual section for the representation of the current status
   {
    GameInfo=new QHBoxLayout();
    GameInfoV1=new QVBoxLayout();
    GameInfoV1H1=new QHBoxLayout();
    GameInfoV1H2=new QHBoxLayout();
    GameInfoV1H3=new QHBoxLayout();
    GameInfoV1H4=new QHBoxLayout();

    GameInfoV2=new QVBoxLayout();
    GameInfoV2H1=new QHBoxLayout();
    GameInfoV2H2=new QHBoxLayout();
    GameInfoV2H3=new QHBoxLayout();
    GameInfoV2H4=new QHBoxLayout();

    GameInfoV3=new QVBoxLayout();
    GameInfoV3H1=new QHBoxLayout();
    GameInfoV3H2=new QHBoxLayout();
    GameInfoV3H3=new QHBoxLayout();
    GameInfoV3H4=new QHBoxLayout();

    //side marker section
    SideL=new QHBoxLayout();

    //user interaction section
    Action1=new QHBoxLayout();
    Action2=new QHBoxLayout();

    //buttons
    NewGame= new QPushButton("New Game");

    PlusCan= new QPushButton("+");
    MinusCan= new QPushButton("-");
    PlusMiss= new QPushButton("+");
    MinusMiss= new QPushButton("-");

    Send= new QPushButton("Send");
}

    //connects
    {
    _cannibalNrDialog = new CannibalNrDialog();

    connect(NewGame, SIGNAL(clicked()), _cannibalNrDialog, SLOT(exec()));


    connect(_cannibalNrDialog, SIGNAL(accepted()),this,SLOT(setNewGame()));


    connect(PlusCan, SIGNAL(clicked()), this, SLOT(setBoatCP()));
    connect(MinusCan, SIGNAL(clicked()), this, SLOT(setBoatCM()));
    connect(PlusMiss, SIGNAL(clicked()), this, SLOT(setBoatMP()));
    connect(MinusMiss, SIGNAL(clicked()), this, SLOT(setBoatMM()));

    connect(Send, SIGNAL(clicked()), this, SLOT(setSend()));

    }

    //labels
    {
    Side=new QLabel("Side");
    SideValue=new QLabel("Right");

    Can1=new QLabel("Cannibals on the left");
    Can1Value=new QLabel(QString::number(CanLeft));

    Can2=new QLabel("Cannibals on the boat");
    Can2Value=new QLabel(QString::number(CanBoat));

    Can3=new QLabel("Cannibals on the right");
    Can3Value=new QLabel(QString::number(CanRight));

    Can4=new QLabel("Cannibals to send");
    Can4Value=new QLabel("Can4V");

    Miss1=new QLabel("Missionaries on the left");
    Miss1Value=new QLabel(QString::number(MissLeft));

    Miss2=new QLabel("Missionaries on the boat");
    Miss2Value=new QLabel(QString::number(MissBoat));

    Miss3=new QLabel("Missinoaries on the right");
    Miss3Value=new QLabel(QString::number(MissRight));

    Miss4=new QLabel("Missionaries to send");
    Miss4Value=new QLabel("Miss4V");
    }

    //merging the layers
    {
    Main->addWidget(NewGame);
    Main->addLayout(GameInfo);
    Main->addLayout(SideL);
    Main->addWidget(Send);
    Main->addLayout(Action1);
    Main->addLayout(Action2);

    GameInfo->addLayout(GameInfoV1);
    GameInfo->addLayout(GameInfoV2);
    GameInfo->addLayout(GameInfoV3);

    SideL->addWidget(Side);
    SideL->addWidget(SideValue);

    Action1->addWidget(Can4);
    Action1->addWidget(PlusCan);
    Action1->addWidget(MinusCan);
    Action2->addWidget(Miss4);
    Action2->addWidget(PlusMiss);
    Action2->addWidget(MinusMiss);

    GameInfoV1->addLayout(GameInfoV1H1);
    GameInfoV1->addLayout(GameInfoV1H2);
    GameInfoV1->addLayout(GameInfoV1H3);
    GameInfoV1->addLayout(GameInfoV1H4);

    GameInfoV2->addLayout(GameInfoV2H1);
    GameInfoV2->addLayout(GameInfoV2H2);
    GameInfoV2->addLayout(GameInfoV2H3);
    GameInfoV2->addLayout(GameInfoV2H4);


    GameInfoV3->addLayout(GameInfoV3H1);
    GameInfoV3->addLayout(GameInfoV3H2);
    GameInfoV3->addLayout(GameInfoV3H3);
    GameInfoV3->addLayout(GameInfoV3H4);


    GameInfoV1H1->addWidget(Can1);
    GameInfoV1H2->addWidget(Can1Value);
    GameInfoV1H3->addWidget(Miss1);
    GameInfoV1H4->addWidget(Miss1Value);

    GameInfoV2H1->addWidget(Can2);
    GameInfoV2H2->addWidget(Can2Value);
    GameInfoV2H3->addWidget(Miss2);
    GameInfoV2H4->addWidget(Miss2Value);

    GameInfoV3H1->addWidget(Can3);
    GameInfoV3H2->addWidget(Can3Value);
    GameInfoV3H3->addWidget(Miss3);
    GameInfoV3H4->addWidget(Miss3Value);


    setLayout(Main);
    }
}

void Cannibal::setNewGame()
{
    BoatSide=true;
    SendCounter=0;
    CanRight=_cannibalNrDialog->CanNr();
    MissRight=_cannibalNrDialog->CanNr();
    BoatCapacity=_cannibalNrDialog->BoatSize();


    SideValue->setText("Right");
    Can3Value->setText(QString::number(CanRight));
    Miss3Value->setText(QString::number(MissRight));

    CanLeft=0;
    CanBoat=0;
    MissLeft=0;
    MissBoat=0;
    Can2Value->setText(QString::number(0));
    Can1Value->setText(QString::number(0));
    Miss1Value->setText(QString::number(0));
    Miss2Value->setText(QString::number(0));


}

void Cannibal::setBoatCP()
{
    if(CanBoat+MissBoat<BoatCapacity)
    {
        if(CanRight>0 && BoatSide==true)
        {
            CanRight--;
            CanBoat++;
            Can3Value->setText(QString::number(CanRight));
            Can2Value->setText(QString::number(CanBoat));

        }
        else if(CanLeft>0 && BoatSide==false)
        {
            CanLeft--;
            CanBoat++;
            Can1Value->setText(QString::number(CanLeft));
            Can2Value->setText(QString::number(CanBoat));
        }
   }
}

void Cannibal::setBoatCM()
{
    if(CanBoat>0 && BoatSide==true)
    {
        CanRight++;
        CanBoat--;
        Can3Value->setText(QString::number(CanRight));
        Can2Value->setText(QString::number(CanBoat));

    }
    else if(CanBoat>0 && BoatSide==false)
    {
        CanLeft++;
        CanBoat--;
        Can1Value->setText(QString::number(CanLeft));
        Can2Value->setText(QString::number(CanBoat));
    }
}

void Cannibal::setBoatMP()
{
    if(CanBoat+MissBoat<BoatCapacity)
    {
    if(MissRight>0 && BoatSide==true)
    {
        MissRight--;
        MissBoat++;
        Miss3Value->setText(QString::number(MissRight));
        Miss2Value->setText(QString::number(MissBoat));

    }
    else if(MissLeft>0 && BoatSide==false)
    {
        MissLeft--;
        MissBoat++;
        Miss1Value->setText(QString::number(MissLeft));
        Miss2Value->setText(QString::number(MissBoat));
    }
    }
}

void Cannibal::setBoatMM()
{
    if(MissBoat>0 && BoatSide==true)
    {
        MissRight++;
        MissBoat--;
        Miss3Value->setText(QString::number(MissRight));
        Miss2Value->setText(QString::number(MissBoat));

    }
    else if(MissBoat>0 && BoatSide==false)
    {
        MissLeft++;
        MissBoat--;
        Miss1Value->setText(QString::number(MissLeft));
        Miss2Value->setText(QString::number(MissBoat));
    }
}

void Cannibal::setSend()
{
     if((CanBoat+MissBoat)>0)
     {
        if(BoatSide)
        {
              if((CanBoat<=MissBoat || MissBoat==0) && (CanRight<=MissRight || MissRight==0) && ((CanLeft+CanBoat)<=(MissLeft+MissBoat) || (MissLeft+MissBoat)==0 ))
              {
                  BoatSide=false;
                  CanLeft+=CanBoat;
                  CanBoat=0;
                  MissLeft+=MissBoat;
                  MissBoat=0;

                  Miss1Value->setText(QString::number(MissLeft));
                  Can1Value->setText(QString::number(CanLeft));
                  Can2Value->setText(QString::number(0));
                  Miss2Value->setText(QString::number(0));
                  SideValue->setText("Left");

                  SendCounter++;
              }
        }
        else
        {
            if((CanBoat<=MissBoat || MissBoat==0) && (CanLeft<=MissLeft || MissLeft==0) && ((CanRight+CanBoat)<=(MissRight+MissBoat) || (MissRight+MissBoat)==0))
            {
                BoatSide=true;
                CanRight+=CanBoat;
                CanBoat=0;
                MissRight+=MissBoat;
                MissBoat=0;

                Miss3Value->setText(QString::number(MissRight));
                Can3Value->setText(QString::number(CanRight));
                Can2Value->setText(QString::number(0));
                Miss2Value->setText(QString::number(0));
                SideValue->setText("Right");

                SendCounter++;
            }
        }
     }

     if(CanRight==0 && MissRight==0)
     {
         QMessageBox::StandardButton reply;
         reply=QMessageBox::information(this,"Counter","Times boat sent: "+QString::number(SendCounter));
         if(reply==QMessageBox::Ok)
         {
             Cannibal::setNewGame();
         }

     }
}


Cannibal::~Cannibal()
{
    delete _cannibalNrDialog;
}
