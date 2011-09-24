#include "Subtitles.h"
#include "Language.h"

bool Subtitles::isTypeValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void Subtitles::setType(QString input) {
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
void Subtitles::initType() {
  typeValue = QString();
}
void Subtitles::addLanguage(Language * ele) {
  languageList.append(ele);
}
void Subtitles::initLanguage() {
  languageList = QList<Language*>();
}
Subtitles * Subtitles::fromElement(QDomElement &element) {
  Subtitles *subtitles_ = new Subtitles();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      subtitles_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    subtitles_->setAttribute(a);
  }
  return subtitles_;
}
void Subtitles::addSubElement( QDomElement &element) {
  if(element.localName().compare("Language", Qt::CaseInsensitive)==0) {
    Language *cn = Language::fromElement(element);
    addLanguage(cn);
    return;
  }
}
void Subtitles::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("Type", Qt::CaseInsensitive)==0) {
    setType(attr.value());
    return;
  }
}
QDomDocument * Subtitles::loadXmlDocument(QFile & file) {
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
Subtitles  * Subtitles::fromFile(QFile & file) {
  QDomDocument *doc = Subtitles::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return Subtitles::fromElement(root);
}
