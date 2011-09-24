#ifndef New_H_
#define New_H_
#include <QtCore/QtCore>
#include <QDomDocument>

class New {
public:
New() {
}
static New* fromFile( QFile &file);
static New* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);

};
#endif