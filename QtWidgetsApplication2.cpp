#include "QtWidgetsApplication2.h"
#include "QtCore/qmetaobject.h"
#include"QtSql/qsqldatabase.h"
QtWidgetsApplication2::QtWidgetsApplication2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //自动绑定按钮点击事件和槽
    /*QMetaObject p;
    p.connectSlotsByName(this);*/
    //
    //实例化交互类对象
    my_context = new JsContext(this);
    //实例化QWebChannel对象
    my_channel = new QWebChannel(this);
    //将交互类对象注册到QWebChannel对象中
    my_channel->registerObject("context_qt", my_context);
    //设置控件的QWebChannel
    ui.webEngineView->page()->setWebChannel(my_channel);
    //绑定交互类的传递消息的信号和槽
    connect(my_context,SIGNAL(set_Lng_Lat_Level(QString, QString, QString)),this ,SLOT(getPositionMsg(QString, QString, QString)));
    connect(my_context, SIGNAL(send_distance_msg(QString)), this, SLOT(getDistanceMsg(QString)));

    //foreach(QString driver, drivers)
    /*QSqlDatabase db;//; = QSqlDatabase().addDatabase("QOCI");
    db.setHostName("localhost");
    db.setUserName("LRH");
    db.setPassword("orcl");
    if (db.open())
    {
        ui.textEdit->setText("666");
    }*/
}
QtWidgetsApplication2::~QtWidgetsApplication2()
{
    delete my_context;
    delete my_channel;
}


//以坐标设置中心的槽函数
void QtWidgetsApplication2::on_pushButton_clicked()
{
    QString x = ui.lineEdit->text();
    QString y = ui.lineEdit_2->text();
    QString level = ui.lineEdit_3->text();
    if (x != QString("") && y != QString(""))
    {
        ui.webEngineView->page()->runJavaScript(QString("setcenter(")+x+","+y+","+level+")");
        //
    }
}
//以名字设置中心的槽函数
void QtWidgetsApplication2::on_pushButton_2_clicked()
{
    QString name = ui.lineEdit_4->text();
    if (name != QString(""))
    {
       ui.webEngineView->page()->runJavaScript(QString("setcenterByname(")+"'"+name+ "'" +")");
    }
    
}
//重置地图的槽函数
void QtWidgetsApplication2::on_pushButton_3_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("reset()"));
}

//放大地图
void QtWidgetsApplication2::on_pushButton_4_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("zoomin()"));
}
//缩小地图
void QtWidgetsApplication2::on_pushButton_5_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("zoomout()"));
}
//显示交通流量图层
void QtWidgetsApplication2::on_pushButton_6_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("showTraffic()"));
}
//关闭交通流量图层显示
void QtWidgetsApplication2::on_pushButton_7_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("removeTraffic()"));
}
//清除覆盖物
void QtWidgetsApplication2::on_pushButton_8_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("clearOverlays()"));
    ui.lineEdit_5->setText("");
}
//接受交互类发出的位置信息信号
void  QtWidgetsApplication2::getPositionMsg(QString lng,QString lat,QString level)
{
    ui.label_10->setText(lng);
    ui.label_11->setText(lat);
    ui.label_9->setText(level);
}
//接受交互类发出的距离信息信号
void  QtWidgetsApplication2::getDistanceMsg(QString distance)
{
    ui.lineEdit_5->setText(distance);
}