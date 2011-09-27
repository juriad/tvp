/*
 * channelsModel.h
 *
 *  Created on: 27.9.2011
 *      Author: Adam Juraszek
 */

#ifndef CHANNELSMODEL_H_
#define CHANNELSMODEL_H_
#include <QtCore/QtCore>
#include <QtGui>

class ChannelsModel: public QStringListModel {
public:
	ChannelsModel(QObject *parent);
	virtual ~ChannelsModel();
	virtual Qt::ItemFlags flags(const QModelIndex &index) const;
};

#endif /* CHANNELSMODEL_H_ */
