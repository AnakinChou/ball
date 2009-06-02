#ifndef PLOTTER_H
#define PLOTTER_H

#include <qwt_plot.h>
#include <BALL/APPLICATIONS/QSAR_GUI/dataItem.h>
#include <list>
#include <QString>
#include <QtGui/QDialog>
#include <QMouseEvent>
#include <QPushButton>
#include <QtGui/QDialogButtonBox>
#include <QHBoxLayout>
#include <QCheckBox>

#include <qwt_symbol.h>
#include <qwt_plot_zoomer.h>


namespace BALL
{
	namespace VIEW
	{
		class Plotter : public QFrame
		{	
			Q_OBJECT		
			
			public: 
				
				/** the symbol to be used for each data point within the plots */
				QwtSymbol data_symbol;
				
				/** the font to to be used for each data point within the plots */
				QFont data_label_font;
				
				/** determines how each label is aligned with respect to its data point */
				Qt::Alignment data_label_alignment;
				
				/** the symbol to be used for each data point within the plots during printing or saving to file.\n
				By default it is equal to data_symbol */
				QwtSymbol print_data_symbol;
				
				/** determines whether or not labels for each data point are to be drawn */
				bool show_data_labels;
				
				/** prints the current contents of the plot to a file */
				void printToFile(QString& file);
				
				~Plotter();

				
				
			protected slots:
				
				void labelsChangeState();
				
				void save();
				
				void print();
				
			
			
			protected:
				/** constructor */
				Plotter(DataItem* item);
				
				/** (re)plots all data. \n
				Must be implemented by derived classes. */
				virtual void plot(bool zoom=1) = 0;
				
				QColor generateColor(int no_colors, int current_no);
				
				DataItem* item_;
				
				QwtPlot* qwt_plot_;
				
				/** contains a name for each plotted data point.\n
				Can be used e.g. for mouse-over effects... */
				std::list<QString> names_;
				
				QPushButton* okButton_;
				QCheckBox* show_labels_;
				QPushButton* saveButton_;
				QPushButton* printButton_;
				QHBoxLayout* buttonsLayout_;
				QVBoxLayout* main_layout_;
				
				QwtPlotZoomer* zoomer_;
				
	
			
		};
	}
}

#endif // PLOTTER_H
