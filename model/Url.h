#ifndef Url_H_
#define Url_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class Url {
public:
Url() {
  initValue();
}
static Url* fromFile( QFile &file);
static Url* fromElement( QDomElement &element);
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