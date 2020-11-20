#include "jscontext.h"

JsContext::JsContext(QObject* parent /*= 0*/) : QObject(parent)
{

}

void JsContext::onRecvMsg(QString lng, QString lat, QString level)
{
    //·¢ËÍÐÅºÅ
    emit set_La_Al_Level(lng,lat,level);
}
