#include "QtWidgetsApplication2.h"

QtWidgetsApplication2::QtWidgetsApplication2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_button_clicked()));  //���������������ĵİ�ť����¼��Ͳ�
    connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(on_button_2_clicked()));//���������������ĵİ�ť����¼��Ͳ�
    connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(on_button_3_clicked()));//�����ð�ť����¼��Ͳ�
    connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(on_button_4_clicked()));//�󶨵�ͼ�Ŵ�ť����¼��Ͳ�
    connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(on_button_5_clicked()));//�󶨵�ͼ��С��ť����¼��Ͳ�

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
    connect(my_context,SIGNAL(set_La_Al_Level(QString, QString, QString)),this ,SLOT(getMsg(QString, QString, QString)));
}
QtWidgetsApplication2::~QtWidgetsApplication2()
{
    delete my_context;
    delete my_channel;
}


//�������������ĵĲۺ���
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
//�������������ĵĲۺ���
void QtWidgetsApplication2::on_button_2_clicked()
{
    QString name = ui.lineEdit_4->text();
    if (name != QString(""))
    {
       ui.webEngineView->page()->runJavaScript(QString("setcenterByname(")+"'"+name+ "'" +")");
    }
    
}
//���õ�ͼ�Ĳۺ���
void QtWidgetsApplication2::on_button_3_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("reset()"));
}

//�Ŵ��ͼ
void QtWidgetsApplication2::on_button_4_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("zoomin()"));
}
//��С��ͼ
void QtWidgetsApplication2::on_button_5_clicked()
{
    ui.webEngineView->page()->runJavaScript(QString("zoomout()"));
}
//��Ӧ�����෢���źŵĲۺ���
void  QtWidgetsApplication2::getMsg(QString lng,QString lat,QString level)
{
    ui.label_10->setText(lng);
    ui.label_11->setText(lat);
    ui.label_9->setText(level);
}