#ifndef Review_H_
#define Review_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class Review {
public:
Review() {
  initReviewer();
  initType();
  initSource();
  initValue();
}
static Review* fromFile( QFile &file);
static Review* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
bool hasReviewer() {
  return hasReviewerValue;
}
bool isReviewerValid(QString input);
QString getReviewer() {
  return reviewerValue;
}
QString getRawReviewer() {
  return reviewerRawValue;
}
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
bool hasSource() {
  return hasSourceValue;
}
bool isSourceValid(QString input);
QString getSource() {
  return sourceValue;
}
QString getRawSource() {
  return sourceRawValue;
}
bool hasValue() {
  return hasValueValue;
}
bool isValueValid(QString input);
QString getValue() {
  return valueValue;
}
QString getRawValue() {
  return valueRawValue;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
QString reviewerValue;
QString reviewerRawValue;
bool hasReviewerValue;
void setReviewer(QString input);
void initReviewer();
QString typeValue;
QString typeRawValue;
bool hasTypeValue;
void setType(QString input);
void initType();
QString sourceValue;
QString sourceRawValue;
bool hasSourceValue;
void setSource(QString input);
void initSource();
QString valueValue;
QString valueRawValue;
bool hasValueValue;
void setValue(QString input);
void initValue();

};
#endif