#include "stats.h"
#include <QtWidgets>

const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;

Stats::Stats(QWidget* parent):
    QDialog(parent)
{
    setItems();
    setConnect();
    layItems();
}

void Stats::setItems(){
    maxAns = 0;

    btHome = new QPushButton(tr("Home"));
    btExit = new QPushButton(tr("Exit"));


    QProgressBar* pbar = new QProgressBar();
    pbar->setFixedSize(100,50);

    for(int i = 0; i < 4; i++){
        pbars_Q1.push_back(new QProgressBar());
        pbars_Q1[i]->setValue(0);
        pbars_Q1[i]->setMaximum(maxAns);
        pbars_Q1[i]->setFixedSize(150,20);

        pbars_Q2.push_back(new QProgressBar());
        pbars_Q2[i]->setValue(0);
        pbars_Q2[i]->setMaximum(maxAns);
        pbars_Q2[i]->setFixedSize(150,20);

        pbars_Q3.push_back(new QProgressBar());
        pbars_Q3[i]->setValue(0);
        pbars_Q3[i]->setMaximum(maxAns);
        pbars_Q3[i]->setFixedSize(150,20);

        pbars_Q4.push_back(new QProgressBar());
        pbars_Q4[i]->setValue(0);
        pbars_Q4[i]->setMaximum(maxAns);
        pbars_Q4[i]->setFixedSize(150,20);

        pbars_Q5.push_back(new QProgressBar());
        pbars_Q5[i]->setValue(0);
        pbars_Q5[i]->setMaximum(maxAns);
        pbars_Q5[i]->setFixedSize(150,20);
    }


    //Spacers
    spBtns = new QSpacerItem(100,100);
}

void Stats::setConnect(){
    connect(btExit, SIGNAL(clicked()),
            this, SLOT(goExit()));
    connect(btHome, SIGNAL(clicked()),
            this, SLOT(goHome()));

}

void Stats::layItems(){
    QHBoxLayout* loTop = new QHBoxLayout;
    loTop->addStretch(1);
    loTop->addWidget(mkGrp_Q1());
    loTop->addStretch(1);
    loTop->addWidget(mkGrp_Q2());
    loTop->addStretch(1);
    loTop->addWidget(mkGrp_Q3());
    loTop->addStretch(1);

    QVBoxLayout* loBtn = new QVBoxLayout;
    loBtn->addWidget(btHome);
    loBtn->addWidget(btExit);

    QHBoxLayout* loBot = new QHBoxLayout;
    loBot->addStretch(1);
    loBot->addWidget(mkGrp_Q4());
    loBot->addSpacerItem(spBtns);
    loBot->addLayout(loBtn);
    loBot->addSpacerItem(spBtns);
    loBot->addWidget(mkGrp_Q5());
    loBot->addStretch(1);

    QVBoxLayout* loMain = new QVBoxLayout;
    loMain->addStretch(1);
    loMain->addLayout(loTop);
    loMain->addLayout(loBot);
    loMain->addStretch(1);

    setLayout(loMain);


    setFixedHeight(SCREEN_HEIGHT);
    setFixedWidth(SCREEN_WIDTH);
}

QGroupBox* Stats::mkGrp_Q1(){
    QGroupBox* groupBox = new QGroupBox(tr("Question 1 Responses"));

    QLabel* lbA = new QLabel(tr("A:"));
    QLabel* lbB = new QLabel(tr("B:"));
    QLabel* lbC = new QLabel(tr("C:"));
    QLabel* lbD = new QLabel(tr("D:"));

    QHBoxLayout* loA = new QHBoxLayout;
    loA->addWidget(lbA);
    loA->addWidget(pbars_Q1.at(0));

    QHBoxLayout* loB = new QHBoxLayout;
    loB->addWidget(lbB);
    loB->addWidget(pbars_Q1.at(1));

    QHBoxLayout* loC = new QHBoxLayout;
    loC->addWidget(lbC);
    loC->addWidget(pbars_Q1.at(2));

    QHBoxLayout* loD = new QHBoxLayout;
    loD->addWidget(lbD);
    loD->addWidget(pbars_Q1.at(3));

    QVBoxLayout* loMain = new QVBoxLayout;
    loMain->addStretch(1);
    loMain->addLayout(loA);
    loMain->addLayout(loB);
    loMain->addLayout(loC);
    loMain->addLayout(loD);
    loMain->addStretch(1);

    groupBox->setLayout(loMain);
    groupBox->setFixedSize(200,200);

    return groupBox;
}

QGroupBox* Stats::mkGrp_Q2(){
    QGroupBox* groupBox = new QGroupBox(tr("Question 2 Responses"));

    QLabel* lbA = new QLabel(tr("A:"));
    QLabel* lbB = new QLabel(tr("B:"));
    QLabel* lbC = new QLabel(tr("C:"));
    QLabel* lbD = new QLabel(tr("D:"));

    QHBoxLayout* loA = new QHBoxLayout;
    loA->addWidget(lbA);
    loA->addWidget(pbars_Q2.at(0));

    QHBoxLayout* loB = new QHBoxLayout;
    loB->addWidget(lbB);
    loB->addWidget(pbars_Q2.at(1));

    QHBoxLayout* loC = new QHBoxLayout;
    loC->addWidget(lbC);
    loC->addWidget(pbars_Q2.at(2));

    QHBoxLayout* loD = new QHBoxLayout;
    loD->addWidget(lbD);
    loD->addWidget(pbars_Q2.at(3));

    QVBoxLayout* loMain = new QVBoxLayout;
    loMain->addStretch(1);
    loMain->addLayout(loA);
    loMain->addLayout(loB);
    loMain->addLayout(loC);
    loMain->addLayout(loD);
    loMain->addStretch(1);

    groupBox->setLayout(loMain);
    groupBox->setFixedSize(200,200);

    return groupBox;

}

