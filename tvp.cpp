#include "tvp.h"

#include <QtGui>
#include "keys.h"
#include "channelsDialog.h"

QSettings *settings;

TVP::TVP() :
		QMainWindow(NULL) {
	tv = NULL;
	settings = new QSettings(this);
	makeUI();
}

void TVP::closeEvent(QCloseEvent *event) {
	quit();
	event->accept();
}

TVP::~TVP() {
}

void TVP::makeMenuBar() {
	QMenu *tvProgram = menuBar()->addMenu(tr("TV &Program"));
	QAction *openAct = new QAction(tr("&Open"), tvProgram);
	openAct->setShortcuts(QKeySequence::Open);
	openAct->setStatusTip(tr("Open TV program from file"));
	connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
	tvProgram->addAction(openAct);

	QAction *sortAct = new QAction(tr("&Sort"), tvProgram);
	sortAct->setShortcut(Qt::ControlModifier + Qt::Key_S);
	sortAct->setStatusTip(tr("Sort channels"));
	connect(sortAct, SIGNAL(triggered()), this, SLOT(sort()));
	tvProgram->addAction(sortAct);

	QAction *quitAct = new QAction(tr("&Quit"), tvProgram);
	quitAct->setShortcuts(QKeySequence::Quit);
	quitAct->setStatusTip(tr("Leave this application"));
	connect(quitAct, SIGNAL(triggered()), this, SLOT(quit()));
	tvProgram->addAction(quitAct);
}

void TVP::fillChannels() {
	QList<Channel*> chans = tv->getChannelList();
	channels.clear();
	channelIds.clear();
	QMap<QString, Channel*> channelMap;
	for (int i = 0; i < chans.size(); i++) {
		channelMap.insert(chans.at(i)->getId(), chans.at(i));
		channelIds.append(chans.at(i)->getId());
		channels.append(chans.at(i)->getDisplayNameList().at(0)->getValue());
	}
	QList<Programme*> programmes = tv->getProgrammeList();
	for (int i = 0; i < programmes.size(); i++) {
		QString chan = programmes.at(i)->getChannel();
		if (!channelMap.contains(chan)) {
			channelMap.insert(chan, NULL);
			channelIds.append(chan);
			channels.append(chan);
		}
	}
}

void TVP::setChannels() {
	progView->setChannels(channelIds, channels);
	inner->setFixedSize(progView->sizeHint());
	progView->setFixedSize(progView->sizeHint());
	progView->layout();
}

void TVP::setTabs() {
	for (int i = tabBar->count() - 1; i >= 0; i--) {
		tabBar->removeTab(i);
	}

	for (int i = 0; i < days.size(); i++) {
		QDate date = days.at(i);
		QString format = getKey(DATE_FORMAT).toString();
		QString text = date.toString(format);
		int index = tabBar->addTab(text);
		tabBar->setTabData(index, date);
	}
}

void TVP::setContent() {
	int index = tabBar->currentIndex();
	QList<Programme*> progs;
	QDate date(2000, 1, 1);
	if (index >= 0) {
		date = tabBar->tabData(index).toDate();
		progs = getProgrammeList(date);
	}
	qDebug() << index << date;
	progView->setProgrammes(progs, date);
}

void TVP::makeStatusBar() {
	statusBar();
}

void TVP::makeContent() {
	QWidget *central = new QWidget(NULL);
	QVBoxLayout *layout = new QVBoxLayout();

	tabBar = new QTabBar(central);
	connect(tabBar, SIGNAL(currentChanged(int)), this, SLOT(setContent()));
	layout->addWidget(tabBar, 0, Qt::AlignTop);

	QScrollArea *scroll = new QScrollArea(central);
	scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

	inner = new QWidget(scroll);

	scroll->setWidget(inner);

	progView = new ProgView(inner);
	progView->layout();
	inner->setFixedSize(progView->sizeHint());

	layout->addWidget(scroll);
	central->setLayout(layout);
	this->setCentralWidget(central);
}

