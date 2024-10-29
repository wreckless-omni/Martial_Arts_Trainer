#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fileMethods.h"
#include "chartmethods.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   chartMethods ch;



   chartPunch();
    chartKick();


    }

MainWindow::~MainWindow()
{
    delete ui;
}




    void MainWindow::chartPunch(){
    fileMethods m;

    //Punch variables-------------------------------------------------------------------------------------------
    static double formPunch = 0;
    double isoPunch = 0;
    double pushPunch = 0;
    double stretchPunch = 0;
    double nothingPunch = 0;
    double noResPunch = 0;



    //file loading for charts1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111


    //punchesPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
    QFile formPfile("C:/Users/Justin/Documents/Qt_test_widgets_justin/Punch_Form");

    if (formPfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&formPfile);

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList values = line.split("="); // Assuming key=value format

            if (values.size() == 2) {
                QString value = values[1].trimmed();

                formPunch = value.toDouble();
                // Use the key and value as needed
            }

        }

        formPfile.close();
    } else {
        qDebug() << "Error opening file!";
    }

    QFile isofile("C:/Users/Justin/Documents/Qt_test_widgets_justin/Punch_Iso");

    if (isofile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&isofile);

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList values = line.split("="); // Assuming key=value format

            if (values.size() == 2) {
                QString value = values[1].trimmed();

                isoPunch = value.toDouble();
                // Use the key and value as needed
            }

        }

        isofile.close();
    } else {
        qDebug() << "Error opening file!";
    }

    QFile pushPfile("C:/Users/Justin/Documents/Qt_test_widgets_justin/Punch_Push");

    if (pushPfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&pushPfile);

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList values = line.split("="); // Assuming key=value format

            if (values.size() == 2) {
                QString value = values[1].trimmed();

                pushPunch = value.toDouble();
                // Use the key and value as needed
            }

        }

        pushPfile.close();
    } else {
        qDebug() << "Error opening file!";
    }

    QFile stretchPfile("C:/Users/Justin/Documents/Qt_test_widgets_justin/Punch_Stretch");

    if (stretchPfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&stretchPfile);

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList values = line.split("="); // Assuming key=value format

            if (values.size() == 2) {
                QString value = values[1].trimmed();

                stretchPunch = value.toDouble();
            }

        }

        stretchPfile.close();
    } else {
        qDebug() << "Error opening file!";
    }





//recommendation matrix222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
    if ( std::max( { formPunch, isoPunch, stretchPunch, pushPunch } ) == formPunch )
    {
        ui->textBrowser-> setText("Slow practice with resistance bands has the most benefit for your punches");

    }else  if ( std::max( { formPunch, isoPunch, stretchPunch, pushPunch } ) == isoPunch )
    {
        ui->textBrowser-> setText("Isometrics has the most benefit for your punches");

    }else  if ( std::max( { formPunch, isoPunch, stretchPunch, pushPunch } ) == pushPunch )
    {
        ui->textBrowser-> setText("Knuckle push ups have the most benefit for your punches");

    }else  if ( std::max( { formPunch, isoPunch, stretchPunch, pushPunch } ) == stretchPunch )
    {
        ui->textBrowser-> setText("Stretching has the most benefit for your punches");

    }
    else  if ( std::max( { formPunch, isoPunch, stretchPunch, pushPunch } ) == nothingPunch )
    {
        ui->textBrowser-> setText("Doing nothing has the most benefit for your punches");

    }
    else  if ( std::max( { formPunch, isoPunch, stretchPunch, pushPunch } ) == noResPunch )
    {
        ui->textBrowser-> setText("Doing many regular punches has the most benefit for your punches");

    }


    //stretchPunch = m.setFormPunch();
    //punch----------------------------------------------------------------------------------------------------------------

    QBarSeries *series = new QBarSeries();
    //data set
    QBarSet *set1 = new QBarSet ("Straight Punch Forward Velocity");

    set1 -> append(formPunch);
    set1 -> append(isoPunch);
    set1 -> append(pushPunch);
    set1-> append (stretchPunch);
    set1 -> append (nothingPunch);
    set1 -> append (noResPunch);


    series ->append (set1);

    //make chart1
    auto *chart = new QChart();
    chart -> addSeries (series);
    chart -> setTitle ("Straight Punch velocity deg/second");
    chart -> setAnimationOptions(QChart::SeriesAnimations);


    QStringList Methodused;
    //categories
    Methodused.append("form w/ bands");
    Methodused.append("isometrics");
    Methodused.append("Knuckle push ups");
    Methodused.append("daily stretching");
    Methodused.append("Doing nothing");
    Methodused.append("Practice Punches");

    //axis
    auto *axisX  = new QBarCategoryAxis();
    axisX ->append(Methodused);
    chart ->addAxis(axisX,Qt::AlignBottom);
    series -> attachAxis(axisX);

    auto *axisY = new QValueAxis();
    axisY -> setRange(0,1500);
    chart-> addAxis(axisY, Qt::AlignLeft);
    series -> attachAxis(axisY);


    //chart1 setup------------------------------------------------------------------------------------------------
    chart ->legend() ->setVisible(true);
    chart -> legend() -> setAlignment(Qt::AlignBottom);
    chart-> setVisible(true);

    QChartView *chartview = new QChartView(chart);
    chartview ->setRenderHint(QPainter::Antialiasing);
    chartview-> setVisible(true);
    chartview -> setMinimumSize(900,300);
    chartview->move (25,0);


    this->layout()->addWidget(chartview);


}

