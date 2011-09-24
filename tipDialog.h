/*
 * tipDialog.h
 *
 *  Created on: 24.9.2011
 *      Author: Adam Juraszek
 */

#ifndef TIPDIALOG_H_
#define TIPDIALOG_H_
#include "model/Programme.h"
#include <QtGui>
#include <QtGui/QWidget>
#include <QtGui/QFileDialog>
#include "progView.h"

class TipDialog: public QDialog {
public:
	TipDialog(ProgView *parent, Programme *programme);
	virtual ~TipDialog();

private:
	Programme *programme;
	QTextDocument *getDocument();
};

#endif /* TIPDIALOG_H_ */
