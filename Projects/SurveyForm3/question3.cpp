#include "question3.h"
#include <QtWidgets>

const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;

Question3::Question3(QWidget *parent) :
    QDialog(parent)
{
    setItems();
    setConnect();
    layItems();
}

void Question3::setItems(){
    lbQ4 = new QLabel(tr("What enrages you more?"));
    rbq4_1 = new QRadioButton(tr("A: Traffic"));
    rbq4_2 = new QRadioButton(tr("B: Kittens"));
    rbq4_3 = new QRadioButton(tr("C: Laundry"));
    rbq4_4 = new QRadioButton(tr("D: That person who didn't do that thing you "
                                 "wanted them to do."));

    rbq4_1->setEnabled(true);

    lbQ5 = new QLabel(tr("Does this dress make me look fat?"));
    rbq5_1 = new QRadioButton(tr("A: Yes"));
    rbq5_2 = new QRadioButton(tr("B: Kind of"));
    rbq5_3 = new QRadioButton(tr("C: Nope"));
    rbq5_4 = new QRadioButton(tr("D: Uh..."));

    rbq5_1->setEnabled(true);

    btNext = new QPushButton("Complete");
    btNext->setFixedSize(100,50);
    btPrev = new QPushButton("Prev");
    btPrev->setFixedSize(100,50);

    spBtn = new QSpacerItem(100,100);
}

void Question3::setConnect(){
    connect(btNext, SIGNAL(clicked()),
            this, SLOT(goNext()));
    connect(btPrev, SIGNAL(clicked()),
            this, SLOT(goPrev()));

}

void Question3::layItems(){
    QHBoxLayout* loBtn = new QHBoxLayout;
    loBtn->addSpacerItem(spBtn);
    loBtn->addWidget(btPrev);
    loBtn->addSpacerItem(spBtn);
    loBtn->addWidget(btNext);
    loBtn->addSpacerItem(spBtn);

    QVBoxLayout *mainlayout = new QVBoxLayout;
    mainlayout->addWidget(mkGroup_Q4());
    mainlayout->addWidget(mkGroup_Q5());
    mainlayout->addLayout(loBtn);

    setLayout(mainlayout);
    setWindowTitle(tr("Survey - Question 4 & 5"));
    setFixedHeight(SCREEN_HEIGHT);
    setFixedWidth(SCREEN_WIDTH);
}

QGroupBox *Question3::mkGroup_Q4(){
    QGroupBox *groupbox = new QGroupBox(tr("Question 4"));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(lbQ4);
    vbox->addWidget(rbq4_1);
    vbox->addWidget(rbq4_2);
    vbox->addWidget(rbq4_3);
    vbox->addWidget(rbq4_4);
    vbox->addStretch(2);

    groupbox->setLayout(vbox);

    return groupbox;
}

QGroupBox *Question3::mkGroup_Q5(){
    QGroupBox *groupbox = new QGroupBox(tr("Question 5"));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(lbQ5);
    vbox->addWidget(rbq5_1);
    vbox->addWidget(rbq5_2);
    vbox->addWidget(rbq5_3);
    vbox->addWidget(rbq5_4);
    vbox->addStretch(2);

    groupbox->setLayout(vbox);

    return groupbox;
}

void Question3::goNext(){
    emit toNext();
}

void Question3::goPrev(){
    emit toPrev();
}
