/*
 * keys.h
 *
 *  Created on: 18.9.2011
 *      Author: Adam Juraszek
 */

#ifndef KEYS_H_
#define KEYS_H_

#include <QtCore/QVariant>
#include <QtCore/QtCore>

struct Key {
	QString key;
	QVariant def;
};

extern QSettings *settings;

extern Key START_TIME;
extern Key END_TIME;
extern Key DATE_FORMAT;
extern Key TIME_FORMAT;
extern Key TIME_PERIOD; // in minutes
extern Key TIMELINE_WIDTH; // in px
extern Key CHANNELBAR_HEIGHT; // in px
extern Key HOUR_HEIGHT; // in px
extern Key CHANNEL_WIDTH; // in px
extern Key TIMELINE_BACKGROUND; // color
extern Key CHANNELBAR_BACKGROUND; // color
extern Key ODDROWS_BACKGROUND; // color
extern Key EVENROWS_BACKGROUND; // color
extern Key ODDCOLS_BACKGROUND; // color
extern Key EVENCOLS_BACKGROUND; // color
extern Key BACKGROUND; // color
extern Key PROGRAMME_BACKGROUND; // color

QVariant getKey(Key key);

void setKey(Key key);

#endif /* KEYS_H_ */
