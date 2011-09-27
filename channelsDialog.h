/*
 * channelsDialog.h
 *
 *  Created on: 27.9.2011
 *      Author: Adam Juraszek
 */

#ifndef CHANNELSDIALOG_H_
#define CHANNELSDIALOG_H_
#include <QtGui>
#include <QtGui/QWidget>
#include <QtCore/QList>
#include "channelsModel.h"

class ChannelsDialog: public QDialog {
public:
	ChannelsDialog(QWidget *parent, QList<QString>);
	virtual ~ChannelsDialog();
	QList<QString> getChannels();

private:
	ChannelsModel *model;
};

#endif /* CHANNELSDIALOG_H_ */
