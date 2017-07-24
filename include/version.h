#ifndef DENADA_VERSION_H
#define DENADA_VERSION_H


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


#include <QString>
#include "deliberate.h"
//#include "delib-debug.h"

namespace deliberate {

class ProgramVersion {

public:

  ProgramVersion (QString pgmname);
  
  static QString Version (); 
  static QString MyName ();
  
  static void ShowVersionWindow ();
  static void CLIVersion ();

  static QString CopyRight() { return copyright; }

  void setLead (const QString &newLead);

  static QString VersionNumber();

  void writeIncludes();
  
private:

  static QString leadVersion;
  static QString ProgramName;
  static QString copyright;

  static int baseYear;
  static int baseMonth;
  static int baseDay;

};

}

#endif
