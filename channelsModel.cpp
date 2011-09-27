/*
 * channelsModel.cpp
 *
 *  Created on: 27.9.2011
 *      Author: Adam Juraszek
 */

#include "channelsModel.h"

ChannelsModel::ChannelsModel(QObject *parent) :
		QStringListModel(parent) {
}

ChannelsModel::~ChannelsModel() {
}

Qt::ItemFlags ChannelsModel::flags(const QModelIndex &index) const {
	Qt::ItemFlags flags;
	if (index.isValid())
		flags = Qt::ItemIsSelectable | Qt::ItemIsDragEnabled
				| Qt::ItemIsEnabled;
	else
		flags = Qt::ItemIsSelectable | Qt::ItemIsDragEnabled
				| Qt::ItemIsDropEnabled | Qt::ItemIsEnabled;
	return flags;
}

