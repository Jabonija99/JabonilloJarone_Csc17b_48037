//Include Qt GUI and QtCore modules
#include <QtWidgets>

/* Other important libraries:
 * * QtCore, QtGui, QtNetwork, QtOpenGL,
 * * QtScript, QtSql, QtSvg, QtXml
*/

#include "finddialog.h"

//Constructor
FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
{
    //Create label (tr("calls for string literal"))
    //Ampersand(&) indicates shortcut key
    label = new QLabel(tr("Find &what:"));
    //Create line editor
    lineEdit = new QLineEdit;
    //Set label and line edit as buddies
    //* buddy - a widget that accepts the focus when the label's
    //* shortcutkey is pressed
    label->setBuddy(lineEdit);

    //Create case checkbox param(text)
    caseCheckBox = new QCheckBox(tr("Match &case"));
    //Create reverse function checkbox
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    //Create a button ("LabelText")
    findButton = new QPushButton(tr("&Find"));
    //Sets the button as the dialog's default button
    findButton->setDefault(true);
    //Disables the button
    findButton->setEnabled(false);

    //Create close button
    closeButton = new QPushButton(tr("Close"));

    //Connects the signals and slots
    //When the text changes in line edit, it enables find button
    connect(lineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(enableFindButton(const QString &)));
    //If the button is clicked, runs the find click function
    connect(findButton, SIGNAL(clicked()),
            this, SLOT(findClicked()));
    //If the close button is clicked, close program
    connect(closeButton, SIGNAL(clicked()),
            this, SLOT(close()));

    //Lays out child widgets
    //Creates a horizontal layout
    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    //Add widgets to top left
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    //Creates a vertical box layout
    QVBoxLayout *leftLayout = new QVBoxLayout;
    //Adds the topleft layout to the left layout
    leftLayout->addLayout(topLeftLayout);
    //Adds widgets to layout
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    //Create a vertical box layout
    QVBoxLayout *rightLayout = new QVBoxLayout;
    //Add widgets
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    //Stretches layout
    rightLayout->addStretch();

    //Creat a horizontal box for main layout
    QHBoxLayout *mainLayout = new QHBoxLayout;
    //Add layouts to the main layout
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    //Assigns the horizontal box as main layout
    setLayout(mainLayout);

    //Sets title (text)
    setWindowTitle(tr("Find"));
    //Sets the height of the window
    //sizeHint().height() returns the widget's "ideal" size
    setFixedHeight(sizeHint().height());

    //Destructors are not necessary since qt automatically deletes
    //child objects when the parent is destroyed.
}

void FindDialog::findClicked()
{
    //Receives text from lineEdit
    QString text = lineEdit->text();
    //Recieves the case sensitivity check box status
    Qt::CaseSensitivity cs =
            caseCheckBox->isChecked() ? Qt::CaseSensitive
                                      : Qt::CaseInsensitive;
    //If the backward box is checked
    if (backwardCheckBox->isChecked()) {
        //Search backwards
        emit findPrevious(text, cs);
    } else {
        //Search forward
        emit findNext(text, cs);
    }
}

void FindDialog::enableFindButton(const QString &text)
{
    //Enables dialogue box when the text is not empty
    findButton->setEnabled(!text.isEmpty());
}