void TVP::makeUI() {
	makeMenuBar();
	makeStatusBar();
	makeContent();
}

void TVP::sort() {
	QMap<QString, QString> map;
	for (int i = 0; i < channels.size(); i++) {
		map.insert(channels.at(i), channelIds.at(i));
	}
	ChannelsDialog dialog(this, channels);
	if (dialog.exec() == QDialog::Accepted) {
		channels = dialog.getChannels();
	}
	channelIds.clear();
	for (int i = 0; i < channels.size(); i++) {
		channelIds.append(map.value(channels.at(i)));
	}
	setChannels();
}

void TVP::open() {
	QString file = QFileDialog::getOpenFileName(this,
			tr("Select file with tv program"), QString(),
			tr("XMLTV files") + "(*.xml *.xmltv)");
	statusBar()->showMessage("Loading file " + file);
	Tv *tv = loadFromFile(file);
	if (tv != NULL) {
		statusBar()->showMessage("Processing xml");
		processModel(tv);
		statusBar()->showMessage("File has been loaded", 3000);
	} else {
		statusBar()->showMessage("Loading failed!", 3000);
	}
}

QList<QDate> TVP::getDays(Tv *tv) {
	QList<Programme*> programmes = tv->getProgrammeList();
	QMap<QDate, int> days;
	for (int i = 0; i < programmes.size(); i++) {
		Programme *p = programmes.at(i);
		QDate day = p->getStart().date();
		days.insert(day, 0);
		day = p->getStop().date();
		days.insert(day, 0);
	}
	QList<QDate> daysList = days.keys();
	qSort(daysList.begin(), daysList.end());
	return daysList;
}

void TVP::processModel(Tv *tv) {
	TVP::tv = tv;
	days = getDays(tv);
	fillChannels();
	setChannels();
	setTabs();
	setContent();
}

QList<Programme*> TVP::getProgrammeList(QDate day) {
	QTime startTime = getKey(START_TIME).toTime();
	QDateTime start;
	if (startTime <= QTime(12, 0)) {
		start = QDateTime(day, startTime);
	} else {
		start = QDateTime(day.addDays(-1), startTime);
	}
	qDebug() << start;
	QTime endTime = getKey(END_TIME).toTime();
	QDateTime end;
	if (endTime >= QTime(12, 0)) {
		end = QDateTime(day, endTime);
	} else {
		end = QDateTime(day.addDays(+1), endTime);
	}
	qDebug() << end;
	QList<Programme*> programmes;
	if (tv != NULL) {
		QList<Programme*> all = tv->getProgrammeList();
		for (int i = 0; i < all.size(); i++) {
			Programme* p = all.at(i);
			if (p->getStart() < end && p->getStop() > start) {
				programmes.append(p);
			}
		}
	}
	return programmes;
}

Tv *TVP::loadFromFile(QString filename) {
	Tv *tv = NULL;
	if (QFile::exists(filename)) {
		QFile file(filename);
		if (file.open(QIODevice::ReadOnly)) {
			QTemporaryFile temp;
			if (temp.open()) {
				QTextStream stream(&file);
				// will convert file to temp
				QString line;
				bool inside = false;
				do {
					line = stream.readLine();
					if (!line.isEmpty()) {
						for (int i = 0; i < line.size(); i++) {
							QChar c = line.at(i);
							if (c == QChar('"') || c == QChar('<')
									|| c == QChar('>')) {
								inside = inside ? false : true;
							}
							if (c == QChar('-') && inside) {
								line.remove(i, 1);
							}
						}
						temp.write(line.toUtf8());
					}
				} while (!line.isNull());
				// temp contains converted file
				temp.close();
				statusBar()->showMessage("Parsing xml");
				tv = Tv::fromFile(temp);
			}
			file.close();
		}
	}
	return tv;
}

void TVP::quit() {
	QApplication::quit();
}
