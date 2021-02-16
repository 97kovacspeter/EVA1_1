#include "cannibalnrdialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

CannibalNrDialog::CannibalNrDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Settings");
    setModal(true);

    CannibalNr = new QLabel ("Number of Cannibals and Missionaries: ");
    _spinBox1 = new QSpinBox();
    _spinBox1->setRange(2,5); //2 to 5 range
    _spinBox1->setSingleStep(1);//which is 1 now (if its set to '2'->10, '3'->100 etc.)

    BoatCap = new QLabel ("Boat capacity: ");
    _spinBox2 = new QSpinBox();
    _spinBox2->setRange(2,5); //2 to 5 range
    _spinBox2->setSingleStep(1);

    _okButton = new QPushButton("OK");
    _okButton->setFixedSize(75,23); //fixedsize buttons
    _cancelButton = new QPushButton("Cancel");
    _cancelButton->setFixedSize(75,23);

    connect(_okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(_cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *upperLayout = new QHBoxLayout();
    QHBoxLayout *middleLayout = new QHBoxLayout();
    QHBoxLayout *lowerLayout = new QHBoxLayout();

    mainLayout->addLayout(upperLayout);
    mainLayout->addLayout(middleLayout);
    mainLayout->addLayout(lowerLayout);
    upperLayout->addWidget(CannibalNr);
    upperLayout->addWidget(_spinBox1);
    middleLayout->addWidget(BoatCap);
    middleLayout->addWidget(_spinBox2);
    lowerLayout->addWidget(_okButton);
    lowerLayout->addWidget(_cancelButton);

    setLayout(mainLayout);

}

