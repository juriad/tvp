#ifndef Tv_H_
#define Tv_H_
#include <QtCore/QtCore>
#include <QDomDocument>
#include "Programme.h"
#include "Channel.h"

class Tv {
public:
Tv() {
  initProgramme();
  initChannel();
  initSourceInfoUrl();
  initSourceDataUrl();
  initDate();
  initGeneratorInfoName();
  initSourceInfoName();
  initGeneratorInfoUrl();
}
static Tv* fromFile( QFile &file);
static Tv* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
bool hasSourceInfoUrl() {
  return hasSourceInfoUrlValue;
}
bool isSourceInfoUrlValid(QString input);
QString getSourceInfoUrl() {
  return sourceInfoUrlValue;
}
QString getRawSourceInfoUrl() {
  return sourceInfoUrlRawValue;
}
bool hasSourceDataUrl() {
  return hasSourceDataUrlValue;
}
bool isSourceDataUrlValid(QString input);
QString getSourceDataUrl() {
  return sourceDataUrlValue;
}
QString getRawSourceDataUrl() {
  return sourceDataUrlRawValue;
}
bool hasDate() {
  return hasDateValue;
}
bool isDateValid(QString input);
QDateTime getDate() {
  return dateValue;
}
QString getRawDate() {
  return dateRawValue;
}
bool hasGeneratorInfoName() {
  return hasGeneratorInfoNameValue;
}
bool isGeneratorInfoNameValid(QString input);
QString getGeneratorInfoName() {
  return generatorInfoNameValue;
}
QString getRawGeneratorInfoName() {
  return generatorInfoNameRawValue;
}
bool hasSourceInfoName() {
  return hasSourceInfoNameValue;
}
bool isSourceInfoNameValid(QString input);
QString getSourceInfoName() {
  return sourceInfoNameValue;
}
QString getRawSourceInfoName() {
  return sourceInfoNameRawValue;
}
bool hasGeneratorInfoUrl() {
  return hasGeneratorInfoUrlValue;
}
bool isGeneratorInfoUrlValid(QString input);
QString getGeneratorInfoUrl() {
  return generatorInfoUrlValue;
}
QString getRawGeneratorInfoUrl() {
  return generatorInfoUrlRawValue;
}
QList<Programme*> getProgrammeList() {
  return programmeList;
}
QList<Channel*> getChannelList() {
  return channelList;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
QString sourceInfoUrlValue;
QString sourceInfoUrlRawValue;
bool hasSourceInfoUrlValue;
void setSourceInfoUrl(QString input);
void initSourceInfoUrl();
QString sourceDataUrlValue;
QString sourceDataUrlRawValue;
bool hasSourceDataUrlValue;
void setSourceDataUrl(QString input);
void initSourceDataUrl();
QDateTime dateValue;
QString dateRawValue;
bool hasDateValue;
void setDate(QString input);
void initDate();
QString generatorInfoNameValue;
QString generatorInfoNameRawValue;
bool hasGeneratorInfoNameValue;
void setGeneratorInfoName(QString input);
void initGeneratorInfoName();
QString sourceInfoNameValue;
QString sourceInfoNameRawValue;
bool hasSourceInfoNameValue;
void setSourceInfoName(QString input);
void initSourceInfoName();
QString generatorInfoUrlValue;
QString generatorInfoUrlRawValue;
bool hasGeneratorInfoUrlValue;
void setGeneratorInfoUrl(QString input);
void initGeneratorInfoUrl();
QList<Programme*> programmeList;
void addProgramme(Programme * ele);
void initProgramme();
QList<Channel*> channelList;
void addChannel(Channel * ele);
void initChannel();

};
#endif