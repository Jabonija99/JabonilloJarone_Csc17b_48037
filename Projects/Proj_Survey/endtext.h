#ifndef ENDTEXT_H
#define ENDTEXT_H

#include <QDialog>

class QLabel;
class QPushButton;
class QSpacerItem;

class Endtext : public QDialog
{
    Q_OBJECT
    private:
        QLabel *lbText;
        QPushButton *btQuit;
        QSpacerItem *spacer;
        QSpacerItem *spacer2;

    public:
        Endtext(QWidget *parent = 0);

    signals:
        void closed();

    private slots:
        void exit();
};

#endif // ENDTEXT_H
