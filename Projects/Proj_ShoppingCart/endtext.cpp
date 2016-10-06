#include <QtWidgets>
#include "endtext.h"

Endtext::Endtext(QWidget *parent) : QDialog(parent)
{
    lbText = new QLabel(tr("Thank you! Your order has\n"
                           "been successfully placed!"));
    btQuit = new QPushButton(tr("Exit"));
    spacer = new QSpacerItem(50,20);
    spacer2 = new QSpacerItem(300,20);

    connect(btQuit, SIGNAL(clicked()),
            this, SLOT(close()));

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
