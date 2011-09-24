#ifndef Length_H_
#define Length_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class Length {
public:
Length() {
  initValue();
  initUnits();
}
static Length* fromFile( QFile &file);
static Length* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
bool hasValue() {
  return hasValueValue;
}
bool isValueValid(QString input);
long long getValue() {
  return valueValue;
}
QString getRawValue() {
  return valueRawValue;
}
bool hasUnits() {
  return hasUnitsValue;
}
bool isUnitsValid(QString input);
QString getUnits() {
  return unitsValue;
}
QString getRawUnits() {
  return unitsRawValue;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
long long valueValue;
QString valueRawValue;
bool hasValueValue;
void setValue(QString input);
void initValue();
QString unitsValue;
QString unitsRawValue;
bool hasUnitsValue;
void setUnits(QString input);
void initUnits();

};
#endif