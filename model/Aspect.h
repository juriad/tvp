#ifndef Aspect_H_
#define Aspect_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class Aspect {
public:
Aspect() {
  initValue();
}
static Aspect* fromFile( QFile &file);
static Aspect* fromElement( QDomElement &element);
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