#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <assert.h>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    menuFile = ui->menuBar->addMenu(tr("&File"));
    menuEdit = ui->menuBar->addMenu(tr("&Edit"));
    menuView = ui->menuBar->addMenu(tr("&View"));
    menuHelp = ui->menuBar->addMenu(tr("&Help"));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete file;
    delete menuFile;
    delete menuEdit;
    delete menuView;
}

void MainWindow::initMenu()
{
    initFileMenu();
}

void MainWindow::initFileMenu() {
    QAction * open = new QAction(tr("&Open"), this);
    QAction * exit = new QAction(tr("&Exit"), this);
    menuFile->addAction(open);
    menuFile->addAction(exit);
    connect(open, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(exit, SIGNAL(triggered()), this, SLOT(exit()));
}

/**
 * Open file
 * @brief MainWindow::openFile
 */
void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    assert(fileName != NULL);
    file = new QFile(fileName, this);
    assert(file != NULL);
    file->open(QIODevice::ReadOnly | QIODevice::WriteOnly);
    while (!file->atEnd()) {
        QString line = file->readLine();
        ui->hexEdit->append(line.toLocal8Bit().toHex());
    }

}

/**
 *
 * @brief MainWindow::exit
 */
void MainWindow::exit()
{
    ::exit(0);
}




