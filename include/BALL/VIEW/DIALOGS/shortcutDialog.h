// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
//

#ifndef BALL_VIEW_DIALOGS_SHORTCUTDIALOG_H
#define BALL_VIEW_DIALOGS_SHORTCUTDIALOG_H

#ifndef BALL_VIEW_KERNEL_PREFERENCESENTRY
# include <BALL/VIEW/KERNEL/preferencesEntry.h>
#endif

#ifndef BALL_VIEW_KERNEL_SHORTCUTREGISTRY_H
# include <BALL/VIEW/KERNEL/shortcutRegistry.h>
#endif

#ifndef BALL_VIEW_KERNEL_MAINCONTROL_H
# include <BALL/VIEW/KERNEL/mainControl.h>
#endif

#ifndef BALL_VIEW_KERNEL_MODULARWIDGET_H
# include <BALL/VIEW/KERNEL/modularWidget.h>
#endif

#ifdef BALL_COMPILER_MSVC
# include <BALL/VIEW/UIC/ui_shortcutDialog.h>
#else
# include <BALL/VIEW/UIC/shortcutDialogData.h>
#endif

namespace BALL
{
	namespace VIEW
	{
		//class MolecularStructure;

		/** Dialog for changing the BALLView shortcuts
				\ingroup ViewDialogs
		*/
		class BALL_VIEW_EXPORT ShortcutDialog
			: public QWidget,
				public Ui_ShortcutDialogData,
				public ModularWidget,
				public PreferencesEntry
		{
			// macro needed for Qt's slot mechanism:
			Q_OBJECT

			public:

			BALL_EMBEDDABLE(ShortcutDialog,ModularWidget)

			/// Constructor
			ShortcutDialog(QWidget* parent = NULL, const char* name = "ShortcutDialog", Qt::WFlags fl = 0 );

			/// Destructor
			virtual ~ShortcutDialog();

			// method for e.g. initializing menu entries, overloaded
			///
			virtual void initializeWidget(MainControl& main_control);

			public slots:
				virtual void searchTextChanged(QString filter);

			protected slots:
				virtual void browseImportFile_();
				virtual void browseExportFile_();

				virtual void shortcutChanged_();

				void loadPredefinedShortcuts_(QString entry);
				void loadShortcutsFromFile_(const String& filename);
		};

	}
}
#endif
