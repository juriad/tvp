#ifndef Guest_H_
#define Guest_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class Guest {
public:
Guest() {
  initValue();
}
static Guest* fromFile( QFile &file);
static Guest* fromElement( QDomElement &element);
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