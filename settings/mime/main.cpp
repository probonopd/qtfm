/*
 * This file is part of QtFM <https://qtfm.eu>
 *
 * Copyright (C) 2013-2019 QtFM developers (see AUTHORS)
 * Copyright (C) 2010-2012 Wittfella <wittfella@qtfm.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 */

#include "settingsdialog.h"
#include "mimeutils.h"
#include "common.h"

#include <QApplication>
#include <QSettings>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MimeUtils mimeUtils(Q_NULLPTR);
    QSettings settings(Common::configFile(), QSettings::IniFormat);
    QString name = settings.value("defMimeAppsFile", MIME_APPS).toString();
    mimeUtils.setDefaultsFileName(name);

    SettingsDialog d(&settings, &mimeUtils, Q_NULLPTR);
    d.show();
    return a.exec();
}
