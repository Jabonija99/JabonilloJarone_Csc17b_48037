#include "mainwindow.h"
#include <QtWidgets>

const int SCREEN_HEIGHT = 768;
const int SCREEN_WIDTH = 1024;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setPg(0);

    //create items
    store = new Store();
    infoscreen = new Info();
    cart = new Cart();
    checkout = new Checkout();
    complete = new Complete();

    stkWidget = new QStackedWidget;
    stkWidget->addWidget(store);
    stkWidget->addWidget(infoscreen);
    stkWidget->addWidget(cart);
    stkWidget->addWidget(checkout);
    stkWidget->addWidget(complete);

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
    delete infoscreen;
    delete cart;
    delete checkout;
    delete complete;
    delete store;
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
    connect(store,SIGNAL(sendItem(Item*)),
            infoscreen,SLOT(load(Item*)));

    connect(infoscreen, SIGNAL(sendItem(Item*)),
            cart, SLOT(add(Item*)));

    connect(store,SIGNAL(toInfo()),
            this, SLOT(nextWindow()));
    connect(store,SIGNAL(toCart()),
            this,SLOT(pgcart()));

    connect(infoscreen,SIGNAL(toCart()),
            this,SLOT(nextWindow()));
    connect(infoscreen,SIGNAL(toShop()),
            this,SLOT(prevWindow()));

    connect(cart, SIGNAL(toShop()),
            this, SLOT(shop()));
    connect(cart, SIGNAL(toCheck()),
            this, SLOT(nextWindow()));

    connect(checkout, SIGNAL(toShop()),
            this, SLOT(shop()));
    connect(checkout, SIGNAL(toFinish()),
            this, SLOT(nextWindow()));
    connect(checkout, SIGNAL(toCart()),
            this, SLOT(prevWindow()));

    connect(complete,SIGNAL(toExit()),
            this, SLOT(close()));
    connect(complete,SIGNAL(toShop()),
            this,SLOT(shop()));



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
    //statusBar()->addWidget(btNext,3);

    updateStatusbar();
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

    stkWidget->setCurrentIndex(pg);

    updateStatusbar();
}

void MainWindow::prevWindow(){
    //Decrement to prev page
    setPg(--pg);

    stkWidget->setCurrentIndex(pg);

    updateStatusbar();
}

void MainWindow::shop(){
    pg=0;

    stkWidget->setCurrentIndex(pg);

    updateStatusbar();
}

void MainWindow::pgcart(){
    pg=2;

    stkWidget->setCurrentIndex(pg);

    updateStatusbar();
}

void MainWindow::updateStatusbar(){

    if(pg <1)
        btPrev->setEnabled(false);
    else
        btPrev->setEnabled(true);

    if(pg>3)
        btNext->setEnabled(false);
    else
        btNext->setEnabled(true);

}
