#ifndef Rating_H_
#define Rating_H_
#include <QtCore/QtCore>
#include <QDomDocument>
#include "Icon.h"
#include "Value.h"

class Rating {
public:
Rating() {
  initIcon();
  initValue();
  initSystem();
}
static Rating* fromFile( QFile &file);
static Rating* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
bool hasSystem() {
  return hasSystemValue;
}
bool isSystemValid(QString input);
QString getSystem() {
  return systemValue;
}
QString getRawSystem() {
  return systemRawValue;
}
QList<Icon*> getIconList() {
  return iconList;
}
QList<Value*> getValueList() {
  return valueList;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
QString systemValue;
QString systemRawValue;
bool hasSystemValue;
void setSystem(QString input);
void initSystem();
QList<Icon*> iconList;
void addIcon(Icon * ele);
void initIcon();
QList<Value*> valueList;
void addValue(Value * ele);
void initValue();

};
#endif