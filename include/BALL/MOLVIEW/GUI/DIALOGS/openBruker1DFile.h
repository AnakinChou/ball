// $Id: openBruker1DFile.h,v 1.4.4.1 2002/10/21 15:39:33 amoll Exp $

#ifndef BALL_MOLVIEW_GUI_DIALOGS_OPENBRUKER1DFILE_H
#define BALL_MOLVIEW_GUI_DIALOGS_OPENBRUKER1DFILE_H

#ifndef BALL_VIEW_GUI_WIDGETS_REGULARDATA1DWIDGET_H
# include <BALL/VIEW/GUI/WIDGETS/regularData1DWidget.h>
#endif

#ifndef BALL_VIEW_GUI_DIALOGS_FILEDIALOG_H
# include <BALL/VIEW/GUI/DIALOGS/fileDialog.h>
#endif

using namespace BALL::VIEW;

namespace BALL
{
	namespace MOLVIEW
	{

		/** This class provides an interface to select and open spectra stored in the bruker file format.
		*/
		class OpenBruker1DFile
			: public FileDialog
		{
			BALL_EMBEDDABLE(OpenBruker1DFile)

			public:

			/** Constructors and Destructors
			*/
			//@{
			/// Constructor.
			OpenBruker1DFile(QWidget *parent = 0, const char *name = 0);

			/// Destructor
			virtual ~OpenBruker1DFile()
				throw();
			//@}

			/** Assignment
			*/

			/** Initialization. This method is called automatically before the main application is started. 
					It adds the	dialog's menu entries and connections.
			*/
			virtual void initializeWidget(MainControl& main_control)
				throw();

			/** Remove the dialog.
					This method is called by the dialog's destructor.
					It reverses all actions performed in 
					initializeWidget (remove menu entries and connections).
			*/
			virtual void finalizeWidget(MainControl& main_control)
				throw();


			protected:

			/** Open the bruker1DFile.
			 */
			virtual void openFile_()
				throw();

		};
	}
}

#endif
