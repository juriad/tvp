#ifndef DisplayName_H_
#define DisplayName_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class DisplayName {
public:
DisplayName() {
  initValue();
  initLang();
}
static DisplayName* fromFile( QFile &file);
static DisplayName* fromElement( QDomElement &element);
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
bool hasLang() {
  return hasLangValue;
}
bool isLangValid(QString input);
QString getLang() {
  return langValue;
}
QString getRawLang() {
  return langRawValue;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
QString valueValue;
QString valueRawValue;
bool hasValueValue;
void setValue(QString input);
void initValue();
QString langValue;
QString langRawValue;
bool hasLangValue;
void setLang(QString input);
void initLang();

};
#endif