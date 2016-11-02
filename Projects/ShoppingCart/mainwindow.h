#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "item.h"
#include "shop.h"
#include "cart.h"

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

    //Menu buttons
    QMenu *fileMenu;
    QMenu *helpMenu;

    //Menu Actions
    QAction *actLogout;
    QAction *actQuit;
    QAction *actInfo;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
