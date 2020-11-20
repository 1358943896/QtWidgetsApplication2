#ifndef JSCONTEXT_H
#define JSCONTEXT_H

#include <QObject>
#include <QWebEnginePage>

//c++��ǰ��js�Ľ����� ͨ�����ഫ������
class JsContext : public QObject
{
    Q_OBJECT

public:
    JsContext(QObject* parent = 0);
    ~JsContext() {}

signals:
    //�����ź� ����ǰ�˽��յ���Ϣ����
    void set_La_Al_Level(QString la,QString al,QString level);

public slots:
    //���ڽ�����Ϣ�Ľӿڱ��붨��Ϊpublic slots�����Թ�js����
    // ����ǰ��js����������Ϣ
    void onRecvMsg(QString lng, QString lat, QString level);
};
#endif // JSCONTEXT_H