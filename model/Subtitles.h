#ifndef Subtitles_H_
#define Subtitles_H_
#include <QtCore/QtCore>
#include <QDomDocument>
#include "Language.h"

class Subtitles {
public:
Subtitles() {
  initLanguage();
  initType();
}
static Subtitles* fromFile( QFile &file);
static Subtitles* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
bool hasType() {
  return hasTypeValue;
}
bool isTypeValid(QString input);
QString getType() {
  return typeValue;
}
QString getRawType() {
  return typeRawValue;
}
QList<Language*> getLanguageList() {
  return languageList;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
QString typeValue;
QString typeRawValue;
bool hasTypeValue;
void setType(QString input);
void initType();
QList<Language*> languageList;
void addLanguage(Language * ele);
void initLanguage();

};
#endif