#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "store.h"
#include "info.h"
#include "cart.h"
#include "checkout.h"
#include "complete.h"

class QStackedWidget;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    //Menu Functions
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();

    Store *store;
    Info *infoscreen;
    Cart *cart;
    Checkout *checkout;
    Complete *complete;

    //Menu buttons
    QMenu *fileMenu;
    QMenu *helpMenu;

    //Menu Actions
    QAction *actLogout;
    QAction *actQuit;
    QAction *actInfo;

    QStackedWidget *stkWidget;
    int pg;

    QPushButton *btNext;
    QPushButton *btPrev;

private slots:
    //Gui functions
    void nextWindow();
    void prevWindow();
    void shop();
    void pgcart();

    void updateStatusbar();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setPg(int);
};

#endif // MAINWINDOW_H
