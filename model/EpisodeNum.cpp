#include "EpisodeNum.h"

bool EpisodeNum::isSystemValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void EpisodeNum::setSystem(QString input) {
    if(input.trimmed().isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  systemValue = collapsed;
  hasSystemValue = true;
  systemRawValue = input;
}
void EpisodeNum::initSystem() {
  systemValue = QString();
  setSystem("onscreen");
}
bool EpisodeNum::isValueValid(QString input) {
  bool ok;
  ok = !input.isEmpty();
  return ok;
}
void EpisodeNum::setValue(QString input) {
    if(input.isEmpty()) {
    return;
  }
  valueValue = input;
  hasValueValue = true;
  valueRawValue = input;
}
void EpisodeNum::initValue() {
  valueValue = QString();
}
EpisodeNum * EpisodeNum::fromElement(QDomElement &element) {
  EpisodeNum *episodeNum_ = new EpisodeNum();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      episodeNum_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    episodeNum_->setAttribute(a);
  }
  episodeNum_->setValue(element.text());
  return episodeNum_;
}
void EpisodeNum::addSubElement( QDomElement &element) {
}
void EpisodeNum::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("System", Qt::CaseInsensitive)==0) {
    setSystem(attr.value());
    return;
  }
  if(attr.localName().compare("Value", Qt::CaseInsensitive)==0) {
    setValue(attr.value());
    return;
  }
}
QDomDocument * EpisodeNum::loadXmlDocument(QFile & file) {
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
EpisodeNum  * EpisodeNum::fromFile(QFile & file) {
  QDomDocument *doc = EpisodeNum::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return EpisodeNum::fromElement(root);
}
