#include "version.h"
#include "deliberate.h"
#include <QMessageBox>
#include <QTimer>
#include <QCoreApplication>
#include <QDateTime>
#include <QDate>


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

namespace deliberate {

  int ProgramVersion::baseYear(2017);
  int ProgramVersion::baseMonth(7);
  int ProgramVersion::baseDay(23);
  QString ProgramVersion::leadVersion ("0.2.%1");

  QString ProgramVersion::ProgramName("Walk");
  QString ProgramVersion::copyright ("Copyright (C) 2017 Bernd Stramm");
  
  ProgramVersion::ProgramVersion (QString pgmname)
  {
    ProgramName = pgmname;
  }

  QString ProgramVersion::Version ()
  { 
    return ProgramName + QString (" Version " )
                   + VersionNumber() + " " + QString(__DATE__) + " "
		       + QString(__TIME__)
		       + QString("\r\n")
		       + copyright;
  }

  void ProgramVersion::ShowVersionWindow ()
  {
    QString versionMessage(Version());
    QMessageBox box;
    box.setText (versionMessage);
    QTimer::singleShot(30000,&box,SLOT(accept()));
    box.exec();
  }
  
  void ProgramVersion::CLIVersion ()
  {
    StdOut() << Version() << endl;
  }

  void ProgramVersion::setLead(const QString &newLead)
  {
    leadVersion = newLead;
  }

  QString ProgramVersion::VersionNumber()
  {
    qint64 lastDigit = QDateTime::currentDateTime().toMSecsSinceEpoch()/100000;
    QDateTime preEpoch = QDateTime(QDate(baseYear,baseMonth,baseDay));
    qint64 offset = - preEpoch.msecsTo(QDateTime::currentDateTime())/100000;
    return QString(leadVersion).arg(lastDigit-offset);
  }
  
  QString ProgramVersion::MyName()
  { 
    return ProgramName;
  }

}
