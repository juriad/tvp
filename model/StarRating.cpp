#include "StarRating.h"
#include "Icon.h"
#include "Value.h"

void StarRating::addIcon(Icon * ele) {
  iconList.append(ele);
}
void StarRating::initIcon() {
  iconList = QList<Icon*>();
}
void StarRating::addValue(Value * ele) {
  valueList.append(ele);
}
void StarRating::initValue() {
  valueList = QList<Value*>();
}
StarRating * StarRating::fromElement(QDomElement &element) {
  StarRating *starRating_ = new StarRating();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      starRating_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    starRating_->setAttribute(a);
  }
  return starRating_;
}
void StarRating::addSubElement( QDomElement &element) {
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
void StarRating::setAttribute( QDomAttr &attr) {
}
QDomDocument * StarRating::loadXmlDocument(QFile & file) {
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
StarRating  * StarRating::fromFile(QFile & file) {
  QDomDocument *doc = StarRating::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return StarRating::fromElement(root);
}
