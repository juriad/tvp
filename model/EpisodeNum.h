#ifndef EpisodeNum_H_
#define EpisodeNum_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class EpisodeNum {
public:
EpisodeNum() {
  initSystem();
  initValue();
}
static EpisodeNum* fromFile( QFile &file);
static EpisodeNum* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
bool hasSystem() {
  return hasSystemValue;
}
bool isSystemValid(QString input);
QString getSystem() {
  return systemValue;
}
QString getRawSystem() {
  return systemRawValue;
}
bool hasValue() {
  return hasValueValue;
}
bool isValueValid(QString input);
QString getValue() {
  return valueValue;
}
QString getRawValue() {
  return valueRawValue;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
QString systemValue;
QString systemRawValue;
bool hasSystemValue;
void setSystem(QString input);
void initSystem();
QString valueValue;
QString valueRawValue;
bool hasValueValue;
void setValue(QString input);
void initValue();

};
#endif