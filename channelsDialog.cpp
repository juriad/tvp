/*
 * channelsDialog.cpp
 *
 *  Created on: 27.9.2011
 *      Author: Adam Juraszek
 */

#include "channelsDialog.h"
#include <QtCore/QtCore>
#include <QtGui>
#include "channelsModel.h"

ChannelsDialog::ChannelsDialog(QWidget *parent, QList<QString> channels) :
		QDialog(parent) {
	QVBoxLayout *layout = new QVBoxLayout();
	QScrollArea *scroll = new QScrollArea(this);
	scroll->setWidgetResizable(true);

	QListView *list = new QListView(scroll);

	model = new ChannelsModel(list);
	model->setSupportedDragActions(Qt::MoveAction);
	for (int i = 0; i < channels.size(); i++) {
		model->setData(model->index(i, 0), channels.at(i));
	}
	model->setStringList(QStringList(channels));
	list->setModel(model);
	list->setSelectionMode(QAbstractItemView::ExtendedSelection);
	list->setDragDropMode(QAbstractItemView::InternalMove);
	list->setDragDropOverwriteMode(false);

	scroll->setWidget(list);
	layout->addWidget(scroll);
	QPushButton *button = new QPushButton(tr("Quit"), this);
	connect(button, SIGNAL(clicked()), this, SLOT(accept()));
	layout->addWidget(button);
	setLayout(layout);
	setMinimumSize(800, 600);
}

QList<QString> ChannelsDialog::getChannels() {
	QList<QString> channels;
	for (int i = 0; i < model->rowCount(); i++) {
		QModelIndex index = model->index(i);
		QString string = model->data(index, Qt::DisplayRole).toString();
		channels.append(string);
	}
	return channels;
}

ChannelsDialog::~ChannelsDialog() {
}

