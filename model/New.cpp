#include "New.h"

New * New::fromElement(QDomElement &element) {
  New *new_ = new New();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      new_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    new_->setAttribute(a);
  }
  return new_;
}
void New::addSubElement( QDomElement &element) {
}
void New::setAttribute( QDomAttr &attr) {
}
QDomDocument * New::loadXmlDocument(QFile & file) {
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
New  * New::fromFile(QFile & file) {
  QDomDocument *doc = New::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return New::fromElement(root);
}
