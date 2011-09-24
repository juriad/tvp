#include "Date.h"

bool Date::isValueValid(QString input) {
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
void Date::setValue(QString input) {
  QString normalized = input.remove(QRegExp(" [+-].*$")).remove(QRegExp("[^0-9]"));
  bool ok;
  QDateTime date_;  if(normalized.isEmpty()) {
    ok = false;
  } else {
    date_ = QDateTime::fromString(normalized, QString("yyyyMMddHHmmss").left(normalized.length()));
    ok = date_.isValid();
  }  if(ok) {
    valueValue = date_;
  } else {
    return;
  }
  hasValueValue = true;
  valueRawValue = input;
}
void Date::initValue() {
  valueValue = QDateTime();
}
Date * Date::fromElement(QDomElement &element) {
  Date *date_ = new Date();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      date_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    date_->setAttribute(a);
  }
  date_->setValue(element.text());
  return date_;
}
void Date::addSubElement( QDomElement &element) {
}
void Date::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("Value", Qt::CaseInsensitive)==0) {
    setValue(attr.value());
    return;
  }
}
QDomDocument * Date::loadXmlDocument(QFile & file) {
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
Date  * Date::fromFile(QFile & file) {
  QDomDocument *doc = Date::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return Date::fromElement(root);
}
