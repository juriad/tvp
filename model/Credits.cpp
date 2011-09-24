#include "Credits.h"
#include "Composer.h"
#include "Commentator.h"
#include "Writer.h"
#include "Director.h"
#include "Producer.h"
#include "Presenter.h"
#include "Actor.h"
#include "Adapter.h"
#include "Guest.h"
#include "Editor.h"

void Credits::addComposer(Composer * ele) {
  composerList.append(ele);
}
void Credits::initComposer() {
  composerList = QList<Composer*>();
}
void Credits::addCommentator(Commentator * ele) {
  commentatorList.append(ele);
}
void Credits::initCommentator() {
  commentatorList = QList<Commentator*>();
}
void Credits::addWriter(Writer * ele) {
  writerList.append(ele);
}
void Credits::initWriter() {
  writerList = QList<Writer*>();
}
void Credits::addDirector(Director * ele) {
  directorList.append(ele);
}
void Credits::initDirector() {
  directorList = QList<Director*>();
}
void Credits::addProducer(Producer * ele) {
  producerList.append(ele);
}
void Credits::initProducer() {
  producerList = QList<Producer*>();
}
void Credits::addPresenter(Presenter * ele) {
  presenterList.append(ele);
}
void Credits::initPresenter() {
  presenterList = QList<Presenter*>();
}
void Credits::addActor(Actor * ele) {
  actorList.append(ele);
}
void Credits::initActor() {
  actorList = QList<Actor*>();
}
void Credits::addAdapter(Adapter * ele) {
  adapterList.append(ele);
}
void Credits::initAdapter() {
  adapterList = QList<Adapter*>();
}
void Credits::addGuest(Guest * ele) {
  guestList.append(ele);
}
void Credits::initGuest() {
  guestList = QList<Guest*>();
}
void Credits::addEditor(Editor * ele) {
  editorList.append(ele);
}
void Credits::initEditor() {
  editorList = QList<Editor*>();
}
Credits * Credits::fromElement(QDomElement &element) {
  Credits *credits_ = new Credits();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      credits_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    credits_->setAttribute(a);
  }
  return credits_;
}
void Credits::addSubElement( QDomElement &element) {
  if(element.localName().compare("Composer", Qt::CaseInsensitive)==0) {
    Composer *cn = Composer::fromElement(element);
    addComposer(cn);
    return;
  }
  if(element.localName().compare("Commentator", Qt::CaseInsensitive)==0) {
    Commentator *cn = Commentator::fromElement(element);
    addCommentator(cn);
    return;
  }
  if(element.localName().compare("Writer", Qt::CaseInsensitive)==0) {
    Writer *cn = Writer::fromElement(element);
    addWriter(cn);
    return;
  }
  if(element.localName().compare("Director", Qt::CaseInsensitive)==0) {
    Director *cn = Director::fromElement(element);
    addDirector(cn);
    return;
  }
  if(element.localName().compare("Producer", Qt::CaseInsensitive)==0) {
    Producer *cn = Producer::fromElement(element);
    addProducer(cn);
    return;
  }
  if(element.localName().compare("Presenter", Qt::CaseInsensitive)==0) {
    Presenter *cn = Presenter::fromElement(element);
    addPresenter(cn);
    return;
  }
  if(element.localName().compare("Actor", Qt::CaseInsensitive)==0) {
    Actor *cn = Actor::fromElement(element);
    addActor(cn);
    return;
  }
  if(element.localName().compare("Adapter", Qt::CaseInsensitive)==0) {
    Adapter *cn = Adapter::fromElement(element);
    addAdapter(cn);
    return;
  }
  if(element.localName().compare("Guest", Qt::CaseInsensitive)==0) {
    Guest *cn = Guest::fromElement(element);
    addGuest(cn);
    return;
  }
  if(element.localName().compare("Editor", Qt::CaseInsensitive)==0) {
    Editor *cn = Editor::fromElement(element);
    addEditor(cn);
    return;
  }
}
void Credits::setAttribute( QDomAttr &attr) {
}
QDomDocument * Credits::loadXmlDocument(QFile & file) {
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
Credits  * Credits::fromFile(QFile & file) {
  QDomDocument *doc = Credits::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return Credits::fromElement(root);
}