void MainWindow::chartKick(){

    //kick varibles----------------------------------------------------------------------------------------------------
    double formKickVel = 0;
    double formkickHeight = 0;

    double isoKickVel = 853.5;
    double isoKickHeight = 532.68;

    double stretchKickVel = 0; //557.8
    double stretchKickHeight = 0; //250.44

    double legRaisesVel = 0;
    double legraisesHeight = 0;

    double nothingKickVel = 0;
    double nothingKickHeight = 0;

    double noResKickVel= 0;
    double noresKickHeight = 0;



    //kick  variable file loadingKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK
    QFile stretchKfile("C:/Users/Justin/Documents/Qt_test_widgets_justin/Kick_Stretch");
    if (stretchKfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&stretchKfile);

 QStringList lines;
    while (!in.atEnd()) {
        lines.append(in.readLine());
    }

    // Example: Extract data based on a pattern
    for (const QString &line : lines) {
        if (line.startsWith("kickVelocity")) {
            QString velLine = line.split("=").at(1).trimmed();
            stretchKickVel = velLine.toDouble();
        }

        if (line.startsWith("kickHeight")) {
            QString heiLine = line.split("=").at(1).trimmed();
            stretchKickHeight = heiLine.toDouble();
        }
    }
        stretchKfile.close();
    } else {
        qDebug() << "Error opening file!";
    }

    QFile LegRaiseKfile("C:/Users/Justin/Documents/Qt_test_widgets_justin/Kick_Lift");
    if (LegRaiseKfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&LegRaiseKfile);

        QStringList lines;
        while (!in.atEnd()) {
            lines.append(in.readLine());
        }

        // Example: Extract data based on a pattern
        for (const QString &line : lines) {
            if (line.startsWith("kickVelocity")) {
                QString velLine = line.split("=").at(1).trimmed();
                legRaisesVel = velLine.toDouble();
            }

            if (line.startsWith("kickHeight")) {
                QString heiLine = line.split("=").at(1).trimmed();
                legraisesHeight = heiLine.toDouble();
            }
        }
        LegRaiseKfile.close();
    } else {
        qDebug() << "Error opening file!";
    }


    QFile KickFormKfile("C:/Users/Justin/Documents/Qt_test_widgets_justin/Kick_Form");
    if (KickFormKfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&KickFormKfile);

        QStringList lines;
        while (!in.atEnd()) {
            lines.append(in.readLine());
        }

        // Example: Extract data based on a pattern
        for (const QString &line : lines) {
            if (line.startsWith("kickVelocity")) {
                QString velLine = line.split("=").at(1).trimmed();
                formKickVel = velLine.toDouble();
            }

            if (line.startsWith("kickHeight")) {
                QString heiLine = line.split("=").at(1).trimmed();
                formkickHeight = heiLine.toDouble();
            }
        }
        KickFormKfile.close();
    } else {
        qDebug() << "Error opening file!";
    }


