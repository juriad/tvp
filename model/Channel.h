#ifndef Channel_H_
#define Channel_H_
#include <QtCore/QtCore>
#include <QDomDocument>
#include "DisplayName.h"
#include "Icon.h"
#include "Url.h"

class Channel {
public:
Channel() {
  initDisplayName();
  initIcon();
  initUrl();
  initId();
}
static Channel* fromFile( QFile &file);
static Channel* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
bool hasId() {
  return hasIdValue;
}
bool isIdValid(QString input);
QString getId() {
  return idValue;
}
QString getRawId() {
  return idRawValue;
}
QList<DisplayName*> getDisplayNameList() {
  return displayNameList;
}
QList<Icon*> getIconList() {
  return iconList;
}
QList<Url*> getUrlList() {
  return urlList;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
QString idValue;
QString idRawValue;
bool hasIdValue;
void setId(QString input);
void initId();
QList<DisplayName*> displayNameList;
void addDisplayName(DisplayName * ele);
void initDisplayName();
QList<Icon*> iconList;
void addIcon(Icon * ele);
void initIcon();
QList<Url*> urlList;
void addUrl(Url * ele);
void initUrl();

};
#endif