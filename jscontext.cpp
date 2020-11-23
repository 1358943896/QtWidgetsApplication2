#include "jscontext.h"

JsContext::JsContext(QObject* parent /*= 0*/) : QObject(parent)
{

}

void JsContext::onRecvPositionMsg(QString lng, QString lat, QString level)
{
    //�����ź�
    emit set_Lng_Lat_Level(lng,lat,level);
}
void JsContext::onRecvDistanceMsg(QString distance)
{
    //�����ź�
    emit send_distance_msg(distance);
}