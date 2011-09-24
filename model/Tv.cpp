#include "Tv.h"
#include "Programme.h"
#include "Channel.h"

bool Tv::isSourceInfoUrlValid(QString input) {
  bool ok;
  ok = !input.isEmpty();
  return ok;
}
void Tv::setSourceInfoUrl(QString input) {
    if(input.isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  sourceInfoUrlValue = collapsed;
  hasSourceInfoUrlValue = true;
  sourceInfoUrlRawValue = input;
}
void Tv::initSourceInfoUrl() {
  sourceInfoUrlValue = QString();
}
bool Tv::isSourceDataUrlValid(QString input) {
  bool ok;
  ok = !input.isEmpty();
  return ok;
}
void Tv::setSourceDataUrl(QString input) {
    if(input.isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  sourceDataUrlValue = collapsed;
  hasSourceDataUrlValue = true;
  sourceDataUrlRawValue = input;
}
void Tv::initSourceDataUrl() {
  sourceDataUrlValue = QString();
}
bool Tv::isDateValid(QString input) {
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
void Tv::setDate(QString input) {
  QString normalized = input.remove(QRegExp(" [+-].*$")).remove(QRegExp("[^0-9]"));
  bool ok;
  QDateTime date_;  if(normalized.isEmpty()) {
    ok = false;
  } else {
    date_ = QDateTime::fromString(normalized, QString("yyyyMMddHHmmss").left(normalized.length()));
    ok = date_.isValid();
  }  if(ok) {
    dateValue = date_;
  } else {
    return;
  }
  hasDateValue = true;
  dateRawValue = input;
}
void Tv::initDate() {
  dateValue = QDateTime();
}
bool Tv::isGeneratorInfoNameValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void Tv::setGeneratorInfoName(QString input) {
    if(input.trimmed().isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  generatorInfoNameValue = collapsed;
  hasGeneratorInfoNameValue = true;
  generatorInfoNameRawValue = input;
}
void Tv::initGeneratorInfoName() {
  generatorInfoNameValue = QString();
}
bool Tv::isSourceInfoNameValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void Tv::setSourceInfoName(QString input) {
    if(input.trimmed().isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  sourceInfoNameValue = collapsed;
  hasSourceInfoNameValue = true;
  sourceInfoNameRawValue = input;
}
void Tv::initSourceInfoName() {
  sourceInfoNameValue = QString();
}
bool Tv::isGeneratorInfoUrlValid(QString input) {
  bool ok;
  ok = !input.isEmpty();
  return ok;
}
void Tv::setGeneratorInfoUrl(QString input) {
    if(input.isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  generatorInfoUrlValue = collapsed;
  hasGeneratorInfoUrlValue = true;
  generatorInfoUrlRawValue = input;
}
void Tv::initGeneratorInfoUrl() {
  generatorInfoUrlValue = QString();
}
void Tv::addProgramme(Programme * ele) {
  programmeList.append(ele);
}
void Tv::initProgramme() {
  programmeList = QList<Programme*>();
}
void Tv::addChannel(Channel * ele) {
  channelList.append(ele);
}
void Tv::initChannel() {
  channelList = QList<Channel*>();
}
Tv * Tv::fromElement(QDomElement &element) {
  Tv *tv_ = new Tv();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      tv_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    tv_->setAttribute(a);
  }
  return tv_;
}
void Tv::addSubElement( QDomElement &element) {
  if(element.localName().compare("Programme", Qt::CaseInsensitive)==0) {
    Programme *cn = Programme::fromElement(element);
    addProgramme(cn);
    return;
  }
  if(element.localName().compare("Channel", Qt::CaseInsensitive)==0) {
    Channel *cn = Channel::fromElement(element);
    addChannel(cn);
    return;
  }
}
void Tv::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("SourceInfoUrl", Qt::CaseInsensitive)==0) {
    setSourceInfoUrl(attr.value());
    return;
  }
  if(attr.localName().compare("SourceDataUrl", Qt::CaseInsensitive)==0) {
    setSourceDataUrl(attr.value());
    return;
  }
  if(attr.localName().compare("Date", Qt::CaseInsensitive)==0) {
    setDate(attr.value());
    return;
  }
  if(attr.localName().compare("GeneratorInfoName", Qt::CaseInsensitive)==0) {
    setGeneratorInfoName(attr.value());
    return;
  }
  if(attr.localName().compare("SourceInfoName", Qt::CaseInsensitive)==0) {
    setSourceInfoName(attr.value());
    return;
  }
  if(attr.localName().compare("GeneratorInfoUrl", Qt::CaseInsensitive)==0) {
    setGeneratorInfoUrl(attr.value());
    return;
  }
}
QDomDocument * Tv::loadXmlDocument(QFile & file) {
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
Tv  * Tv::fromFile(QFile & file) {
  QDomDocument *doc = Tv::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return Tv::fromElement(root);
}
