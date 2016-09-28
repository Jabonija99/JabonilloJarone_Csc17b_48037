
//Protect against multiple inclusions
#ifndef FINDDIALOG_H
#define FINDDIALOG_H

//Includes QDialogue box from widget library
#include <QDialog>

/* Foward declaration of classes
    -Tells the compiler that a class exists,
    without giving all the detal that a class
    defintion provides
        #(usually provided by the header)
    -Allows access to pointers
        # Not a full declaration
    -Makes it faster
*/

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

//Defines FindDialog class that inherits QDialog
class FindDialog : public QDialog
{
    //Defines the class as one that uses signals and slots
    Q_OBJECT

public:
    //Constructor that defines the Widget as the parent
    FindDialog(QWidget *parent = 0); //Defaults at null


signals: //Signal macro keyword
    //Declare functions for when the button is clicked
    //Search forward in the text
    /*
        The compiler initially runs the code as c++,
        Qt::CaseSensitivity is an enum tpye that takes:
            Qt::CaseSensitive & Qt::CaseInsensitive
    */
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    //Search backward in the text
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    //Implements the slots by accessing child widgets
    void findClicked();
    void enableFindButton(const QString &text);

private:
    //Child widgets
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
};

#endif
