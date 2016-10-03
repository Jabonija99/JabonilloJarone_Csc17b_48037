#ifndef SURVEYFORM_H
#define SURVEYFORM_H

#include <QDialog>

class QLabel;
class QPushButton;
class QLineEdit;
class QFile;

class SurveyForm : public QDialog
{
    Q_OBJECT

    private:
        QLabel *lbName;
        QLabel *lbQ1;
        QLabel *lbQ2;
        QLabel *lbQ3;
        QLabel *lbQ4;

        QLineEdit *leName;
        QLineEdit *leQ1;
        QLineEdit *leQ2;
        QLineEdit *leQ3;
        QLineEdit *leQ4;

        QPushButton *submit;
        QPushButton *cancel;

        QFile *outFile;
    public:
        SurveyForm(QWidget *parent =0);
    private slots:
        void saveForm(const QString&);
        void enableSubmit(const QString&text);
};

#endif // SURVEYFORM_H
