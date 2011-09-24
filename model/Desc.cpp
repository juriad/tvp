#include "Desc.h"

bool Desc::isValueValid(QString input) {
  bool ok;
  ok = !input.isEmpty();
  return ok;
}
void Desc::setValue(QString input) {
    if(input.isEmpty()) {
    return;
  }
  valueValue = input;
  hasValueValue = true;
  valueRawValue = input;
}
void Desc::initValue() {
  valueValue = QString();
}
bool Desc::isLangValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void Desc::setLang(QString input) {
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
void Desc::initLang() {
  langValue = QString();
}
Desc * Desc::fromElement(QDomElement &element) {
  Desc *desc_ = new Desc();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      desc_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    desc_->setAttribute(a);
  }
  desc_->setValue(element.text());
  return desc_;
}
void Desc::addSubElement( QDomElement &element) {
}
void Desc::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("Value", Qt::CaseInsensitive)==0) {
    setValue(attr.value());
    return;
  }
  if(attr.localName().compare("Lang", Qt::CaseInsensitive)==0) {
    setLang(attr.value());
    return;
  }
}
QDomDocument * Desc::loadXmlDocument(QFile & file) {
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
Desc  * Desc::fromFile(QFile & file) {
  QDomDocument *doc = Desc::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return Desc::fromElement(root);
}
