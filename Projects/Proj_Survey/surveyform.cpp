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

    submit = new QPushButton("Submit");
    submit->setDefault(true);
    submit->setEnabled(false);

    connect();


}
