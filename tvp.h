#ifndef TVP_H
#define TVP_H

#include <QtGui/QMainWindow>
#include "model/Tv.h"
#include "progView.h"


class TVP: public QMainWindow {
Q_OBJECT

public:
	TVP();
	~TVP();

private slots:
	void open();
	void quit();
	void setContent();

private:
	QHash<QString, Channel*> channels;
	Tv *tv;
	QList<QDate> days;
	QTabBar *tabBar;
	QWidget *inner;
	ProgView *progView;
	void makeUI();
	void makeMenuBar();
	void makeStatusBar();
	void makeContent();
	void setTabs();
	void setChannels();
	void fillChannels();
	Tv *loadFromFile(QString filename);
	void processModel(Tv *tv);
	QList<QDate> getDays(Tv *tv);
	QList<Programme*> getProgrammeList(QDate day);
	virtual void closeEvent(QCloseEvent *event);
};

#endif // TVP_H
