#ifndef Composer_H_
#define Composer_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class Composer {
public:
Composer() {
  initValue();
}
static Composer* fromFile( QFile &file);
static Composer* fromElement( QDomElement &element);
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