//kick velocity automagick

    if ( std::max( { formKickVel, isoKickVel, stretchKickVel, legRaisesVel, nothingKickVel, noResKickVel } ) == formKickVel )
    {
        ui->textBrowser_2-> setText("Slow practice with resistance bands has the most benefit for your kick velocity");

    }else   if ( std::max( { formKickVel, isoKickVel, stretchKickVel, legRaisesVel, nothingKickVel, noResKickVel } ) == isoKickVel )
    {
        ui->textBrowser_2-> setText("Isometrics has the most benefit for your kick velocity");

    } else  if ( std::max( { formKickVel, isoKickVel, stretchKickVel, legRaisesVel, nothingKickVel, noResKickVel } ) == stretchKickVel )
    {
        ui->textBrowser_2-> setText("Stretching has the most benefit for your kick velocity");

    } else   if ( std::max( { formKickVel, isoKickVel, stretchKickVel, legRaisesVel, nothingKickVel, noResKickVel } ) == legRaisesVel)

    ui->textBrowser_2-> setText("Leg raises have the most benefit for your kick velocity");

    else   if ( std::max( { formKickVel, isoKickVel, stretchKickVel, legRaisesVel, nothingKickVel, noResKickVel } ) == nothingKickVel)

    ui->textBrowser_2-> setText("doing nothing has the most benefit for your kick velocity");

    else  if ( std::max( { formKickVel, isoKickVel, stretchKickVel, legRaisesVel, nothingKickVel, noResKickVel } ) == noResKickVel)

    ui->textBrowser_2-> setText("Practicing many kicks has the most benefit for your kick velocity");


   // kick height Automagick
    //kick velocity automagick

    if ( std::max( { formkickHeight, isoKickHeight, stretchKickHeight, legraisesHeight, nothingKickHeight, noresKickHeight } ) == formkickHeight )
    {
        ui->textBrowser_4-> setText("Slow practice with resistance bands has the most benefit for your kick height");

    }else  if ( std::max( { formkickHeight, isoKickHeight, stretchKickHeight, legraisesHeight, nothingKickHeight, noresKickHeight } ) == isoKickHeight )
    {
        ui->textBrowser_4-> setText("Isometrics has the most benefit for your kick height");

    } else if ( std::max( { formkickHeight, isoKickHeight, stretchKickHeight, legraisesHeight, nothingKickHeight, noresKickHeight } ) == stretchKickVel )
    {
        ui->textBrowser_4-> setText("Stretching has the most benefit for your kick height");

    } else  if ( std::max( { formkickHeight, isoKickHeight, stretchKickHeight, legraisesHeight, nothingKickHeight, noresKickHeight } ) == legRaisesVel)

    ui->textBrowser_4-> setText("Leg raises have the most benefit for your kick height");

    else   if ( std::max( { formkickHeight, isoKickHeight, stretchKickHeight, legraisesHeight, nothingKickHeight, noresKickHeight } ) == nothingKickVel)

    ui->textBrowser_4-> setText("doing nothing has the most benefit for your kick height");

    else  if ( std::max( { formkickHeight, isoKickHeight, stretchKickHeight, legraisesHeight, nothingKickHeight, noresKickHeight } ) == noResKickVel)

    ui->textBrowser_4-> setText("Practicing many kicks has the most benefit for your kick height");






    QBarSeries *series2 = new QBarSeries();
    //data set
    QBarSet *set2 = new QBarSet ("Sidekick outer Velocity");

    set2 -> append(formKickVel);
    set2 -> append(isoKickVel);
    set2 -> append(legRaisesVel);
    set2 -> append (stretchKickVel);
    set2 -> append (nothingKickVel);
    set2 -> append (noResKickVel);

    QBarSet *set3 = new QBarSet ("Sidekick Upward velocity");

    set3 -> append(formkickHeight);
    set3 -> append(isoKickHeight);
    set3 -> append(legraisesHeight);
    set3 -> append (stretchKickHeight);
    set3 -> append (nothingKickHeight);
    set3 -> append (noresKickHeight);

    series2 ->append (set2);
    series2 ->append (set3);


    //make chart2
    auto *chart2 = new QChart();
    chart2-> addSeries (series2);
    chart2 -> setTitle ("Sidekick Progress Against Method Deg/S");
    chart2 -> setAnimationOptions(QChart::SeriesAnimations);


    QStringList Methodused2;
    //categories
    Methodused2.append("form w/ bands");
    Methodused2.append("isometrics");
    Methodused2.append("Leg raises");
    Methodused2.append("daily stretching");
    Methodused2.append("doing nothing");
    Methodused2.append("practicing Kicks");

    //axis
    auto *axisX2  = new QBarCategoryAxis();
    axisX2 ->append(Methodused2);
    chart2 ->addAxis(axisX2,Qt::AlignBottom);
    series2 -> attachAxis(axisX2);

    auto *axisY2 = new QValueAxis();
    axisY2 -> setRange(0,1500);
    chart2-> addAxis(axisY2, Qt::AlignLeft);
    series2 -> attachAxis(axisY2);


    //chart setup
    chart2 ->legend() ->setVisible(true);
    chart2 -> legend() -> setAlignment(Qt::AlignBottom);
    chart2-> setVisible(true);

    QChartView *chartview2 = new QChartView(chart2);
    chartview2 ->setRenderHint(QPainter::Antialiasing);
    chartview2-> setVisible(true);
    chartview2 -> setMinimumSize(900,300);
    chartview2->move (25,300);


    this->layout()->addWidget(chartview2);
}




