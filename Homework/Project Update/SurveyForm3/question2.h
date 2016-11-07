#ifndef QUESTION2_H
#define QUESTION2_H

#include <QDialog>

class QLabel;
class QRadioButton;
class QPushButton;
class QGroupBox;

class Question2 : public QDialog
{
    Q_OBJECT
private:
    void setItems();
    void setConnect();
    void layItems();

    QLabel *lbQ2;
    QRadioButton *rbq2_1;
    QRadioButton *rbq2_2;
    QRadioButton *rbq2_3;
    QRadioButton *rbq2_4;
    QGroupBox *mkGroup_Q2();

    QLabel *lbQ3;
    QRadioButton *rbq3_1;
    QRadioButton *rbq3_2;
    QRadioButton *rbq3_3;
    QRadioButton *rbq3_4;
    QGroupBox *mkGroup_Q3();

public:
    Question2(QWidget *parent =0);
};

#endif // QUESTION2_H
