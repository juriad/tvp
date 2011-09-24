#include "Premiere.h"

bool Premiere::isValueValid(QString input) {
  bool ok;
  ok = !input.isEmpty();
  return ok;
}
void Premiere::setValue(QString input) {
    if(input.isEmpty()) {
    return;
  }
  valueValue = input;
  hasValueValue = true;
  valueRawValue = input;
}
void Premiere::initValue() {
  valueValue = QString();
}
bool Premiere::isLangValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void Premiere::setLang(QString input) {
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
void Premiere::initLang() {
  langValue = QString();
}
Premiere * Premiere::fromElement(QDomElement &element) {
  Premiere *premiere_ = new Premiere();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      premiere_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    premiere_->setAttribute(a);
  }
  premiere_->setValue(element.text());
  return premiere_;
}
void Premiere::addSubElement( QDomElement &element) {
}
void Premiere::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("Value", Qt::CaseInsensitive)==0) {
    setValue(attr.value());
    return;
  }
  if(attr.localName().compare("Lang", Qt::CaseInsensitive)==0) {
    setLang(attr.value());
    return;
  }
}
QDomDocument * Premiere::loadXmlDocument(QFile & file) {
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
Premiere  * Premiere::fromFile(QFile & file) {
  QDomDocument *doc = Premiere::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return Premiere::fromElement(root);
}