QGroupBox* Stats::mkGrp_Q3(){
    QGroupBox* groupBox = new QGroupBox(tr("Question 3 Responses"));

    QLabel* lbA = new QLabel(tr("A:"));
    QLabel* lbB = new QLabel(tr("B:"));
    QLabel* lbC = new QLabel(tr("C:"));
    QLabel* lbD = new QLabel(tr("D:"));

    QHBoxLayout* loA = new QHBoxLayout;
    loA->addWidget(lbA);
    loA->addWidget(pbars_Q3.at(0));

    QHBoxLayout* loB = new QHBoxLayout;
    loB->addWidget(lbB);
    loB->addWidget(pbars_Q3.at(1));

    QHBoxLayout* loC = new QHBoxLayout;
    loC->addWidget(lbC);
    loC->addWidget(pbars_Q3.at(2));

    QHBoxLayout* loD = new QHBoxLayout;
    loD->addWidget(lbD);
    loD->addWidget(pbars_Q3.at(3));

    QVBoxLayout* loMain = new QVBoxLayout;
    loMain->addStretch(1);
    loMain->addLayout(loA);
    loMain->addLayout(loB);
    loMain->addLayout(loC);
    loMain->addLayout(loD);
    loMain->addStretch(1);

    groupBox->setLayout(loMain);
    groupBox->setFixedSize(200,200);


    return groupBox;

}

QGroupBox* Stats::mkGrp_Q4(){
    QGroupBox* groupBox = new QGroupBox(tr("Question 4 Responses"));

    QLabel* lbA = new QLabel(tr("A:"));
    QLabel* lbB = new QLabel(tr("B:"));
    QLabel* lbC = new QLabel(tr("C:"));
    QLabel* lbD = new QLabel(tr("D:"));

    QHBoxLayout* loA = new QHBoxLayout;
    loA->addWidget(lbA);
    loA->addWidget(pbars_Q4.at(0));

    QHBoxLayout* loB = new QHBoxLayout;
    loB->addWidget(lbB);
    loB->addWidget(pbars_Q4.at(1));

    QHBoxLayout* loC = new QHBoxLayout;
    loC->addWidget(lbC);
    loC->addWidget(pbars_Q4.at(2));

    QHBoxLayout* loD = new QHBoxLayout;
    loD->addWidget(lbD);
    loD->addWidget(pbars_Q4.at(3));

    QVBoxLayout* loMain = new QVBoxLayout;
    loMain->addStretch(1);
    loMain->addLayout(loA);
    loMain->addLayout(loB);
    loMain->addLayout(loC);
    loMain->addLayout(loD);
    loMain->addStretch(1);

    groupBox->setLayout(loMain);
    groupBox->setFixedSize(200,200);


    return groupBox;

}

QGroupBox* Stats::mkGrp_Q5(){
    QGroupBox* groupBox = new QGroupBox(tr("Question 5 Responses"));

    QLabel* lbA = new QLabel(tr("A:"));
    QLabel* lbB = new QLabel(tr("B:"));
    QLabel* lbC = new QLabel(tr("C:"));
    QLabel* lbD = new QLabel(tr("D:"));

    QHBoxLayout* loA = new QHBoxLayout;
    loA->addWidget(lbA);
    loA->addWidget(pbars_Q5.at(0));

    QHBoxLayout* loB = new QHBoxLayout;
    loB->addWidget(lbB);
    loB->addWidget(pbars_Q5.at(1));

    QHBoxLayout* loC = new QHBoxLayout;
    loC->addWidget(lbC);
    loC->addWidget(pbars_Q5.at(2));

    QHBoxLayout* loD = new QHBoxLayout;
    loD->addWidget(lbD);
    loD->addWidget(pbars_Q5.at(3));

    QVBoxLayout* loMain = new QVBoxLayout;
    loMain->addStretch(1);
    loMain->addLayout(loA);
    loMain->addLayout(loB);
    loMain->addLayout(loC);
    loMain->addLayout(loD);
    loMain->addStretch(1);

    groupBox->setLayout(loMain);
    groupBox->setFixedSize(200,200);


    return groupBox;

}

void Stats::updateMax(){
    maxAns++;
    for(int i = 0; i < pbars_Q1.size(); i++){
        pbars_Q1[i]->setMaximum(maxAns);
        pbars_Q2[i]->setMaximum(maxAns);
        pbars_Q3[i]->setMaximum(maxAns);
        pbars_Q4[i]->setMaximum(maxAns);
        pbars_Q5[i]->setMaximum(maxAns);
    }
}

void Stats::goExit(){
    emit toExit();
}

void Stats::goHome(){
    emit toHome();
}
