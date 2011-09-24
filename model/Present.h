#ifndef Present_H_
#define Present_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class Present {
public:
Present() {
  initValue();
}
static Present* fromFile( QFile &file);
static Present* fromElement( QDomElement &element);
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