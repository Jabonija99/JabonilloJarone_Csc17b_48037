#ifndef QUESTION3_H
#define QUESTION3_H

#include <QDialog>

class QLabel;
class QRadioButton;
class QPushButton;
class QGroupBox;
class QSpacerItem;

class Question3 :  public QDialog
{
    Q_OBJECT
private:
    void setItems();
    void setConnect();
    void layItems();

    QLabel *lbQ4;
    QRadioButton *rbq4_1;
    QRadioButton *rbq4_2;
    QRadioButton *rbq4_3;
    QRadioButton *rbq4_4;
    QGroupBox *mkGroup_Q4();

    QLabel *lbQ5;
    QRadioButton *rbq5_1;
    QRadioButton *rbq5_2;
    QRadioButton *rbq5_3;
    QRadioButton *rbq5_4;
    QGroupBox *mkGroup_Q5();

    QPushButton* btNext;
    QPushButton* btPrev;

    QSpacerItem* spBtn;

public:
    Question3(QWidget *parent =0);

public slots:
    void goNext();
    void goPrev();

signals:
    void toNext();
    void toPrev();
};

#endif // QUESTION3_H
