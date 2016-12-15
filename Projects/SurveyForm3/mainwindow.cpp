#include "mainwindow.h"
#include <QtWidgets>

const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;

MainWindow::MainWindow()
{
    setPg(0);

    window1 = new Login();
    window2 = new Question1();
    window3 = new Question2();
    window4 = new Question3();
    window5 = new Complete();

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(window1);
    stackedWidget->addWidget(window2);
    stackedWidget->addWidget(window3);
    stackedWidget->addWidget(window4);
    stackedWidget->addWidget(window5);

    setCentralWidget(stackedWidget);

    btNext = new QPushButton("Next");
    btPrev = new QPushButton("Prev");

    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();


    connect(window5,SIGNAL(toExit()),
            this, SLOT(close()));
    connect(window1, SIGNAL(toSurvey()),
            this, SLOT(nextWindow()));
    connect(window1, SIGNAL(toExit()),
            this, SLOT(close()));
}

void MainWindow::setPg(int page){
    if(page > 4)
        pg = 4;
    else if(page < 0)
        pg = 0;
    else
        pg = page;

}

void MainWindow::nextWindow(){
    //Increment to next page
    setPg(++pg);

    stackedWidget->setCurrentIndex(pg);

    updateStatusbar();
}

void MainWindow::prevWindow(){
    //Decrement to prev page
    setPg(--pg);

    stackedWidget->setCurrentIndex(pg);

    updateStatusbar();
}

void MainWindow::updateStatusbar(){

    if(pg < 1 || pg >3)
        btNext->setEnabled(false);
    else
        btNext->setEnabled(true);


}

void MainWindow::createActions(){
    actLogout = new QAction(tr("Logout"), this);
    actQuit = new QAction(tr("Quit"), this);
    actInfo = new QAction(tr("Info"), this);

    connect(actQuit, SIGNAL(triggered()),
            this, SLOT(close()));
    connect(btNext,SIGNAL(clicked()),
            this, SLOT(nextWindow()));
    connect(btPrev,SIGNAL(clicked()),
            this, SLOT(prevWindow()));

}

void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(actLogout);
    fileMenu->addAction(actQuit);

    helpMenu = menuBar()->addMenu(tr("Help"));
    helpMenu->addAction(actInfo);

}

void MainWindow::createContextMenu(){
    setFixedHeight(SCREEN_HEIGHT);
    setFixedWidth(SCREEN_WIDTH);
}

void MainWindow::createToolBars(){

}

void MainWindow::createStatusBar(){
    //statusBar()->addWidget(btPrev,3);
    statusBar()->addWidget(btNext,3);

    updateStatusbar();
}


