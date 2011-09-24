#ifndef Video_H_
#define Video_H_
#include <QtCore/QtCore>
#include <QDomDocument>
#include "Present.h"
#include "Colour.h"
#include "Quality.h"
#include "Aspect.h"

class Video {
public:
Video() {
  initPresent();
  initColour();
  initQuality();
  initAspect();
}
static Video* fromFile( QFile &file);
static Video* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
QList<Present*> getPresentList() {
  return presentList;
}
QList<Colour*> getColourList() {
  return colourList;
}
QList<Quality*> getQualityList() {
  return qualityList;
}
QList<Aspect*> getAspectList() {
  return aspectList;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
QList<Present*> presentList;
void addPresent(Present * ele);
void initPresent();
QList<Colour*> colourList;
void addColour(Colour * ele);
void initColour();
QList<Quality*> qualityList;
void addQuality(Quality * ele);
void initQuality();
QList<Aspect*> aspectList;
void addAspect(Aspect * ele);
void initAspect();

};
#endif