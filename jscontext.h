#ifndef JSCONTEXT_H
#define JSCONTEXT_H

#include <QObject>


//c++与前端js的交互类 通过此类传递数据
class JsContext : public QObject
{
    Q_OBJECT

public:
    JsContext(QObject* parent = 0);
    ~JsContext() {}

signals:
    //自身信号 将从前端接收的消息发出
    void set_Lng_Lat_Level(QString la,QString al,QString level);
signals:
    void send_distance_msg(QString distance);
public slots:
    //用于接收消息的接口必须定义为public slots：，以供js调用
    // 接收前端js发送来的消息
    void onRecvPositionMsg(QString lng, QString lat, QString level);
    void onRecvDistanceMsg(QString distance);
};
#endif // JSCONTEXT_H