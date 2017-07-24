

/****************************************************************
 * This file is distributed under the following license:
 *
 * Copyright (C) 2017, Bernd Stramm

This is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

 ****************************************************************/

#include "version.h"
#include <QApplication>

#include "deliberate.h"
#include <QString>
#include <QDebug>
#include <stdio.h>

/****************************************************************
 * This file is distributed under the following license:
 *
 * Copyright (C) 2017, Bernd Stramm

This is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

 ****************************************************************/

using namespace deliberate;

int
main (int argc, char *argv[])
{
  QApplication::setOrganizationName ("BerndStramm");
  QApplication::setOrganizationDomain ("berndhs.world");
  QString appname (argv[1]);
  QApplication::setApplicationName (appname);
  QApplication app (argc, argv);

  ProgramVersion pv (appname);

  printf ("// defne for string vaiable\n");
  printf ("// %s\n",pv.CopyRight().toLocal8Bit().data());
  printf ("\n#define wholeversion %s\n",pv.VersionNumber().toLocal8Bit().data());
  return pv.Version().length();
}

