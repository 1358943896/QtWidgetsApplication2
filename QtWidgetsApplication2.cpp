#include "QtWidgetsApplication2.h"

QtWidgetsApplication2::QtWidgetsApplication2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_button_clicked()));  //绑定以坐标设置中心的按钮点击事件和槽
    connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(on_button_2_clicked()));//绑定以名字设置中心的按钮点击事件和槽
    connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(on_button_3_clicked()));//绑定重置按钮点击事件和槽
    connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(on_button_4_clicked()));//绑定地图放大按钮点击事件和槽
    connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(on_button_5_clicked()));//绑定地图缩小按钮点击事件和槽

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
    connect(my_context,SIGNAL(set_La_Al_Level(QString, QString, QString)),this ,SLOT(getMsg(QString, QString, QString)));
}
QtWidgetsApplication2::~QtWidgetsApplication2()
{
    delete my_context;
    delete my_channel;
}


//以坐标设置中心的槽函数
void QtWidgetsApplication2::on_button_clicked()
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
void QtWidgetsApplication2::on_button_2_clicked()
{
    QString name = ui.lineEdit_4->text();
    if (name != QString(""))
    {
       ui.webEngineView->page()->runJavaScript(QString("setcenterByname(")+"'"+name+ "'" +")");
    }
    
}
//重置地图的槽函数
void QtWidgetsApplication2::on_button_3_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("reset()"));
}

//放大地图
void QtWidgetsApplication2::on_button_4_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("zoomin()"));
}
//缩小地图
void QtWidgetsApplication2::on_button_5_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("zoomout()"));
}
//响应交互类发出信号的槽函数
void  QtWidgetsApplication2::getMsg(QString lng,QString lat,QString level)
{
    ui.label_10->setText(lng);
    ui.label_11->setText(lat);
    ui.label_9->setText(level);
}