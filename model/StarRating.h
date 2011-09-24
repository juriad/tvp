#ifndef StarRating_H_
#define StarRating_H_
#include <QtCore/QtCore>
#include <QDomDocument>
#include "Icon.h"
#include "Value.h"

class StarRating {
public:
StarRating() {
  initIcon();
  initValue();
}
static StarRating* fromFile( QFile &file);
static StarRating* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
QList<Icon*> getIconList() {
  return iconList;
}
QList<Value*> getValueList() {
  return valueList;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
QList<Icon*> iconList;
void addIcon(Icon * ele);
void initIcon();
QList<Value*> valueList;
void addValue(Value * ele);
void initValue();

};
#endif