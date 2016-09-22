#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_3_clicked()
{
    on_label_objectNameChanged("Red");

}

void MainWindow::on_label_objectNameChanged(const QString &objectName)
{

}
