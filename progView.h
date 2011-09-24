/*
 * progView.h
 *
 *  Created on: 21.9.2011
 *      Author: Adam Juraszek
 */

#ifndef PROGVIEW_H_
#define PROGVIEW_H_
#include <QtGui/QWidget>
#include <QtCore/QList>
#include <QtCore/QtCore>
#include <QtGui>
#include "model/Programme.h"

class ProgView: public QWidget {
public:
	ProgView(QWidget *parent);
	virtual ~ProgView();
	void setProgrammes(QList<Programme*> programmes, QDate baseDay);
	virtual QSize sizeHint();
	QString getStringForId(QString id);

public slots:
	void layout();
	void setChannels(QList<QString> channelIds, QList<QString> channels);

protected:
	virtual void paintEvent(QPaintEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent * event);

private:
	void makeContent();
	void makeTimeLine();
	void makeChannelBar();
	int getX(int index);
	int getY(QDateTime time);
	void paint(QPainter& painter, QPaintEvent *event);
	void paintBackground(QPainter& painter, QPaintEvent *event);
	void paintProgrammes(QPainter& painter, QPaintEvent *event);
	QDateTime getRelTime(QDateTime time);
	void showTip(QMouseEvent *event, Programme *programme);

	QList<Programme*> programmes;
	QDate baseDay;
	QList<QLabel*> timeLine;
	QList<QString> channels;
	QHash<QLabel*, QDateTime> timeLineDate;
	QList<QString> channelIds;
	QList<QLabel*> channelBar;
};

#endif /* PROGVIEW_H_ */
