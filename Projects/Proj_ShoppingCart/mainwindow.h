#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Forminfo;
class Checkout;
class endtext;

class mainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        void setItems();
        void setConnect();
        void layItems();

        Forminfo wForm;
        Checkout wChkout;
        endtext wEnd;

    protected:
        void closeEvent(QCloseEvent *event);

    public:
        mainWindow();

    private slots:

};

#endif // MAINWINDOW_H
