#include "Icon.h"

bool Icon::isSrcValid(QString input) {
  bool ok;
  ok = !input.isEmpty();
  return ok;
}
void Icon::setSrc(QString input) {
    if(input.isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  srcValue = collapsed;
  hasSrcValue = true;
  srcRawValue = input;
}
void Icon::initSrc() {
  srcValue = QString();
}
bool Icon::isWidthValid(QString input) {
  bool ok;
    QString trimmed = input.trimmed();
  if(trimmed.isEmpty()) {
    ok = false;
  } else {
    long long number = trimmed.toLongLong(&ok);
  }
  return ok;
}
void Icon::setWidth(QString input) {
    QString trimmed = input.trimmed();
  bool ok;
  if(trimmed.isEmpty()) {
    return;
  }
    long long number = trimmed.toLongLong(&ok);
  widthValue = number;
  hasWidthValue = true;
  widthRawValue = input;
}
void Icon::initWidth() {
  widthValue = 0;
}
bool Icon::isHeightValid(QString input) {
  bool ok;
    QString trimmed = input.trimmed();
  if(trimmed.isEmpty()) {
    ok = false;
  } else {
    long long number = trimmed.toLongLong(&ok);
  }
  return ok;
}
void Icon::setHeight(QString input) {
    QString trimmed = input.trimmed();
  bool ok;
  if(trimmed.isEmpty()) {
    return;
  }
    long long number = trimmed.toLongLong(&ok);
  heightValue = number;
  hasHeightValue = true;
  heightRawValue = input;
}
void Icon::initHeight() {
  heightValue = 0;
}
Icon * Icon::fromElement(QDomElement &element) {
  Icon *icon_ = new Icon();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      icon_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    icon_->setAttribute(a);
  }
  return icon_;
}
void Icon::addSubElement( QDomElement &element) {
}
void Icon::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("Src", Qt::CaseInsensitive)==0) {
    setSrc(attr.value());
    return;
  }
  if(attr.localName().compare("Width", Qt::CaseInsensitive)==0) {
    setWidth(attr.value());
    return;
  }
  if(attr.localName().compare("Height", Qt::CaseInsensitive)==0) {
    setHeight(attr.value());
    return;
  }
}
QDomDocument * Icon::loadXmlDocument(QFile & file) {
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
Icon  * Icon::fromFile(QFile & file) {
  QDomDocument *doc = Icon::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return Icon::fromElement(root);
}
