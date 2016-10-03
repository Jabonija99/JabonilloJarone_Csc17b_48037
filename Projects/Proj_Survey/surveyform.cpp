#include <QtWidgets>
#include "surveyform.h"

SurveyForm::SurveyForm(QWidget *parent):QWidget(parent){
    lbName = new QLabel(tr("Name"));
    leName = new QLineEdit();

    lbQ1 = new QLabel(tr(""));
    leQ1 = new QLineEdit();

    lbQ2 = new QLabel(tr(""));
    leQ2 = new QLineEdit();

    lbQ3 = new QLabel(tr(""));
    leQ3 = new QLineEdit();

    lbQ4 = new QLabel(tr(""));
    leQ4 = new QLineEdit();

    submit = new QPushButton(tr("Submit"));
    submit->setDefault(true);
    submit->setEnabled(false);

    cancel = new QPushButton(tr("Cancel"));

    connect(leName, SIGNAL(textChanged(const QString&)),
            submit, SLOT(setEnabled));
    connect(submit, SIGNAL(clicked()),
            this, SLOT(saveForm()));
    connect(cancel, SIGNAL(clicked()),
            this, SLOT(close());

    QVBoxLayout * leftLayout = new QVBoxLayout;
    leftLayout->addWidget(lbName);
    leftLayout->addWidget(lbQ1);
    leftLayout->addWidget(lbQ2);
    leftLayout->addWidget(lbQ3);
    leftLayout->addWidget(lbQ4);

    QVBoxLayout * rightLayout = new QVBoxLayout;
    rightLayout->addWidget(leName);
    rightLayout->addWidget(leQ1);
    rightLayout->addWidget(leQ2);
    rightLayout->addWidget(leQ3);
    rightLayout->addWidget(leQ4);


    QHBoxLayout * topLayout = new QHBoxLayout;
    topLayout->addLayout(leftLayout);
    topLayout->addLayout(rightLayout);

    QVBoxLayout * botLayout = new QVBoxLayout;
    botLayout->addWidget(submit);
    botLayout->addWidget(cancel);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(botLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Survey Form"));
    setFixedHeight(600);
    setFixedWidth(800);)
}


void SurveyForm::saveForm(){
    //Saves file to text
}


void SurveyForm::enableSubmit(const QString& text){
    QString msg =
}

