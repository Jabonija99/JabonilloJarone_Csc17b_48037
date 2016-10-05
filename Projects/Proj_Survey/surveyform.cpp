#include <QtWidgets>
#include "surveyform.h"

SurveyForm::SurveyForm(QWidget *parent):QDialog (parent){
    setItems();
    setConnects();
    layItems();
}

void SurveyForm::setItems(){
    //General Information
    lbName = new QLabel(tr("Name"));
    leName = new QLineEdit;
    rbM = new QRadioButton(tr("Male"));
    rbF = new QRadioButton(tr("Female"));

    //Question 1
    lbQ1 = new QLabel(tr("Do you like surveys?"));
    rbQ1_1 = new QRadioButton(tr("Yes"));
    rbQ1_2 = new QRadioButton(tr("No"));
    rbQ1_3 = new QRadioButton(tr("Other"));
    leQ1 = new QLineEdit;
    leQ1->setEnabled(false);

    //Question 2
    lbQ2 = new QLabel(tr("Do you like this survey?"));
    rbQ2_1 = new QRadioButton(tr("Yes"));
    rbQ2_2 = new QRadioButton(tr("No"));
    rbQ2_3 = new QRadioButton(tr("Other"));
    leQ2 = new QLineEdit;
    leQ2->setEnabled(false);

    //Question 3
    lbQ3 = new QLabel(tr("How would you rate this survey?"));
    rbQ3_1 = new QRadioButton(tr("Yes"));
    rbQ3_2 = new QRadioButton(tr("No"));
    rbQ3_3 = new QRadioButton(tr("Other"));
    leQ3 = new QLineEdit;
    leQ3->setEnabled(false);

    //Question 4
    lbQ4 = new QLabel(tr("Would you ever take this survey again?"));
    rbQ4_1 = new QRadioButton(tr("Yes"));
    rbQ4_2 = new QRadioButton(tr("No"));
    rbQ4_3 = new QRadioButton(tr("Other"));
    leQ4 = new QLineEdit;
    leQ4->setEnabled(false);

    //Buttons
    submit = new QPushButton(tr("Submit"));
    submit->setDefault(true);
    submit->setEnabled(false);

    cancel = new QPushButton(tr("Cancel"));

    //Spacers
    spQ = new QSpacerItem(100,300);
    spBtn = new QSpacerItem(300,50);

    //End Text Box
    txtTY = new Endtext;

}


void SurveyForm::setConnects(){
    //Connections
    connect(leName, SIGNAL(textChanged(const QString&)),
            this, SLOT(enableSubmit(const QString&)));

    connect(rbQ1_3, SIGNAL(toggled()),
            this, SLOT(enableLEQ1()));


    connect(submit, SIGNAL(clicked()),
            this, SLOT(txtConfirm()));
    connect(cancel, SIGNAL(clicked()),
            this, SLOT(close()));

}

void SurveyForm::layItems(){
    //Layouts
    QHBoxLayout *genderLayout = new QHBoxLayout;
    genderLayout->addWidget(rbM);
    genderLayout->addWidget(rbF);

    //Name Layout
    QVBoxLayout *nameLayout = new QVBoxLayout;
    nameLayout->addWidget(lbName);
    nameLayout->addWidget(leName);
    nameLayout->addLayout(genderLayout);

    //Question 1 Layout
    QVBoxLayout *q1Layout = new QVBoxLayout;
    q1Layout->addWidget(lbQ1);
    q1Layout->addWidget(rbQ1_1);
    q1Layout->addWidget(rbQ1_2);
    q1Layout->addWidget(rbQ1_3);
    q1Layout->addWidget(leQ1);

    //Question 2 Layout
    QVBoxLayout *q2Layout = new QVBoxLayout;
    q2Layout->addWidget(lbQ2);
    q2Layout->addWidget(rbQ2_1);
    q2Layout->addWidget(rbQ2_2);
    q2Layout->addWidget(rbQ2_3);
    q2Layout->addWidget(leQ2);

    //Question 3 Layout
    QVBoxLayout *q3Layout = new QVBoxLayout;
    q3Layout->addWidget(lbQ3);
    q3Layout->addWidget(rbQ3_1);
    q3Layout->addWidget(rbQ3_2);
    q3Layout->addWidget(rbQ3_3);
    q3Layout->addWidget(leQ3);

    //Question 4 Layout
    QVBoxLayout *q4Layout = new QVBoxLayout;
    q4Layout->addWidget(lbQ4);
    q4Layout->addWidget(rbQ4_1);
    q4Layout->addWidget(rbQ4_2);
    q4Layout->addWidget(rbQ4_3);
    q4Layout->addWidget(leQ4);

    //Question Layout
    QVBoxLayout *qLayout = new QVBoxLayout;
    qLayout->addLayout(nameLayout);
    qLayout->addLayout(q1Layout);
    qLayout->addLayout(q2Layout);
    qLayout->addLayout(q3Layout);
    qLayout->addLayout(q4Layout);

    //Top layout
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addSpacerItem(spQ);
    topLayout->addLayout(qLayout);
    topLayout->addSpacerItem(spQ);

    //Button layout
    QVBoxLayout *btnLayout = new QVBoxLayout;
    btnLayout->addWidget(submit);
    btnLayout->addWidget(cancel);

    //Bottom layout
    QHBoxLayout *botLayout = new QHBoxLayout;
    botLayout->addSpacerItem(spBtn);
    botLayout->addLayout(btnLayout);
    botLayout->addSpacerItem(spBtn);

    //Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(botLayout);

    setLayout(mainLayout);
    setWindowTitle(tr("Survey Form"));
    setFixedHeight(600);
    setFixedWidth(800);

}

void SurveyForm::txtConfirm(){
    txtTY->show();
    connect(txtTY, SIGNAL(closed()),
            this, SLOT(close()));
}

void SurveyForm::enableSubmit(const QString& text){
    submit->setEnabled(!text.isEmpty());
}

void SurveyForm::enableLEQ1(){
    leQ1->setEnabled(true);
}

void SurveyForm::enableLEQ2(){
    leQ2->setEnabled(true);
}

void SurveyForm::enableLEQ3(){
    leQ3->setEnabled(true);
}

void SurveyForm::enableLEQ4(){
    leQ4->setEnabled(true);
}
