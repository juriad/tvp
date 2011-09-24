#include "DisplayName.h"

bool DisplayName::isValueValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void DisplayName::setValue(QString input) {
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
void DisplayName::initValue() {
  valueValue = QString();
}
bool DisplayName::isLangValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void DisplayName::setLang(QString input) {
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
void DisplayName::initLang() {
  langValue = QString();
}
DisplayName * DisplayName::fromElement(QDomElement &element) {
  DisplayName *displayName_ = new DisplayName();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      displayName_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    displayName_->setAttribute(a);
  }
  displayName_->setValue(element.text());
  return displayName_;
}
void DisplayName::addSubElement( QDomElement &element) {
}
void DisplayName::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("Value", Qt::CaseInsensitive)==0) {
    setValue(attr.value());
    return;
  }
  if(attr.localName().compare("Lang", Qt::CaseInsensitive)==0) {
    setLang(attr.value());
    return;
  }
}
QDomDocument * DisplayName::loadXmlDocument(QFile & file) {
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
DisplayName  * DisplayName::fromFile(QFile & file) {
  QDomDocument *doc = DisplayName::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return DisplayName::fromElement(root);
}
