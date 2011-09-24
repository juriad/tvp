#ifndef Credits_H_
#define Credits_H_
#include <QtCore/QtCore>
#include <QDomDocument>
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

class Credits {
public:
Credits() {
  initComposer();
  initCommentator();
  initWriter();
  initDirector();
  initProducer();
  initPresenter();
  initActor();
  initAdapter();
  initGuest();
  initEditor();
}
static Credits* fromFile( QFile &file);
static Credits* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
QList<Composer*> getComposerList() {
  return composerList;
}
QList<Commentator*> getCommentatorList() {
  return commentatorList;
}
QList<Writer*> getWriterList() {
  return writerList;
}
QList<Director*> getDirectorList() {
  return directorList;
}
QList<Producer*> getProducerList() {
  return producerList;
}
QList<Presenter*> getPresenterList() {
  return presenterList;
}
QList<Actor*> getActorList() {
  return actorList;
}
QList<Adapter*> getAdapterList() {
  return adapterList;
}
QList<Guest*> getGuestList() {
  return guestList;
}
QList<Editor*> getEditorList() {
  return editorList;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
QList<Composer*> composerList;
void addComposer(Composer * ele);
void initComposer();
QList<Commentator*> commentatorList;
void addCommentator(Commentator * ele);
void initCommentator();
QList<Writer*> writerList;
void addWriter(Writer * ele);
void initWriter();
QList<Director*> directorList;
void addDirector(Director * ele);
void initDirector();
QList<Producer*> producerList;
void addProducer(Producer * ele);
void initProducer();
QList<Presenter*> presenterList;
void addPresenter(Presenter * ele);
void initPresenter();
QList<Actor*> actorList;
void addActor(Actor * ele);
void initActor();
QList<Adapter*> adapterList;
void addAdapter(Adapter * ele);
void initAdapter();
QList<Guest*> guestList;
void addGuest(Guest * ele);
void initGuest();
QList<Editor*> editorList;
void addEditor(Editor * ele);
void initEditor();

};
#endif