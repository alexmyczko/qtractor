// qtractorMidiControlObserverForm.h
//
/****************************************************************************
   Copyright (C) 2005-2011, rncbc aka Rui Nuno Capela. All rights reserved.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*****************************************************************************/

#ifndef __qtractorMidiControlObserverForm_h
#define __qtractorMidiControlObserverForm_h

#include "ui_qtractorMidiControlObserverForm.h"

// Forward declarartions.
class qtractorMidiControlObserver;
class qtractorCtlEvent;

class QCloseEvent;


//----------------------------------------------------------------------------
// qtractorMidiControlObserverForm -- UI wrapper form.

class qtractorMidiControlObserverForm : public QDialog
{
	Q_OBJECT

public:

	// Pseudo-singleton instance.
	static qtractorMidiControlObserverForm *getInstance();

	// Pseudo-constructor.
	static void showInstance(qtractorMidiControlObserver *pMidiObserver,
		QWidget *pParent = 0, Qt::WindowFlags wflags = 0);

	// Observer accessors.
	void setMidiObserver(qtractorMidiControlObserver *pMidiObserver);
	qtractorMidiControlObserver *midiObserver() const;

	// Process incoming controller event.
	void processEvent(const qtractorCtlEvent& ctle);

protected slots:

	void activateControlType(const QString&);

	void change();

	void click(QAbstractButton *);

	void accept();
	void reject();
	void inputs();
	void reset();

protected:

	// Constructor.
	qtractorMidiControlObserverForm(QWidget *pParent = 0, Qt::WindowFlags wflags = 0);

	// Pseudo-destructor.
	void closeEvent(QCloseEvent *pCloseEvent);

private:

	// The Qt-designer UI struct...
	Ui::qtractorMidiControlObserverForm m_ui;

	// Target object.
	qtractorMidiControlObserver *m_pMidiObserver;

	// Instance variables.
	int m_iDirtyCount;
	int m_iDirtySetup;

	// Pseudo-singleton instance.
	static qtractorMidiControlObserverForm *g_pMidiObserverForm;
};


#endif	// __qtractorMidiControlObserverForm_h


// end of qtractorMidiControlObserverForm.h
