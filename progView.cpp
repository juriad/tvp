/*
 * progView.cpp
 *
 *  Created on: 21.9.2011
 *      Author: Adam Juraszek
 */

#include "progView.h"
#include "keys.h"
#include <QtGui>
#include "tipDialog.h"

ProgView::ProgView(QWidget *parent) :
		QWidget(parent) {
	makeContent();
}

ProgView::~ProgView() {
}

void ProgView::makeContent() {
	makeTimeLine();
}

void ProgView::makeTimeLine() {
	QTime s = getKey(START_TIME).toTime();
	QDateTime start = QDateTime(
			QDate(2000, 1, 1).addDays(s.hour() >= 12 ? -1 : 0), s);
	QTime e = getKey(END_TIME).toTime();
	QDateTime end = QDateTime(QDate(2000, 1, 1).addDays(e.hour() < 12 ? 1 : 0),
			e);
	float period = getKey(TIME_PERIOD).toInt(); // min
	QString format = getKey(TIME_FORMAT).toString();
	QDateTime time = start;
	int length = start.secsTo(end) / 60; // min
	int count = length / period + 2;
	for (int i = 0; i <= count; i++) {
		QLabel *lab = new QLabel(time.time().toString(format), this);
		timeLine.append(lab);
		timeLineDate.insert(lab, time);
		time = time.addSecs(period * 60);
	}
}

int ProgView::getX(int index) {
	return getKey(TIMELINE_WIDTH).toInt()
			+ index * getKey(CHANNEL_WIDTH).toInt();
}

int ProgView::getY(QDateTime time) {
	QTime s = getKey(START_TIME).toTime();
	QDateTime start = QDateTime(
			QDate(2000, 1, 1).addDays(s.hour() >= 12 ? -1 : 0), s);
	return ((float) start.secsTo(time) / 60) / 60 * getKey(HOUR_HEIGHT).toInt()
			+ getKey(CHANNELBAR_HEIGHT).toInt();
}

void ProgView::makeChannelBar() {
	for (int i = 0; i < channels.size(); i++) {
		QLabel *chan = new QLabel(channels.at(i), this);
		chan->setWordWrap(true);
		channelBar.append(chan);
	}
}

void ProgView::setChannels(QList<QString> channelIds, QList<QString> channels) {
	qDebug() << "setChannels" << channelIds.size();
	while (channelBar.size() > 0) {
		channelBar.last()->hide();
		channelBar.last()->setParent(NULL);
		delete channelBar.last();
		channelBar.removeLast();
	}
	ProgView::channelIds = channelIds;
	ProgView::channels = channels;
	makeChannelBar();
}

void ProgView::paintEvent(QPaintEvent *event) {
	QPainter painter;
	painter.begin(this);
	paint(painter, event);
	painter.end();
}

void ProgView::paint(QPainter& painter, QPaintEvent *event) {
	paintBackground(painter, event);
	paintProgrammes(painter, event);
}

void ProgView::paintBackground(QPainter &painter, QPaintEvent *event) {
	QSize size = sizeHint();
	painter.setPen(QPen(Qt::NoPen));
	painter.fillRect(0, 0, size.width(), size.height(),
			getKey(BACKGROUND).value<QColor>());
	for (int i = 0; i < channelBar.size(); i++) {
		painter.fillRect(
				getX(i),
				0,
				getKey(CHANNEL_WIDTH).toInt(),
				size.height(),
				getKey(i % 2 == 0 ? ODDCOLS_BACKGROUND : EVENCOLS_BACKGROUND).value<
						QColor>());
	}
	for (int i = 0; i < timeLine.size(); i++) {
		QLabel *lab = timeLine.at(i);
		int start = getY(timeLineDate.value(lab));
		int end = getY(
				timeLineDate.value(lab).addSecs(
						getKey(TIME_PERIOD).toInt() * 60));
		painter.fillRect(
				0,
				start,
				size.width(),
				end - start,
				getKey(i % 2 == 0 ? ODDROWS_BACKGROUND : EVENROWS_BACKGROUND).value<
						QColor>());
	}
	painter.fillRect(0, 0, getKey(TIMELINE_WIDTH).toInt(), size.height(),
			getKey(TIMELINE_BACKGROUND).value<QColor>());
	painter.fillRect(0, 0, size.width(), getKey(CHANNELBAR_HEIGHT).toInt(),
			getKey(CHANNELBAR_BACKGROUND).value<QColor>());
}

