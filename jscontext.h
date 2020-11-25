#ifndef JSCONTEXT_H
#define JSCONTEXT_H

#include <QObject>


//c++��ǰ��js�Ľ����� ͨ�����ഫ������
class JsContext : public QObject
{
    Q_OBJECT

public:
    JsContext(QObject* parent = 0);
    ~JsContext() {}

signals:
    //�����ź� ����ǰ�˽��յ���Ϣ����
    void set_Lng_Lat_Level(QString la,QString al,QString level);
signals:
    void send_distance_msg(QString distance);
public slots:
    //���ڽ�����Ϣ�Ľӿڱ��붨��Ϊpublic slots�����Թ�js����
    // ����ǰ��js����������Ϣ
    void onRecvPositionMsg(QString lng, QString lat, QString level);
    void onRecvDistanceMsg(QString distance);
};
#endif // JSCONTEXT_H