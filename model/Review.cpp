#include "Review.h"

bool Review::isReviewerValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void Review::setReviewer(QString input) {
    if(input.trimmed().isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  reviewerValue = collapsed;
  hasReviewerValue = true;
  reviewerRawValue = input;
}
void Review::initReviewer() {
  reviewerValue = QString();
}
bool Review::isTypeValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void Review::setType(QString input) {
    if(input.trimmed().isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  typeValue = collapsed;
  hasTypeValue = true;
  typeRawValue = input;
}
void Review::initType() {
  typeValue = QString();
}
bool Review::isSourceValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void Review::setSource(QString input) {
    if(input.trimmed().isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  sourceValue = collapsed;
  hasSourceValue = true;
  sourceRawValue = input;
}
void Review::initSource() {
  sourceValue = QString();
}
bool Review::isValueValid(QString input) {
  bool ok;
  ok = !input.isEmpty();
  return ok;
}
void Review::setValue(QString input) {
    if(input.isEmpty()) {
    return;
  }
  valueValue = input;
  hasValueValue = true;
  valueRawValue = input;
}
void Review::initValue() {
  valueValue = QString();
}
Review * Review::fromElement(QDomElement &element) {
  Review *review_ = new Review();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      review_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    review_->setAttribute(a);
  }
  review_->setValue(element.text());
  return review_;
}
void Review::addSubElement( QDomElement &element) {
}
void Review::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("Reviewer", Qt::CaseInsensitive)==0) {
    setReviewer(attr.value());
    return;
  }
  if(attr.localName().compare("Type", Qt::CaseInsensitive)==0) {
    setType(attr.value());
    return;
  }
  if(attr.localName().compare("Source", Qt::CaseInsensitive)==0) {
    setSource(attr.value());
    return;
  }
  if(attr.localName().compare("Value", Qt::CaseInsensitive)==0) {
    setValue(attr.value());
    return;
  }
}
QDomDocument * Review::loadXmlDocument(QFile & file) {
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
Review  * Review::fromFile(QFile & file) {
  QDomDocument *doc = Review::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return Review::fromElement(root);
}
