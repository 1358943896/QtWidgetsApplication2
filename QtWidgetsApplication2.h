#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication2.h"
#include"qwebchannel.h"
#include"jscontext.h"
class QtWidgetsApplication2 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication2(QWidget *parent = Q_NULLPTR);
    ~QtWidgetsApplication2();
private:
    Ui::QtWidgetsApplication2Class ui;
    JsContext* my_context;
    QWebChannel* my_channel;
private slots:
   // void loadFinished(bool a);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void getPositionMsg(QString la,QString al,QString level);
    void getDistanceMsg(QString distance);
};
