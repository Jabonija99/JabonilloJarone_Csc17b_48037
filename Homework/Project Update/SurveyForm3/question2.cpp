#include "question2.h"
#include <QtWidgets>

const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;

Question2::Question2(QWidget *parent) :
    QDialog(parent)
{
    setItems();
    setConnect();
    layItems();
}

void Question2::setItems(){
    lbQ2 = new QLabel(tr("What's your favorite food out of the selection?"));
    rbq2_1 = new QRadioButton(tr("Pizza"));
    rbq2_2 = new QRadioButton(tr("Chicken"));
    rbq2_3 = new QRadioButton(tr("Zombies"));
    rbq2_4 = new QRadioButton(tr("Dog"));

    rbq2_1->setEnabled(true);

    lbQ3 = new QLabel(tr("If you can live in any of the listed places,"
                      "where would you call home?"));
    rbq3_1 = new QRadioButton(tr("Canada"));
    rbq3_2 = new QRadioButton(tr("Caribbeans"));
    rbq3_3 = new QRadioButton(tr("America"));
    rbq3_4 = new QRadioButton(tr("Space"));

    rbq3_1->setEnabled(true);
}

void Question2::setConnect(){

}

void Question2::layItems(){
    QVBoxLayout *mainlayout = new QVBoxLayout;
    mainlayout->addWidget(mkGroup_Q2());
    mainlayout->addWidget(mkGroup_Q3());

    setLayout(mainlayout);
    setWindowTitle(tr("Survey - Question 2 & 3"));
    setFixedHeight(SCREEN_HEIGHT);
    setFixedWidth(SCREEN_WIDTH);
}

QGroupBox *Question2::mkGroup_Q2(){
    QGroupBox *groupbox = new QGroupBox(tr("Question 2"));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(lbQ2);
    vbox->addWidget(rbq2_1);
    vbox->addWidget(rbq2_2);
    vbox->addWidget(rbq2_3);
    vbox->addWidget(rbq2_4);
    vbox->addStretch(2);

    groupbox->setLayout(vbox);

    return groupbox;
}

QGroupBox *Question2::mkGroup_Q3(){
    QGroupBox *groupbox = new QGroupBox(tr("Question 3"));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(lbQ3);
    vbox->addWidget(rbq3_1);
    vbox->addWidget(rbq3_2);
    vbox->addWidget(rbq3_3);
    vbox->addWidget(rbq3_4);
    vbox->addStretch(2);

    groupbox->setLayout(vbox);

    return groupbox;
}
