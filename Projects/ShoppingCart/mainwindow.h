#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "item.h"
#include "shop.h"
#include "cart.h"
#include "checkout.h"

class QStackedWidget;

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

    Shop *store;
    Item *item;
    Cart *cart;
    Checkout *checkout;

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
    void toItem(bool);

    void updateStatusbar();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setPg(int);
};

#endif // MAINWINDOW_H
