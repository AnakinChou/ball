#ifndef BAYES_PLOTTER
#define BAYES_PLOTTER

#include <qwt_plot_spectrogram.h>

#include  <BALL/APPLICATIONS/QSAR_GUI/plotter.h>
#include  <BALL/APPLICATIONS/QSAR_GUI/modelItem.h>
#include <qwt_raster_data.h>

namespace BALL
{
	namespace VIEW
	{
		class BayesPlotter;
		
		class SpectrogramData : public QwtRasterData
		{
			public:
				SpectrogramData(BayesModel* snb,  const double& max_x, const double& min_y, const double& max_y, const double& y_resolution, BayesPlotter* plotter, bool copy=0);

				virtual QwtRasterData* copy() const;
				virtual QwtDoubleInterval range() const;

				virtual double value(double x, double y) const;
		
				/** calculates the probabilities for a specified class 
				@param class_index if plotter_::class_to_use_==-1, the class with the highest probability will be used for each cell of the heatmap */
				void precalculateProb();
			private:
				double min_x_;
				double max_x_;
				double min_y_;
				double max_y_;
				double min_z_;
				double max_z_;
				double y_resolution_;
				BayesModel* snb_;
				BayesPlotter* plotter_;
		};
		
		class BayesPlotter : public Plotter
		{
			public:
				BayesPlotter(ModelItem* model_item);
		
			
			private:
				ModelItem* model_item_;
				
				void plot();
				
				QwtPlotSpectrogram* spectrogram_;
				
				/** precalculated probabilities that are to be plotted */
				vector<vector<double> > data_;
				
				int class_to_use_;
		
				friend class SpectrogramData;
		};
	}
}

#endif //BAYES_PLOTTER
