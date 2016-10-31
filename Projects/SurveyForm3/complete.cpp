#include "complete.h"
#include <QtWidgets>

const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;

Complete::Complete(QWidget *parent):
    QDialog(parent)
{
    setItems();
    setConnect();
    layItems();
}

void Complete::setItems(){
    lbComplete = new QLabel("Survey Complete!");
    btExit = new QPushButton("Exit");
    btStats = new QPushButton("Stats");

    spLb = new QSpacerItem(100, 100);
    spLb2 = new QSpacerItem(140,50);
    spVert = new QSpacerItem(SCREEN_WIDTH, 150);
    spHorz = new QSpacerItem(200, SCREEN_HEIGHT);
}

void Complete::setConnect(){
    connect(btExit, SIGNAL(clicked()),
            this, SLOT(close()));
}

void Complete::layItems(){
    QHBoxLayout *loLabel = new QHBoxLayout;
    loLabel->addSpacerItem(spLb2);
    loLabel->addWidget(lbComplete);
    loLabel->addSpacerItem(spLb2);

    QVBoxLayout *loItems = new QVBoxLayout;
    loItems->addLayout(loLabel);
    loItems->addSpacerItem(spLb);
    loItems->addWidget(btStats);
    loItems->addWidget(btExit);

    QHBoxLayout *loCenter = new QHBoxLayout;
    loCenter->addSpacerItem(spHorz);
    loCenter->addLayout(loItems);
    loCenter->addSpacerItem(spHorz);

    QVBoxLayout *mainlayout = new QVBoxLayout;
    mainlayout->addSpacerItem(spVert);
    mainlayout->addLayout(loCenter);
    mainlayout->addSpacerItem(spVert);

    setLayout(mainlayout);
    setWindowTitle(tr("Survey - Complete"));
    setFixedHeight(SCREEN_HEIGHT);
    setFixedWidth(SCREEN_WIDTH);
}
