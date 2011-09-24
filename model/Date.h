#ifndef Date_H_
#define Date_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class Date {
public:
Date() {
  initValue();
}
static Date* fromFile( QFile &file);
static Date* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
bool hasValue() {
  return hasValueValue;
}
bool isValueValid(QString input);
QDateTime getValue() {
  return valueValue;
}
QString getRawValue() {
  return valueRawValue;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
QDateTime valueValue;
QString valueRawValue;
bool hasValueValue;
void setValue(QString input);
void initValue();

};
#endif