#include "jscontext.h"

JsContext::JsContext(QObject* parent /*= 0*/) : QObject(parent)
{

}

void JsContext::onRecvPositionMsg(QString lng, QString lat, QString level)
{
    //发送信号
    emit set_Lng_Lat_Level(lng,lat,level);
}
void JsContext::onRecvDistanceMsg(QString distance)
{
    //发送信号
    emit send_distance_msg(distance);
}