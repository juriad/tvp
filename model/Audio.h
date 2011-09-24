#ifndef Audio_H_
#define Audio_H_
#include <QtCore/QtCore>
#include <QDomDocument>
#include "Present.h"
#include "Stereo.h"

class Audio {
public:
Audio() {
  initPresent();
  initStereo();
}
static Audio* fromFile( QFile &file);
static Audio* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
QList<Present*> getPresentList() {
  return presentList;
}
QList<Stereo*> getStereoList() {
  return stereoList;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
QList<Present*> presentList;
void addPresent(Present * ele);
void initPresent();
QList<Stereo*> stereoList;
void addStereo(Stereo * ele);
void initStereo();

};
#endif