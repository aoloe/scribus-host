#ifndef PRVIEW_H
#define PRVIEW_H

#include <qdialog.h>
#include <qlabel.h>
#include <qpixmap.h>
#include <qscrollview.h>
#include <qlayout.h>
#include <qtoolbutton.h>
#include <qcombobox.h>
#include <qcheckbox.h>
#include "scribus.h"

/** Calls the Plugin with the main Application window as parent
  * and the main Application Class as parameter */
extern "C" void Run(QWidget *d, ScribusApp *plug);
/** Returns the Name of the Plugin.
  * This name appears in the relevant Menue-Entrys */
extern "C" QString Name();
/** Returns the Type of the Plugin.
  * 1 = the Plugin is a normal Plugin, which appears in the Extras Menue
  * 2 = the Plugins is a import Plugin, which appears in the Import Menue
  * 3 = the Plugins is a export Plugin, which appears in the Export Menue */
extern "C" int Type();

class PPreview : public QDialog
{
	Q_OBJECT

public:
	PPreview( QWidget* parent, ScribusApp *plug );
	~PPreview();
	void setPageCombo(int num);
	QPixmap CreatePreview(int Seite, int Res);
	QToolButton* First;
	QToolButton* Back;
	QLabel* Text1;
	QComboBox* SeitenAusw;
	QToolButton* Forward;
	QToolButton* Last;
	QCheckBox* AliasText;
	QCheckBox* AliasGr;
	QScrollView* Anzeige;
	QLabel* Anz;
	QPixmap* Bild;
	ScribusApp *app;
	int APage;
	int MPage;

public slots:
	void ToStart();
	void BackW();
	void ForW();
	void ToEnd();
	void ToSeite(int num);
	void ToggleTextAA();

protected:
	QVBoxLayout* PLayout;
	QHBoxLayout* Layout1;
	QVBoxLayout* Layout2;

};
#endif // QUERY_H
