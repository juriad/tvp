#include "PreviouslyShown.h"

bool PreviouslyShown::isChannelValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void PreviouslyShown::setChannel(QString input) {
    if(input.trimmed().isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  channelValue = collapsed;
  hasChannelValue = true;
  channelRawValue = input;
}
void PreviouslyShown::initChannel() {
  channelValue = QString();
}
bool PreviouslyShown::isStartValid(QString input) {
  bool ok;
    QString normalized = input.remove(QRegExp(" [+-].*$")).remove(QRegExp("[^0-9]"));
  if(normalized.isEmpty()) {
    ok = false;
  } else {
    QDateTime date_ = QDateTime::fromString(normalized, QString("yyyyMMddHHmmss").left(normalized.length()));
    ok = date_.isValid();
  }
  return ok;
}
void PreviouslyShown::setStart(QString input) {
  QString normalized = input.remove(QRegExp(" [+-].*$")).remove(QRegExp("[^0-9]"));
  bool ok;
  QDateTime date_;  if(normalized.isEmpty()) {
    ok = false;
  } else {
    date_ = QDateTime::fromString(normalized, QString("yyyyMMddHHmmss").left(normalized.length()));
    ok = date_.isValid();
  }  if(ok) {
    startValue = date_;
  } else {
    return;
  }
  hasStartValue = true;
  startRawValue = input;
}
void PreviouslyShown::initStart() {
  startValue = QDateTime();
}
PreviouslyShown * PreviouslyShown::fromElement(QDomElement &element) {
  PreviouslyShown *previouslyShown_ = new PreviouslyShown();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      previouslyShown_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    previouslyShown_->setAttribute(a);
  }
  return previouslyShown_;
}
void PreviouslyShown::addSubElement( QDomElement &element) {
}
void PreviouslyShown::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("Channel", Qt::CaseInsensitive)==0) {
    setChannel(attr.value());
    return;
  }
  if(attr.localName().compare("Start", Qt::CaseInsensitive)==0) {
    setStart(attr.value());
    return;
  }
}
QDomDocument * PreviouslyShown::loadXmlDocument(QFile & file) {
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
PreviouslyShown  * PreviouslyShown::fromFile(QFile & file) {
  QDomDocument *doc = PreviouslyShown::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return PreviouslyShown::fromElement(root);
}
