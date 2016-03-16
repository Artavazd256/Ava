#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initMenu();

private: // fields
    Ui::MainWindow *ui;
    QFile * file = NULL;
    QMenu * menuFile = NULL;
    QMenu * menuEdit = NULL;
    QMenu * menuView = NULL;
    QMenu * menuHelp = NULL;

private: // function
    void initFileMenu();

private slots:
    void openFile();
    void exit();
};

#endif // MAINWINDOW_H
