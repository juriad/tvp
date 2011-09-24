#include "Rating.h"
#include "Icon.h"
#include "Value.h"

bool Rating::isSystemValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void Rating::setSystem(QString input) {
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
void Rating::initSystem() {
  systemValue = QString();
}
void Rating::addIcon(Icon * ele) {
  iconList.append(ele);
}
void Rating::initIcon() {
  iconList = QList<Icon*>();
}
void Rating::addValue(Value * ele) {
  valueList.append(ele);
}
void Rating::initValue() {
  valueList = QList<Value*>();
}
Rating * Rating::fromElement(QDomElement &element) {
  Rating *rating_ = new Rating();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      rating_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    rating_->setAttribute(a);
  }
  return rating_;
}
void Rating::addSubElement( QDomElement &element) {
  if(element.localName().compare("Icon", Qt::CaseInsensitive)==0) {
    Icon *cn = Icon::fromElement(element);
    addIcon(cn);
    return;
  }
  if(element.localName().compare("Value", Qt::CaseInsensitive)==0) {
    Value *cn = Value::fromElement(element);
    addValue(cn);
    return;
  }
}
void Rating::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("System", Qt::CaseInsensitive)==0) {
    setSystem(attr.value());
    return;
  }
}
QDomDocument * Rating::loadXmlDocument(QFile & file) {
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
Rating  * Rating::fromFile(QFile & file) {
  QDomDocument *doc = Rating::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return Rating::fromElement(root);
}
