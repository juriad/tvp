#ifndef Icon_H_
#define Icon_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class Icon {
public:
Icon() {
  initSrc();
  initWidth();
  initHeight();
}
static Icon* fromFile( QFile &file);
static Icon* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
bool hasSrc() {
  return hasSrcValue;
}
bool isSrcValid(QString input);
QString getSrc() {
  return srcValue;
}
QString getRawSrc() {
  return srcRawValue;
}
bool hasWidth() {
  return hasWidthValue;
}
bool isWidthValid(QString input);
long long getWidth() {
  return widthValue;
}
QString getRawWidth() {
  return widthRawValue;
}
bool hasHeight() {
  return hasHeightValue;
}
bool isHeightValid(QString input);
long long getHeight() {
  return heightValue;
}
QString getRawHeight() {
  return heightRawValue;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
QString srcValue;
QString srcRawValue;
bool hasSrcValue;
void setSrc(QString input);
void initSrc();
long long widthValue;
QString widthRawValue;
bool hasWidthValue;
void setWidth(QString input);
void initWidth();
long long heightValue;
QString heightRawValue;
bool hasHeightValue;
void setHeight(QString input);
void initHeight();

};
#endif