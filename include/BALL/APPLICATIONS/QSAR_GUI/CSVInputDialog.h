#ifndef CSVINPUTDIALOG_H
#define CSVINPUTDIALOG_H

#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QLineEdit>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>

#include <BALL/APPLICATIONS/QSAR_GUI/CSVInputDataItem.h>

namespace BALL
{
	namespace VIEW
	{
		/** @class CSVInputDialog
		* @brief a dialog
		*
		* @todo
		*/
		class CSVInputDialog : public QDialog
		{
		
			Q_OBJECT
		public:
			/** @name Constructors and Destructors
			*/	
			CSVInputDialog(CSVInputDataItem* item);
			~CSVInputDialog();
		
			/** @name Accessors
			*/
		
			/** returns the activity numbers
			*/ 
			int numberOfActivities();
			bool xLabels();
			bool yLabels();
			bool inputOk();
		
		public slots:
			void readNumY();

		private:
		
			/** @name Attributes
			*/
			QLineEdit* activity_edit_;
			QCheckBox* x_labels_;
			QCheckBox* y_labels_;
			QCheckBox* center_descriptor_values_;
			QCheckBox* center_response_values_;
			int no_y_;
			bool input_ok_;
			CSVInputDataItem* input_item_;
		};
	}
}

 #endif