//load file action
 void MainWindow::on_actionLoad_triggered()
{

    QString file_name = QFileDialog:: getOpenFileName(this,"open new file", "C:\\Users\\Justin\\Desktop\\punch_kick data");
  //  QMessageBox::information (this,"Loaded", file_name);
    QFile file (file_name);

    if (!file.open(QIODevice::ReadOnly)){
       // QMessageBox::information(0,"info", file.errorString());
        qDebug() << file.errorString();
    }

    QTextStream in(&file);
    QString line;
    double currentMaximum1 = 0;
    double currentMaximum2 = 0;


    if(file_name.contains("Punch")){
    while (!in.atEnd()) {
        line = in.readLine();
        QStringList words = line.split(","); // Split line into words

        if (words.size() >= 3) { // Check if there are at least 3 words
            QString thirdString = words[2]; // Get the third word (index 2)

           // if (!line.contains("-"))

            currentMaximum1 = qMax(currentMaximum1, thirdString.toDouble());

            ui->textBrowser_3-> setText(QString::number(currentMaximum1));


            if(file_name.contains("Form")){
                QFile writefile( "C:/Users/Justin/Documents/Qt_test_widgets_justin/Punch_Form" );

                if (writefile.isOpen()) {
                    // File is already open, close it
                    writefile.close();
                }

                if ( writefile.open(QIODevice::WriteOnly))
                {
                    QTextStream stream( &writefile );
                    stream << "Punchform = " <<currentMaximum1 << Qt::endl;
                    writefile.close();
                }
            }


            if(file_name.contains("Iso")){
                QFile writefile( "C:/Users/Justin/Documents/Qt_test_widgets_justin/Punch_Iso" );

                if (writefile.isOpen()) {
                    // File is already open, close it
                    writefile.close();
                }

                if ( writefile.open(QIODevice::WriteOnly))
                {
                    QTextStream stream( &writefile );
                    stream << "PunchIso = " <<currentMaximum1 << Qt::endl;
                    writefile.close();
                }
            }

            if(file_name.contains("Push")){
                QFile writefile( "C:/Users/Justin/Documents/Qt_test_widgets_justin/Punch_Push" );

                if (writefile.isOpen()) {
                    // File is already open, close it
                    writefile.close();
                }

                if ( writefile.open(QIODevice::WriteOnly))
                {
                    QTextStream stream( &writefile );
                    stream << "PunchPush = " <<currentMaximum1 << Qt::endl;
                    writefile.close();
                }
            }

            if(file_name.contains("Stretch")){
                QFile writefile( "C:/Users/Justin/Documents/Qt_test_widgets_justin/Punch_Stretch" );

                if (writefile.isOpen()) {
                    // File is already open, close it
                    writefile.close();
                }

                if ( writefile.open(QIODevice::WriteOnly))
                {
                    QTextStream stream( &writefile );
                    stream << "Punchstretch = " <<currentMaximum1 << Qt::endl;
                    writefile.close();
                }
            }

            if(file_name.contains("Nothing")){
                QFile writefile( "C:/Users/Justin/Documents/Qt_test_widgets_justin/Punch_Nothing" );

                if (writefile.isOpen()) {
                    // File is already open, close it
                    writefile.close();
                }

                if ( writefile.open(QIODevice::WriteOnly))
                {
                    QTextStream stream( &writefile );
                    stream << "Punchnothing = " <<currentMaximum1 << Qt::endl;
                    writefile.close();
                }
            }

            if(file_name.contains("NoRes")){
                QFile writefile( "C:/Users/Justin/Documents/Qt_test_widgets_justin/Punch_NoRes" );

                if (writefile.isOpen()) {
                    // File is already open, close it
                    writefile.close();
                }

                if ( writefile.open(QIODevice::WriteOnly))
                {
                    QTextStream stream( &writefile );
                    stream << "PunchNoRes = " <<currentMaximum1 << Qt::endl;
                    writefile.close();
                }
            }


        }

    }

    chartPunch();



    }

    if(file_name.contains("Kick")){

        while (!in.atEnd()) {
            line = in.readLine();
            QStringList words = line.split(","); // Split line into words

            if (words.size() >= 3) { // Check if there are at least 3 words
                QString thirdString = words[2]; // Get the third word (index 2)
                QString fourthString = words[3];

                // if (!line.contains("-"))

                currentMaximum1 = qMax(currentMaximum1, thirdString.toDouble());
                currentMaximum2 = qMax(currentMaximum2, fourthString.toDouble());

//reversed because of sensor position relative to the leg
                ui->textBrowser_3-> setText(QString::number(currentMaximum2) + ", " + QString::number(currentMaximum1));


                //automagic file updates

                if(file_name.contains("Form")){
                QFile writefile( "C:/Users/Justin/Documents/Qt_test_widgets_justin/Kick_Form" );

                if (writefile.isOpen()) {
                    // File is already open, close it
                    writefile.close();
                }

                if ( writefile.open(QIODevice::WriteOnly))
                {
                    QTextStream stream( &writefile );
                    stream << "kickVelocity = " <<currentMaximum2 << "\nkickHeight = "<< currentMaximum1 << Qt::endl;
                    writefile.close();
                }
                }


                if(file_name.contains("Iso")){
                    QFile writefile( "C:/Users/Justin/Documents/Qt_test_widgets_justin/Kick_Iso" );

                    if (writefile.isOpen()) {
                        // File is already open, close it
                        writefile.close();
                    }

                    if ( writefile.open(QIODevice::WriteOnly))
                    {
                        QTextStream stream( &writefile );
                        stream << "kickVelocity = " <<currentMaximum2 << "\nkickHeight = "<< currentMaximum1 << Qt::endl;
                        writefile.close();
                    }
                }

                if(file_name.contains("Lift")){
                    QFile writefile( "C:/Users/Justin/Documents/Qt_test_widgets_justin/Kick_Lift" );

                    if (writefile.isOpen()) {
                        // File is already open, close it
                        writefile.close();
                    }

                    if ( writefile.open(QIODevice::WriteOnly))
                    {
                        QTextStream stream( &writefile );
                        stream << "kickVelocity = " <<currentMaximum2 << "\nkickHeight = "<< currentMaximum1 << Qt::endl;
                        writefile.close();
                    }
                }




                if(file_name.contains("Stretch")){
                    QFile writefile( "C:/Users/Justin/Documents/Qt_test_widgets_justin/Kick_Stretch" );

                    if (writefile.isOpen()) {
                        // File is already open, close it
                        writefile.close();
                    }

                    if ( writefile.open(QIODevice::WriteOnly))
                    {
                        QTextStream stream( &writefile );
                        stream << "kickVelocity = " <<currentMaximum2 << "\nkickHeight = "<< currentMaximum1 << Qt::endl;
                        writefile.close();
                    }
                }


                if(file_name.contains("Nothing")){
                    QFile writefile( "C:/Users/Justin/Documents/Qt_test_widgets_justin/Kick_Nothing" );

                    if (writefile.isOpen()) {
                        // File is already open, close it
                        writefile.close();
                    }

                    if ( writefile.open(QIODevice::WriteOnly))
                    {
                        QTextStream stream( &writefile );
                        stream << "kickVelocity = " <<currentMaximum2 << "\nkickHeight = "<< currentMaximum1 << Qt::endl;
                        writefile.close();
                    }
                }

                if(file_name.contains("NoRes")){
                    QFile writefile( "C:/Users/Justin/Documents/Qt_test_widgets_justin/Kick_NoRes" );

                    if (writefile.isOpen()) {
                        // File is already open, close it
                        writefile.close();
                    }

                    if ( writefile.open(QIODevice::WriteOnly))
                    {
                        QTextStream stream( &writefile );
                        stream << "kickVelocity = " <<currentMaximum2 << "\nkickHeight = "<< currentMaximum1 << Qt::endl;
                        writefile.close();
                    }
                }


            }

        }

        chartKick();
    }




    }



    void MainWindow::on_actionDelete_triggered()
    {
        QString file_name = QFileDialog:: getOpenFileName(this,"open new file", "C:\\Users\\Justin\\Documents\\Qt_test_widgets_justin");
        QFile nullfile (file_name);

        if (nullfile.isOpen()) {
            // File is already open, close it
            nullfile.close();
        }

        if ( nullfile.open(QIODevice::WriteOnly))
        {
            QTextStream stream( &nullfile );
            stream << "" << Qt::endl;
            nullfile.close();
        }

        chartKick() ;
        chartPunch();

    }

