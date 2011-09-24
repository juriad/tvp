#ifndef Producer_H_
#define Producer_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class Producer {
public:
Producer() {
  initValue();
}
static Producer* fromFile( QFile &file);
static Producer* fromElement( QDomElement &element);
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