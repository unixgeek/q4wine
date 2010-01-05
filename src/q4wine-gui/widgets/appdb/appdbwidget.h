/***************************************************************************
 *   Copyright (C) 2008-2010 by Malakhov Alexey                            *
 *   brezerk@gmail.com                                                     *
 *                                                                         *
 *   This program is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                         *
 ***************************************************************************/

#ifndef APPDBWIDGET_H
#define APPDBWIDGET_H

#include <memory>
#include "config.h"

#include <QDebug>
#include <QString>
#include <QTimer>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QToolBar>
#include <QKeyEvent>
#include <QAction>

#include "httpcore.h"
#include "xmlparser.h"

#include "appdbheaderwidget.h"
#include "appdbscrollwidget.h"

class AppDBWidget : public QWidget
{
Q_OBJECT
public:
	explicit AppDBWidget(QString themeName, QWidget *parent = 0);

public slots:
	void itemTrigged(short int action, QString search="", int val1=0, int val2=0, int val3=0);
	void httpcore_pageDownloaded();
	void requestError(QString error);
	void updateDataReadProgress(int bytesRead, int totalBytes);

private:
	//! Functions
	void showXmlError(int id);
	void createActions(void);
	QIcon loadIcon(QString iconName);

	//! AppDB core clases
	std::auto_ptr<XmlParser> xmlparser;
	std::auto_ptr<HttpCore> httpcore;

	//! AppDB custom widgets
	std::auto_ptr<AppDBScrollWidget> appdbScrollArea;
	std::auto_ptr<AppDBHeaderWidget> appdbHeader;

	//! Delay timer
	std::auto_ptr<QTimer> timer;
	std::auto_ptr<QAction> appdbOpen;
	std::auto_ptr<QAction> appdbAppPage;
	std::auto_ptr<QAction> appdbClear;
	std::auto_ptr<QAction> appdbClearSearch;
	std::auto_ptr<QAction> appdbSearch;

	std::auto_ptr<QLineEdit> searchField;

	//! State variables
	QString search, themeName;
	short int action;
	int appid;
	int catid;
	int verid;
	int testid;
	int page;

	//! This is need for libq4wine-core.so import.
	QLibrary libq4wine;
	typedef void *CoreLibPrototype (bool);
	CoreLibPrototype *CoreLibClassPointer;
	std::auto_ptr<corelib> CoreLib;

private slots:
	void timer_timeout(void);
	void appdbOpen_Click(void);
	void appdbAppPage_Click(void);
	void appdbClear_Click(void);
	void appdbClearSearch_Click(void);
	void appdbSearch_Click(void);

};

#endif // APPDBWIDGET_H