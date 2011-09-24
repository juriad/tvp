#include "OrigLanguage.h"

bool OrigLanguage::isValueValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void OrigLanguage::setValue(QString input) {
    if(input.trimmed().isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  valueValue = collapsed;
  hasValueValue = true;
  valueRawValue = input;
}
void OrigLanguage::initValue() {
  valueValue = QString();
}
bool OrigLanguage::isLangValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void OrigLanguage::setLang(QString input) {
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
void OrigLanguage::initLang() {
  langValue = QString();
}
OrigLanguage * OrigLanguage::fromElement(QDomElement &element) {
  OrigLanguage *origLanguage_ = new OrigLanguage();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      origLanguage_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    origLanguage_->setAttribute(a);
  }
  origLanguage_->setValue(element.text());
  return origLanguage_;
}
void OrigLanguage::addSubElement( QDomElement &element) {
}
void OrigLanguage::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("Value", Qt::CaseInsensitive)==0) {
    setValue(attr.value());
    return;
  }
  if(attr.localName().compare("Lang", Qt::CaseInsensitive)==0) {
    setLang(attr.value());
    return;
  }
}
QDomDocument * OrigLanguage::loadXmlDocument(QFile & file) {
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
OrigLanguage  * OrigLanguage::fromFile(QFile & file) {
  QDomDocument *doc = OrigLanguage::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return OrigLanguage::fromElement(root);
}
