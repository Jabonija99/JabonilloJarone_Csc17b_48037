#include "question1.h"
#include <QtWidgets>

const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;


Question1::Question1(QWidget *parent)
    :QDialog(parent)
{
    setItems();
    setConnect();
    layItems();
}

void Question1::setItems(){
    lbName = new QLabel(tr("Enter Name:"));
    leName = new QLineEdit;

    lbGender = new QLabel(tr("Gender:"));
    rbMale = new QRadioButton(tr("Male"));
    rbFemale = new QRadioButton(tr("Female"));
    rbFemale->setChecked(true);

    lbQ1 = new QLabel(tr("What is your favorite color?"));
    rb1 = new QRadioButton(tr("A: Purple"));
    rb2 = new QRadioButton(tr("B: Orange"));
    rb3 = new QRadioButton(tr("C: Green"));
    rb4 = new QRadioButton(tr("D: Red!...No wait. Blue!"));

    rb1->setChecked(true);

    btNext = new QPushButton("Next");
    btNext->setFixedSize(100,50);

    spBtn = new QSpacerItem(100,100);
}

void Question1::setConnect(){
    connect(btNext, SIGNAL(clicked()),
            this, SLOT(goNext()));


}

void Question1::layItems(){
    QHBoxLayout* loBtn = new QHBoxLayout;
    loBtn->addSpacerItem(spBtn);
    loBtn->addWidget(btNext);
    loBtn->addSpacerItem(spBtn);

    QVBoxLayout *mainlayout = new QVBoxLayout;
    mainlayout->addWidget(mkGroup_info());
    mainlayout->addWidget(mkGroup_Q1());
    mainlayout->addLayout(loBtn);

    setLayout(mainlayout);
    setWindowTitle(tr("Survey - Question 1"));
    setFixedHeight(SCREEN_HEIGHT);
    setFixedWidth(SCREEN_WIDTH);
}

QGroupBox *Question1::mkGroup_info(){
    QGroupBox *groupBox = new QGroupBox(tr("General Info"));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(lbName);
    vbox->addWidget(leName);
    vbox->addWidget(lbGender);
    vbox->addWidget(rbFemale);
    vbox->addWidget(rbMale);
    vbox->addStretch(2);

    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *Question1::mkGroup_Q1(){
    QGroupBox *groupBox = new QGroupBox(tr("Question1"));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(lbQ1);
    vbox->addWidget(rb1);
    vbox->addWidget(rb2);
    vbox->addWidget(rb3);
    vbox->addWidget(rb4);
    vbox->addStretch(2);

    groupBox->setLayout(vbox);

    return groupBox;
}

void Question1::goNext(){
    emit toNext();
}
