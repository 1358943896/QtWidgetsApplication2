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
    void resetUI();
private:
    Ui::QtWidgetsApplication2Class ui;
private slots:
   // void loadFinished(bool a);
    void on_button_clicked();
    void on_button_2_clicked();
    void on_button_3_clicked();
    void on_button_4_clicked();
    void on_button_5_clicked();
    void getMsg(QString la,QString al,QString level);
};
