#include <QApplication>
#include "surveyform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SurveyForm *form = new SurveyForm();
    form->show();


    return a.exec();
}
