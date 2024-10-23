#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QtWidgets>
#include <QtCharts>
#include <QMessageBox>
#include<QFile>
#include<QDir>
#include <QDebug>
#include<QTextStream>
#include <QString>
#include <QPrinter>
#include <QPrintDialog>
#include <QDebug>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionLoad_triggered();



    void chartPunch();
    void chartKick();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H