void ProgView::paintProgrammes(QPainter& painter, QPaintEvent *event) {
	for (int i = 0; i < programmes.size(); i++) {
		Programme *prog = programmes.at(i);
		QDateTime start = getRelTime(prog->getStart());
		QDateTime stop = getRelTime(prog->getStop());
		QString channel = prog->getChannel();
		int s = getY(start);
		int min = getKey(CHANNELBAR_HEIGHT).toInt();
		s = s < min ? min : s;
		int c = getX(channelIds.indexOf(channel));
		//painter.fillRect(c + 10, s + 10, getKey(CHANNEL_WIDTH).toInt() - 20,
		//		getY(stop) - s - 20, Qt::red);
		QRect full(c, s, getKey(CHANNEL_WIDTH).toInt(), getY(stop) - s);
		QRect rect = full.adjusted(5, 5, -5, -5);
		painter.setBrush(Qt::NoBrush);
		painter.setPen(Qt::black);
		painter.drawRect(rect);
		//painter.setClipRect(rect);
		painter.drawText(rect, prog->getTitleList().at(0)->getValue());
	}
}

void ProgView::mouseReleaseEvent(QMouseEvent * event) {
	for (int i = 0; i < programmes.size(); i++) {
		Programme *prog = programmes.at(i);
		QDateTime start = getRelTime(prog->getStart());
		QDateTime stop = getRelTime(prog->getStop());
		QString channel = prog->getChannel();
		int s = getY(start);
		int min = getKey(CHANNELBAR_HEIGHT).toInt();
		s = s < min ? min : s;
		int c = getX(channelIds.indexOf(channel));
		QRect full(c, s, getKey(CHANNEL_WIDTH).toInt(), getY(stop) - s);
		if (full.contains(event->pos())) {
			qDebug() << "clicked on" << prog->getTitleList().at(0)->getValue();
			showTip(event, prog);
		}
	}
}

void ProgView::showTip(QMouseEvent *event, Programme *programme) {
	TipDialog *dialog = new TipDialog(this, programme);
	dialog->show();
	dialog->raise();
	dialog->activateWindow();
}

void ProgView::layout() {
	int maxHeight = 0;
	for (int i = 0; i < channelBar.size(); i++) {
		int y = 0;
		QLabel *chan = channelBar.at(i);
		int x = getX(i);
		int width = getKey(CHANNEL_WIDTH).toInt();
		int height = chan->heightForWidth(width);
		if (height > maxHeight) {
			maxHeight = height;
		}
		chan->setGeometry(x, y, width, height);
		chan->show();
		//qDebug() << "x: " << x << "y: " << y;
		//qDebug() << chan->text();
	}
	CHANNELBAR_HEIGHT.def = maxHeight;
	setKey(CHANNELBAR_HEIGHT);
	for (int i = 0; i < timeLine.size(); i++) {
		int x = 0;
		QLabel *lab = timeLine.at(i);
		int y = getY(timeLineDate.value(lab));
		lab->setGeometry(x, y, lab->sizeHint().width(),
				lab->sizeHint().height());
		lab->show();
		//qDebug() << "x: " << x << "y: " << y;
		//qDebug() << lab->text();
	}
}

QSize ProgView::sizeHint() {
	int width = getKey(TIMELINE_WIDTH).toInt()
			+ channels.size() * getKey(CHANNEL_WIDTH).toInt();
	QTime s = getKey(START_TIME).toTime();
	QDateTime start = QDateTime(
			QDate(2000, 1, 1).addDays(s.hour() >= 12 ? -1 : 0), s);
	QTime e = getKey(END_TIME).toTime();
	QDateTime end = QDateTime(QDate(2000, 1, 1).addDays(e.hour() < 12 ? 1 : 0),
			e);
	float length = (start.secsTo(end) / (float) 3600)
			* getKey(HOUR_HEIGHT).toInt();
	return QSize(width, length + getKey(CHANNELBAR_HEIGHT).toInt());
}

void ProgView::setProgrammes(QList<Programme*> programmes, QDate baseDay) {
	qDebug() << "setProgrammes" << baseDay;
	ProgView::programmes = programmes;
	ProgView::baseDay = baseDay;
	repaint();
}

QDateTime ProgView::getRelTime(QDateTime time) {
	QDate date(2000, 1, 1);
	date = date.addDays(baseDay.daysTo(time.date()));
	return QDateTime(date, time.time());
}

QString ProgView::getStringForId(QString id) {
	return channels.at(channelIds.indexOf(id));
}
