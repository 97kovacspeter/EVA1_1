#ifndef CANNIBALNRDIALOG_H
#define CANNIBALNRDIALOG_H

#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QDialog>

class CannibalNrDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CannibalNrDialog(QWidget *parent = 0);
    int CanNr() { return _spinBox1->value(); }
    int BoatSize() {return _spinBox2->value();}

private:
    QLabel *CannibalNr;
    QLabel *BoatCap;
    QSpinBox *_spinBox1;
    QSpinBox *_spinBox2;
    QPushButton *_okButton;
    QPushButton *_cancelButton;
};

#endif // CANNIBALNRDIALOG_H
