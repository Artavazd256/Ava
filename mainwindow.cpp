#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <assert.h>
#include <QPainter>
#include "utils.h"
#include <byteswap.h>

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
    delete menuFile;
    delete menuEdit;
    delete menuView;
    delete hexStream;
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
    connect(ui->bigEndianRadioButton, SIGNAL(clicked(bool)), this, SLOT(changBigEndian(bool))); // TODO
    connect(ui->littleEndianRadioButton, SIGNAL(clicked(bool)), this, SLOT(changLittleEndian(bool))); // TODO
}

/**
 * Open file
 * @brief MainWindow::openFile
 */
void MainWindow::openFile()
{
    QString filePath = QFileDialog::getOpenFileName(this);
    assert(filePath != NULL);
    hexStream = new HexStream(this, filePath) ;
    QString data = hexStream->getHexData(4);
    assert(data != NULL);
    ui->hexEdit->setText(data);
}

/**
 *
 * @brief MainWindow::exit
 */
void MainWindow::exit()
{
    ::exit(0);
}

void MainWindow::changLittleEndian(bool b)
{
    hexStream->setMode(Ava::little_endian);
    QString data = hexStream->getHexData(4);
    assert(data != NULL);
    ui->hexEdit->setText(data);
    qDebug()<<"Little endian";
}

void MainWindow::changBigEndian(bool b)
{
    hexStream->setMode(Ava::big_endian);
    QString data = hexStream->getHexData(4);
    assert(data != NULL);
    ui->hexEdit->setText(data);
    qDebug()<<"Big endian";

}

