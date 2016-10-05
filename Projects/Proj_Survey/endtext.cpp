#include <QtWidgets>
#include "endtext.h"

Endtext::Endtext(QWidget *parent) : QDialog(parent)
{
    lbText = new QLabel(tr("Thank you!"));
    btQuit = new QPushButton(tr("Complete Survey"));
    spacer = new QSpacerItem(50,20);
    spacer2 = new QSpacerItem(300,20);

    exit();

    QHBoxLayout *botLayout = new QHBoxLayout;
    botLayout->addSpacerItem(spacer);
    botLayout->addWidget(btQuit);
    botLayout->addSpacerItem(spacer);

    QHBoxLayout *textLayout = new QHBoxLayout;
    textLayout->addSpacerItem(spacer2);
    textLayout->addWidget(lbText);
    textLayout->addSpacerItem(spacer2);

    QVBoxLayout *topLayout = new QVBoxLayout;
    topLayout->addLayout(textLayout);
    topLayout->addLayout(botLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addSpacerItem(spacer);
    mainLayout->addLayout(topLayout);
    mainLayout->addSpacerItem(spacer);

    setLayout(mainLayout);
    setFixedHeight(200);
    setFixedWidth(500);
}

void Endtext::exit(){
    connect(btQuit, SIGNAL(clicked()),
            this, SLOT(close()));
    emit closed();
}
