/*
 * keys.cpp
 *
 *  Created on: 22.9.2011
 *      Author: Adam Juraszek
 */

#include "keys.h"
#include <QtGui/QPalette>

Key START_TIME = { "START_TIME", QTime(23, 0) };
Key END_TIME = { "END_TIME", QTime(4, 0) };
Key DATE_FORMAT = { "DATE_FORMAT", QString("dddd' - 'd'. 'MMM") };
Key TIME_FORMAT = { "TIME_FORMAT", QString("H':'m") };
Key TIME_PERIOD = { "TIME_PERIOD", 30 }; // in minutes
Key TIMELINE_WIDTH = { "TIMELINE_WIDTH", 100 }; // in px
Key CHANNELBAR_HEIGHT = { "CHANNELBAR_HEIGHT", 0 }; // in px
Key HOUR_HEIGHT = { "HOUR_HEIGHT", 200 }; // in px
Key CHANNEL_WIDTH = { "CHANNEL_WIDTH", 200 }; // in px
Key TIMELINE_BACKGROUND = { "TIMELINE_BACKGROUND", QColor(200, 200, 200, 127) }; // color
Key CHANNELBAR_BACKGROUND = { "CHANNELBAR_BACKGROUND", QColor(220, 220, 220,
		127) }; // color
Key ODDROWS_BACKGROUND = { "ODDROWS_BACKGROUND", QColor(255, 255, 255, 127) }; // color
Key EVENROWS_BACKGROUND = { "EVENROWS_BACKGROUND", QColor(255, 255, 0, 127) }; // color
Key ODDCOLS_BACKGROUND = { "ODDCOLS_BACKGROUND", QColor(255, 255, 255, 127) }; // color
Key EVENCOLS_BACKGROUND = { "EVENCOLS_BACKGROUND", QColor(0, 255, 255, 127) }; // color
Key BACKGROUND = { "BACKGROUND", QColor(255, 255, 255, 255) }; // color
Key PROGRAMME_BACKGROUND = { "PROGRAMME_BACKGROUND", QColor(127, 255, 127, 64) }; // color

QVariant getKey(Key key) {
	return settings->value(key.key, key.def);
}

void setKey(Key key) {
	settings->setValue(key.key, key.def);
}

