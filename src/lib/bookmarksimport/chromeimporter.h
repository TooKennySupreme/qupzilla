/* ============================================================
* QupZilla - WebKit based browser
* Copyright (C) 2010-2013  David Rosca <nowrep@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#ifndef CHROMEIMPORTER_H
#define CHROMEIMPORTER_H

#include <QObject>
#include <QFile>

#include "qz_namespace.h"
#include "bookmarksmodel.h"

class QT_QUPZILLA_EXPORT ChromeImporter : public QObject
{
public:
    explicit ChromeImporter(QObject* parent = 0);

    void setFile(const QString &path);
    bool openFile();

    QVector<Bookmark> exportBookmarks();

    bool error() { return m_error; }
    QString errorString() { return m_errorString; }

private:
    QString m_path;
    QFile m_file;

    bool m_error;
    QString m_errorString;

};

#endif // CHROMEIMPORTER_H
