#ifndef Actor_H_
#define Actor_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class Actor {
public:
Actor() {
  initRole();
  initValue();
}
static Actor* fromFile( QFile &file);
static Actor* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
bool hasRole() {
  return hasRoleValue;
}
bool isRoleValid(QString input);
QString getRole() {
  return roleValue;
}
QString getRawRole() {
  return roleRawValue;
}
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
QString roleValue;
QString roleRawValue;
bool hasRoleValue;
void setRole(QString input);
void initRole();
QString valueValue;
QString valueRawValue;
bool hasValueValue;
void setValue(QString input);
void initValue();

};
#endif