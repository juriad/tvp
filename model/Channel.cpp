#include "Channel.h"
#include "DisplayName.h"
#include "Icon.h"
#include "Url.h"

bool Channel::isIdValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void Channel::setId(QString input) {
    if(input.trimmed().isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  idValue = collapsed;
  hasIdValue = true;
  idRawValue = input;
}
void Channel::initId() {
  idValue = QString();
}
void Channel::addDisplayName(DisplayName * ele) {
  displayNameList.append(ele);
}
void Channel::initDisplayName() {
  displayNameList = QList<DisplayName*>();
}
void Channel::addIcon(Icon * ele) {
  iconList.append(ele);
}
void Channel::initIcon() {
  iconList = QList<Icon*>();
}
void Channel::addUrl(Url * ele) {
  urlList.append(ele);
}
void Channel::initUrl() {
  urlList = QList<Url*>();
}
Channel * Channel::fromElement(QDomElement &element) {
  Channel *channel_ = new Channel();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      channel_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    channel_->setAttribute(a);
  }
  return channel_;
}
void Channel::addSubElement( QDomElement &element) {
  if(element.localName().compare("DisplayName", Qt::CaseInsensitive)==0) {
    DisplayName *cn = DisplayName::fromElement(element);
    addDisplayName(cn);
    return;
  }
  if(element.localName().compare("Icon", Qt::CaseInsensitive)==0) {
    Icon *cn = Icon::fromElement(element);
    addIcon(cn);
    return;
  }
  if(element.localName().compare("Url", Qt::CaseInsensitive)==0) {
    Url *cn = Url::fromElement(element);
    addUrl(cn);
    return;
  }
}
void Channel::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("Id", Qt::CaseInsensitive)==0) {
    setId(attr.value());
    return;
  }
}
QDomDocument * Channel::loadXmlDocument(QFile & file) {
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
Channel  * Channel::fromFile(QFile & file) {
  QDomDocument *doc = Channel::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return Channel::fromElement(root);
}
