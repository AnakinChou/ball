// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id:

#ifndef BALL_VIEW_DIALOGS_ASSIGNBONDORDERRESULTSDIALOG_H
#define BALL_VIEW_DIALOGS_ASSIGNBONDORDERRESULTSDIALOG_H

#ifndef BALL_VIEW_KERNEL_MODULARWIDGET_H
# include <BALL/VIEW/KERNEL/modularWidget.h>
#endif

#ifndef BALL_VIEW_WIDGETS_SDWIDGET_H
# include <BALL/VIEW/WIDGETS/SDWidget.h>
#endif

#ifndef BALL_STRUCTURE_ASSIGNBONDORDERPROCESSOR_H
# include <BALL/STRUCTURE/assignBondOrderProcessor.h>
#endif

#include <BALL/VIEW/UIC/assignBondOrderResultsDialogData.h>
#include <QtGui/qdialog.h>
#include <map>

namespace BALL
{
	namespace VIEW
	{
		/** Dialog for presenting the bond order assingment sets and generating structures for each found solution
			 */
			class BALL_VIEW_EXPORT AssignBondOrderResultsDialog :
				public QDialog,
				public Ui_AssignBondOrderResultsDialogData,
				public ModularWidget
			{
				Q_OBJECT

				public:

					BALL_EMBEDDABLE(AssignBondOrderResultsDialog, ModularWidget)

					/// Default Constructor.
					AssignBondOrderResultsDialog(QWidget *parent = NULL,	const char *name = "AssignBondOrderResultsDialog")
						throw();

					/// Destructor.
					virtual ~AssignBondOrderResultsDialog() throw();

					///
					virtual void initializeWidget(MainControl& main_control);

					///
					virtual void checkMenu(MainControl& main_control)
						throw();

					///
					void setProcessor(AssignBondOrderProcessor* abop);

				public slots:
					
					/// Show and raise dialog
					void show();
					
					///
					void addSolutionToStructures();

					///
					void computeNextSolution();
					
					/// show the chosen solution
					void switchView(QTreeWidgetItem* item, int column);
				
					///
					void createEntries();

					///
					void clearEntries();
					
					///
					void finished();
				
				protected:

					SDWidget 																		sdwidget_;

					// systems, which have already been mapped to 2D	
					std::map<QTreeWidgetItem*, System*> 				sd_systems_;
					
					// system copies with applied solutions 
					std::map<QTreeWidgetItem*, System*> 				solution_systems_;
					
					// the solution number 
					std::map<QTreeWidgetItem*, Position> 				solution_number_;
					
					// the solution description
					std::map<QTreeWidgetItem*, String>  	      descriptions_;
						
					AssignBondOrderProcessor* 									bond_order_processor_;
					
					QTreeWidgetItem *														root_;
					
					QTreeWidgetItem *														activated_item_;
			};
	}
}
#endif
