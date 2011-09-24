#ifndef Colour_H_
#define Colour_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class Colour {
public:
Colour() {
  initValue();
}
static Colour* fromFile( QFile &file);
static Colour* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
bool hasValue() {
  return hasValueValue;
}
bool isValueValid(QString input);
bool getValue() {
  return valueValue;
}
QString getRawValue() {
  return valueRawValue;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
bool valueValue;
QString valueRawValue;
bool hasValueValue;
void setValue(QString input);
void initValue();

};
#endif