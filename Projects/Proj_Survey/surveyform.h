#ifndef SURVEYFORM_H
#define SURVEYFORM_H

#include <QDialog>
#include "endtext.h"

class QLabel;
class QPushButton;
class QLineEdit;
class QRadioButton;
class QSpacerItem;
class QFile;

class SurveyForm : public QDialog
{
    Q_OBJECT

    private:
        //System functions
        void setItems();
        void setConnects();
        void layItems();

        //Labels
        QLabel *lbName;
        QLabel *lbQ1;
        QLabel *lbQ2;
        QLabel *lbQ3;
        QLabel *lbQ4;

        //Text Lines
        QLineEdit *leName;
        QLineEdit *leQ1;
        QLineEdit *leQ2;
        QLineEdit *leQ3;
        QLineEdit *leQ4;

        //RadioButtons
        QRadioButton *rbM;      //Male
        QRadioButton *rbF;      //Female

        QRadioButton *rbQ1_1;
        QRadioButton *rbQ1_2;
        QRadioButton *rbQ1_3;

        QRadioButton *rbQ2_1;
        QRadioButton *rbQ2_2;
        QRadioButton *rbQ2_3;

        QRadioButton *rbQ3_1;
        QRadioButton *rbQ3_2;
        QRadioButton *rbQ3_3;

        QRadioButton *rbQ4_1;
        QRadioButton *rbQ4_2;
        QRadioButton *rbQ4_3;

        //Spacers
        QSpacerItem *spQ;
        QSpacerItem *spBtn;

        //Buttons
        QPushButton *submit;
        QPushButton *cancel;

        //Completion Text
        Endtext *txtTY;

        QFile *outFile;
    public:
        SurveyForm(QWidget *parent =0);
    private slots:
        void txtConfirm();
        void enableSubmit(const QString&);
        void enableLEQ1();
        void enableLEQ2();
        void enableLEQ3();
        void enableLEQ4();
};

#endif // SURVEYFORM_H
