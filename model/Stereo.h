#ifndef Stereo_H_
#define Stereo_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class Stereo {
public:
Stereo() {
  initValue();
}
static Stereo* fromFile( QFile &file);
static Stereo* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
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
QString valueValue;
QString valueRawValue;
bool hasValueValue;
void setValue(QString input);
void initValue();

};
#endif