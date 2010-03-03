/***************************************************************************
 *   Copyright (C) 2008, 2009, 2010 by Malakhov Alexey                                 *
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

#ifndef Q4WINE_HELPER_H
#define Q4WINE_HELPER_H

#include <memory>
#include "config.h"

#include <QObject>

#include "prefix.h"
#include "icon.h"

#include "q4wine-lib.h"

class WineObject : public QObject
{
Q_OBJECT
public:
    explicit WineObject(QString prefixName = "Default", QObject *parent = 0);

    void setProgramBinary(QString binary);
    void setProgramArgs(QString args);
    void setProgramDir(QString dir);
    void setProgramDisplay(QString dislpay);
    void setProgramNice(QString dir);

    void setProgramDesktop(QString desktop);
    void setUseConsole(bool console);

private:
    Prefix db_prefix;

    QString prefixName;
    QString prefixPath;
    QString prefixDllPath;
    QString prefixLoader;
    QString prefixServer;
    QString prefixBinary;

    QString programBinary;
    QString programArgs;
    QString programDir;
    QString programDisplay;
    int programNice;
    QString programDesktop;

    bool useConsole;


 /*
struct ExecObject{
    QString runcmd;
    QString useconsole;
    QString cmdargs;
    QString override;
    QString winedebug;
    QString display;
    QString wrkdir;
    QString desktop;
    QString nice;
    QString name;
};
*/

signals:



public slots:

};

#endif // Q4WINE_HELPER_H