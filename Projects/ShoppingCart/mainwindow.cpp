#include "mainwindow.h"
#include <QtWidgets>

const int SCREEN_HEIGHT = 768;
const int SCREEN_WIDTH = 1024;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setPg(0);

    item = new Item("punchingbag.txt");
    store = new Shop();
    cart = new Cart();
    checkout = new Checkout();

    stkWidget = new QStackedWidget;
    stkWidget->addWidget(store);
    stkWidget->addWidget(cart);
    stkWidget->addWidget(checkout);

    setCentralWidget(stkWidget);


    btNext = new QPushButton("Next");
    btPrev = new QPushButton("Prev");

    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();

}

MainWindow::~MainWindow()
{

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
    statusBar()->addWidget(btPrev,3);
    statusBar()->addWidget(btNext,3);

    updateStatusbar();
}

void MainWindow::setPg(int page){
    if(page > 2)
        pg = 2;
    else if(page < 0)
        pg = 0;
    else
        pg = page;

}

void MainWindow::nextWindow(){
    //Increment to next page
    setPg(++pg);

    stkWidget->setCurrentIndex(pg);

    updateStatusbar();
}

void MainWindow::prevWindow(){
    //Decrement to prev page
    setPg(--pg);

    stkWidget->setCurrentIndex(pg);

    updateStatusbar();
}

void MainWindow::updateStatusbar(){

    if(pg <1)
        btPrev->setEnabled(false);
    else
        btPrev->setEnabled(true);

    if(pg>1)
        btNext->setEnabled(false);
    else
        btNext->setEnabled(true);

}
