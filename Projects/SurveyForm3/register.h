#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>


class QLabel;
class QLineEdit;
class QPushButton;
class QSpacerItem;

class Register: public QDialog
{
    Q_OBJECT

private:
    //Gui functions
    void setItems();
    void setConnect();
    void layItems();

    //Label items
    QLabel *lbTitle;
    QLabel *lbName;
    QLabel *lbPin;      //Password

    //Line edit items
    QLineEdit *leName;
    QLineEdit *lePin;

    //Button items
    QPushButton *btLogin;
    QPushButton *btQuit;
    QPushButton *btRegister;

    //Spacer items
    QSpacerItem *spTitle;//Title label spacer
    QSpacerItem *spName;//Name label spacer
    QSpacerItem *spPin;//Pin label spacers
    QSpacerItem *spBtn;//Button spacer
    QSpacerItem *spVert; //Vertical spacer
    QSpacerItem *spHorz; //Horizontal spacer

public:
    Register(QWidget *parent = 0);

public slots:
    void goSurvey();
    void goExit();

signals:
    void toSurvey();
    void toExit();

};

#endif // REGISTER_H
