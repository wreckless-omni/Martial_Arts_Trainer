#ifndef FILEMETHODS_H
#define FILEMETHODS_H
#include <qfile.h>
#include <QString>
#include <QObject>
#pragma once

class fileMethods : public QObject
{
    Q_OBJECT


public:

    double setFormPunch(double numberIn);

    QFile inFile;
    double numberOut = 0;
    double numberIn = 0;

    //fileMethods(QFile inFile);

   // QString  parseFile(QFile inFile);

private:




};

#endif // FILEMETHODS_H
