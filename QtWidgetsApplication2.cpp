#include "QtWidgetsApplication2.h"
#include "QtCore/qmetaobject.h"
QtWidgetsApplication2::QtWidgetsApplication2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    /*connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));  //���������������ĵİ�ť����¼��Ͳ�
    connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));//���������������ĵİ�ť����¼��Ͳ�
    connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushButton_3_clicked()));//�����ð�ť����¼��Ͳ�
    connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(on_pushButton_4_clicked()));//�󶨵�ͼ�Ŵ�ť����¼��Ͳ�
    connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(on_pushButton_5_clicked()));//�󶨵�ͼ��С��ť����¼��Ͳ�
    connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(on_pushButton_6_clicked()));//��ʾ��ͨ����ͼ��
    //connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(on_button_7_clicked()));//�رս�ͨ����ͼ����ʾ*/
    QMetaObject().connectSlotsByName(this);
    
    
    //
   
    //ʵ�������������
    my_context = new JsContext(this);
    //ʵ����QWebChannel����
    my_channel = new QWebChannel(this);
    //�����������ע�ᵽQWebChannel������
    my_channel->registerObject("context_qt", my_context);
    //���ÿؼ���QWebChannel
    ui.webEngineView->page()->setWebChannel(my_channel);
    //�󶨽�����Ĵ�����Ϣ���źźͲ�
    connect(my_context,SIGNAL(set_Lng_Lat_Level(QString, QString, QString)),this ,SLOT(getPositionMsg(QString, QString, QString)));
    connect(my_context, SIGNAL(send_distance_msg(QString)), this, SLOT(getDistanceMsg(QString)));
}
QtWidgetsApplication2::~QtWidgetsApplication2()
{
    delete my_context;
    delete my_channel;
}


//�������������ĵĲۺ���
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
//�������������ĵĲۺ���
void QtWidgetsApplication2::on_pushButton_2_clicked()
{
    QString name = ui.lineEdit_4->text();
    if (name != QString(""))
    {
       ui.webEngineView->page()->runJavaScript(QString("setcenterByname(")+"'"+name+ "'" +")");
    }
    
}
//���õ�ͼ�Ĳۺ���
void QtWidgetsApplication2::on_pushButton_3_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("reset()"));
}

//�Ŵ��ͼ
void QtWidgetsApplication2::on_pushButton_4_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("zoomin()"));
}
//��С��ͼ
void QtWidgetsApplication2::on_pushButton_5_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("zoomout()"));
}
//��ʾ��ͨ����ͼ��
void QtWidgetsApplication2::on_pushButton_6_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("showTraffic()"));
}
//�رս�ͨ����ͼ����ʾ
void QtWidgetsApplication2::on_pushButton_7_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("removeTraffic()"));
}
//���������
void QtWidgetsApplication2::on_pushButton_8_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("clearOverlays()"));
    ui.lineEdit_5->setText("");
}
//���ܽ����෢����λ����Ϣ�ź�
void  QtWidgetsApplication2::getPositionMsg(QString lng,QString lat,QString level)
{
    ui.label_10->setText(lng);
    ui.label_11->setText(lat);
    ui.label_9->setText(level);
}
//���ܽ����෢���ľ�����Ϣ�ź�
void  QtWidgetsApplication2::getDistanceMsg(QString distance)
{
    ui.lineEdit_5->setText(distance);
}