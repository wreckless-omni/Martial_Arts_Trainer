#ifndef CHARTMETHODS_H
#define CHARTMETHODS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

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

class chartMethods : public QObject
{

    Q_OBJECT
public:
  void  punchChart();
    void kickChart();
};

#endif // CHARTMETHODS_H
