#ifndef PreviouslyShown_H_
#define PreviouslyShown_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class PreviouslyShown {
public:
PreviouslyShown() {
  initChannel();
  initStart();
}
static PreviouslyShown* fromFile( QFile &file);
static PreviouslyShown* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
bool hasChannel() {
  return hasChannelValue;
}
bool isChannelValid(QString input);
QString getChannel() {
  return channelValue;
}
QString getRawChannel() {
  return channelRawValue;
}
bool hasStart() {
  return hasStartValue;
}
bool isStartValid(QString input);
QDateTime getStart() {
  return startValue;
}
QString getRawStart() {
  return startRawValue;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
QString channelValue;
QString channelRawValue;
bool hasChannelValue;
void setChannel(QString input);
void initChannel();
QDateTime startValue;
QString startRawValue;
bool hasStartValue;
void setStart(QString input);
void initStart();

};
#endif