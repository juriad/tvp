#include "Present.h"

bool Present::isValueValid(QString input) {
  bool ok;
    ok = !input.trimmed().isEmpty();
  return ok;
}
void Present::setValue(QString input) {
    QString b = input.trimmed();
  if(b.isEmpty()) {
    return;
  }
  if(b.startsWith("t") || b.startsWith("y") || b.startsWith("1")) {
  valueValue = true;
  } else {
  valueValue = false;
  }
  hasValueValue = true;
  valueRawValue = input;
}
void Present::initValue() {
    valueValue = false;
}
Present * Present::fromElement(QDomElement &element) {
  Present *present_ = new Present();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      present_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    present_->setAttribute(a);
  }
  present_->setValue(element.text());
  return present_;
}
void Present::addSubElement( QDomElement &element) {
}
void Present::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("Value", Qt::CaseInsensitive)==0) {
    setValue(attr.value());
    return;
  }
}
QDomDocument * Present::loadXmlDocument(QFile & file) {
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
Present  * Present::fromFile(QFile & file) {
  QDomDocument *doc = Present::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return Present::fromElement(root);
}
