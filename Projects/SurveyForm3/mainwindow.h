#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "question1.h"
#include "question2.h"
#include "question3.h"
#include "complete.h"

class QLabel;
class QLineEdit;
class QPushButton;
class QSpacerItem;
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

    //Objects
    Login *window1;
    Question1 *window2;
    Question2 *window3;
    Question3 *window4;
    Complete *window5;

    QPushButton *btNext;
    QPushButton *btPrev;

    //Menu buttons
    QMenu *fileMenu;
    QMenu *helpMenu;

    //Menu Actions
    QAction *actLogout;
    QAction *actQuit;
    QAction *actInfo;

    QStackedWidget *stackedWidget;
    int pg;

private slots:
    //Gui functions
    void nextWindow();
    void prevWindow();

    void updateStatusbar();

public:
    MainWindow();

    void setPg(int);

protected:
    //Window close function
    //void closeEvent(QCloseEvent *event);





};

#endif // MAINWINDOW_H
