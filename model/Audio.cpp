#include "Audio.h"
#include "Present.h"
#include "Stereo.h"

void Audio::addPresent(Present * ele) {
  presentList.append(ele);
}
void Audio::initPresent() {
  presentList = QList<Present*>();
}
void Audio::addStereo(Stereo * ele) {
  stereoList.append(ele);
}
void Audio::initStereo() {
  stereoList = QList<Stereo*>();
}
Audio * Audio::fromElement(QDomElement &element) {
  Audio *audio_ = new Audio();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      audio_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    audio_->setAttribute(a);
  }
  return audio_;
}
void Audio::addSubElement( QDomElement &element) {
  if(element.localName().compare("Present", Qt::CaseInsensitive)==0) {
    Present *cn = Present::fromElement(element);
    addPresent(cn);
    return;
  }
  if(element.localName().compare("Stereo", Qt::CaseInsensitive)==0) {
    Stereo *cn = Stereo::fromElement(element);
    addStereo(cn);
    return;
  }
}
void Audio::setAttribute( QDomAttr &attr) {
}
QDomDocument * Audio::loadXmlDocument(QFile & file) {
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
Audio  * Audio::fromFile(QFile & file) {
  QDomDocument *doc = Audio::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return Audio::fromElement(root);
}
