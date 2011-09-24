/*
 * tipDialog.cpp
 *
 *  Created on: 24.9.2011
 *      Author: Adam Juraszek
 */

#include "tipDialog.h"
#include <QtCore/QtCore>
#include <QtGui>
#include "model/Programme.h"
#include "keys.h"
#include "progView.h"

TipDialog::TipDialog(ProgView *parent, Programme *programme) :
		QDialog(parent) {
	this->programme = programme;

	QVBoxLayout *layout = new QVBoxLayout();
	QScrollArea *scroll = new QScrollArea(this);
	scroll->setWidgetResizable(true);
	QTextBrowser *text = new QTextBrowser();
	text->setDocument(getDocument());

	scroll->setWidget(text);
	layout->addWidget(scroll);
	QPushButton *button = new QPushButton(tr("Quit"), this);
	connect(button, SIGNAL(clicked()), this, SLOT(close()));
	layout->addWidget(button);
	setLayout(layout);
	setMinimumSize(800, 600);
}

QTextDocument *TipDialog::getDocument() {
	QString text = "<html><body>";
	QString format = getKey(TIME_FORMAT).toString();
	text.append("<div id=\"w\">" + programme->getStart().toString(format));
	text.append(
			" - " + programme->getStop().toString(format) + " " + tr("on")
					+ " ");
	ProgView *progView = (ProgView*) (this->parentWidget());
	QString channel = progView->getStringForId(programme->getChannel());
	text.append(channel + "</div>");
	for (int i = 0; i < programme->getTitleList().size(); i++) {
		QString title = programme->getTitleList().at(i)->getValue();
		text.append("<h1>" + title + "</h1>");
	}
	for (int i = 0; i < programme->getSubTitleList().size(); i++) {
		QString subTitle = programme->getSubTitleList().at(i)->getValue();
		text.append("<h2>" + subTitle + "</h2>");
	}
	for (int i = 0; i < programme->getDescList().size(); i++) {
		QString desc = programme->getDescList().at(i)->getValue();
		text.append("<p>" + desc + "</p>");
	}

	QTextDocument *doc = new QTextDocument(this);
	doc->setHtml(text);
	return doc;
}

TipDialog::~TipDialog() {
}

