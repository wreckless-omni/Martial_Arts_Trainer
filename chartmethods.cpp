#include "chartmethods.h"

void chartMethods::punchChart() {

    //Punch variables-------------------------------------------------------------------------------------------
    static double formPunch = 0;
    double isoPunch = 0;
    double pushPunch = 0;
    double stretchPunch = 718.34;

    //kick varibles----------------------------------------------------------------------------------------------------
    double formKickVel = 0;
    double formkickHeight = 0;

    double isoKickVel = 0;
    double isoKickHeight = 0;

    double stretchKickVel = 557.8;
    double stretchKickHeight = 250.44;

    double legRaisesVel = 0;
    double legraisesHeight = 0;



    //punch----------------------------------------------------------------------------------------------------------------

    QBarSeries *series = new QBarSeries();
    //data set
    QBarSet *set1 = new QBarSet ("Straight Punch Forward Velocity");

    set1 -> append(formPunch);
    set1 -> append(isoPunch);
    set1 -> append(pushPunch);
    set1-> append (stretchPunch);

    series ->append (set1);

    //make chart1
    auto *chart = new QChart();
    chart -> addSeries (series);
    chart -> setTitle ("Straight Punch velocity deg/second");
    chart -> setAnimationOptions(QChart::SeriesAnimations);


    QStringList Methodused;
    //categories
    Methodused.append("practice form");
    Methodused.append("isometrics");
    Methodused.append("push ups");
    Methodused.append("daily stretching");

    //axis
    auto *axisX  = new QBarCategoryAxis();
    axisX ->append(Methodused);
    chart ->addAxis(axisX,Qt::AlignBottom);
    series -> attachAxis(axisX);

    auto *axisY = new QValueAxis();
    axisY -> setRange(0,1000);
    chart-> addAxis(axisY, Qt::AlignLeft);
    series -> attachAxis(axisY);


    //chart1 setup------------------------------------------------------------------------------------------------
    chart ->legend() ->setVisible(true);
    chart -> legend() -> setAlignment(Qt::AlignBottom);
    chart-> setVisible(true);

    QChartView *chartview = new QChartView(chart);
    chartview ->setRenderHint(QPainter::Antialiasing);
    chartview-> setVisible(true);
    chartview -> setMinimumSize(800,300);
    chartview->move (25,0);


  //  this->layout()->addWidget(chartview);



}

void chartMethods::kickChart() {


}
