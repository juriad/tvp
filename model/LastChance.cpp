#include "LastChance.h"

bool LastChance::isValueValid(QString input) {
  bool ok;
  ok = !input.isEmpty();
  return ok;
}
void LastChance::setValue(QString input) {
    if(input.isEmpty()) {
    return;
  }
  valueValue = input;
  hasValueValue = true;
  valueRawValue = input;
}
void LastChance::initValue() {
  valueValue = QString();
}
bool LastChance::isLangValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void LastChance::setLang(QString input) {
    if(input.trimmed().isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  langValue = collapsed;
  hasLangValue = true;
  langRawValue = input;
}
void LastChance::initLang() {
  langValue = QString();
}
LastChance * LastChance::fromElement(QDomElement &element) {
  LastChance *lastChance_ = new LastChance();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      lastChance_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    lastChance_->setAttribute(a);
  }
  lastChance_->setValue(element.text());
  return lastChance_;
}
void LastChance::addSubElement( QDomElement &element) {
}
void LastChance::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("Value", Qt::CaseInsensitive)==0) {
    setValue(attr.value());
    return;
  }
  if(attr.localName().compare("Lang", Qt::CaseInsensitive)==0) {
    setLang(attr.value());
    return;
  }
}
QDomDocument * LastChance::loadXmlDocument(QFile & file) {
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
LastChance  * LastChance::fromFile(QFile & file) {
  QDomDocument *doc = LastChance::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return LastChance::fromElement(root);
}
