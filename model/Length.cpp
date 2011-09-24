#include "Length.h"

bool Length::isValueValid(QString input) {
  bool ok;
    QString trimmed = input.trimmed();
  if(trimmed.isEmpty()) {
    ok = false;
  } else {
    long long number = trimmed.toLongLong(&ok);
  }
  return ok;
}
void Length::setValue(QString input) {
    QString trimmed = input.trimmed();
  bool ok;
  if(trimmed.isEmpty()) {
    return;
  }
    long long number = trimmed.toLongLong(&ok);
  valueValue = number;
  hasValueValue = true;
  valueRawValue = input;
}
void Length::initValue() {
  valueValue = 0;
}
bool Length::isUnitsValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void Length::setUnits(QString input) {
    if(input.trimmed().isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  unitsValue = collapsed;
  hasUnitsValue = true;
  unitsRawValue = input;
}
void Length::initUnits() {
  unitsValue = QString();
}
Length * Length::fromElement(QDomElement &element) {
  Length *length_ = new Length();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      length_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    length_->setAttribute(a);
  }
  length_->setValue(element.text());
  return length_;
}
void Length::addSubElement( QDomElement &element) {
}
void Length::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("Value", Qt::CaseInsensitive)==0) {
    setValue(attr.value());
    return;
  }
  if(attr.localName().compare("Units", Qt::CaseInsensitive)==0) {
    setUnits(attr.value());
    return;
  }
}
QDomDocument * Length::loadXmlDocument(QFile & file) {
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
Length  * Length::fromFile(QFile & file) {
  QDomDocument *doc = Length::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return Length::fromElement(root);
}
