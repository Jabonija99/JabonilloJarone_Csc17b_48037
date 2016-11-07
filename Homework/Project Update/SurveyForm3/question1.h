#ifndef QUESTION1_H
#define QUESTION1_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QRadioButton;
class QPushButton;
class QGroupBox;

class Question1 : public QDialog
{
    Q_OBJECT
private:
    void setItems();
    void setConnect();
    void layItems();

    QLabel *lbName;
    QLineEdit *leName;

    QLabel *lbGender;
    QRadioButton *rbMale;
    QRadioButton *rbFemale;
    QGroupBox *mkGroup_info();

    QLabel *lbQ1;
    QRadioButton *rb1;
    QRadioButton *rb2;
    QRadioButton *rb3;
    QRadioButton *rb4;
    QGroupBox *mkGroup_Q1();

public:
    Question1(QWidget *parent = 0);
};

#endif // QUESTION1_H
