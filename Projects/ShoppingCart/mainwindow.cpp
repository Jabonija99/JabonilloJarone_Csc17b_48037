#include "mainwindow.h"
#include <QtWidgets>

const int SCREEN_HEIGHT = 768;
const int SCREEN_WIDTH = 1024;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    item = new Item("punchingbag.txt");
    store = new Shop();
    cart = new Cart();

    setCentralWidget(cart);
    //setCentralWidget(store);
    //setCentralWidget(item);


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

}
