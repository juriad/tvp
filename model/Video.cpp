#include "Video.h"
#include "Present.h"
#include "Colour.h"
#include "Quality.h"
#include "Aspect.h"

void Video::addPresent(Present * ele) {
  presentList.append(ele);
}
void Video::initPresent() {
  presentList = QList<Present*>();
}
void Video::addColour(Colour * ele) {
  colourList.append(ele);
}
void Video::initColour() {
  colourList = QList<Colour*>();
}
void Video::addQuality(Quality * ele) {
  qualityList.append(ele);
}
void Video::initQuality() {
  qualityList = QList<Quality*>();
}
void Video::addAspect(Aspect * ele) {
  aspectList.append(ele);
}
void Video::initAspect() {
  aspectList = QList<Aspect*>();
}
Video * Video::fromElement(QDomElement &element) {
  Video *video_ = new Video();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      video_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    video_->setAttribute(a);
  }
  return video_;
}
void Video::addSubElement( QDomElement &element) {
  if(element.localName().compare("Present", Qt::CaseInsensitive)==0) {
    Present *cn = Present::fromElement(element);
    addPresent(cn);
    return;
  }
  if(element.localName().compare("Colour", Qt::CaseInsensitive)==0) {
    Colour *cn = Colour::fromElement(element);
    addColour(cn);
    return;
  }
  if(element.localName().compare("Quality", Qt::CaseInsensitive)==0) {
    Quality *cn = Quality::fromElement(element);
    addQuality(cn);
    return;
  }
  if(element.localName().compare("Aspect", Qt::CaseInsensitive)==0) {
    Aspect *cn = Aspect::fromElement(element);
    addAspect(cn);
    return;
  }
}
void Video::setAttribute( QDomAttr &attr) {
}
QDomDocument * Video::loadXmlDocument(QFile & file) {
  if (!file.exists()) {
    qDebug() << "doesn't exist";
    return NULL;
  }
  QString errorStr;
  int errorLine;
  int errorColumn;
  QDomDocument *doc = new QDomDocument();
  if (!doc->setContent(&file, true, &errorStr, &errorLine, &errorColumn)) {
    qDebug()<< QString("Error > %1 < in file %2 on line %3, column %4").arg(
      errorStr).arg(file.fileName()).arg(errorLine).arg(errorColumn);
    delete doc;
    doc = NULL;
  }
  return doc;
}
Video  * Video::fromFile(QFile & file) {
  QDomDocument *doc = Video::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return Video::fromElement(root);
}
