// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: lineSearch.h,v 1.10 2003/02/02 21:53:59 oliver Exp $
// Line Search Minimizer: A special class for the line search minimization algorithm

#ifndef BALL_MOLMEC_MINIMIZATION_LINESEARCH_H
#define BALL_MOLMEC_MINIMIZATION_LINESEARCH_H

#ifndef BALL_COMMON_H
#	include <BALL/common.h>
#endif

namespace BALL 
{

	class EnergyMinimizer;

	/**	Basic line search class.
			Without being a true energy minimizer, this method minimizes
			the energy of a system along a given direction using	
			cubic interpolation. \\
			{\bf Definition:} \URL{BALL/MOLMEC/MINIMIZATION/lineSearch.h}
	*/
	class LineSearch
	{
		public:

		/**	@name	Constructors and Destructors	
		*/
		//@{
		
		BALL_CREATE(LineSearch)

		/**	Default constructor.
		*/
		LineSearch();

		/**	Detailed constructor.
		*/
		LineSearch(const EnergyMinimizer& minimizer);

		/**	Copy constructor
		*/
		LineSearch(const LineSearch& line_search);

		/**	Destructor.
		*/
		virtual ~LineSearch() 
			throw();
		//@}

		/**	@name	Assignments 
		*/
		//@{

		/**	Assignment operator
		*/
		const LineSearch& operator = (const LineSearch& LineSearch);

		//@}

		/**	@name	Accessors
		*/
		//@{

		/**	Set the parameter alpha
		*/
		void setAlpha(double alpha);

		/**	Set the parameter beta
		*/
		void setBeta(double beta);

		/**	Get the parameter alpha
		*/
		double getAlpha() const;

		/**	Get the parameter beta
		*/
		double getBeta() const;

		/**	Get the parameter max_steps
		*/
		Size getMaxSteps() const;

		/**	Set the parameter max_steps
		*/
		void setMaxSteps(Size steps);

		/** Set the minimizer
		*/
		void setMinimizer(const EnergyMinimizer& minimizer);

		/**	Line search criterion
		*/
		virtual bool criterion() const;

		/**	Cubic interpolation routine
		*/
		virtual double interpolate	
			(double lambda_0, double lambda_1, 
			 double energy_,  double energy_1, 
			 double grad_0,   double grad_1) const;		
		//@}

		/**	@name	Minimization
		*/
		//@{

		/**	Perform a line search.
		*/
		virtual bool minimize(double& lambda, double step = 1.0);

		//@}

		protected:
			
		/*_	Parameter alpha for line search criterion.
		*/
		double alpha_;
			
		/*_	Parameter beta for line search criterion.
		*/
		double beta_;

		/*_	Parameter for the number of interpolation steps
		*/
		Size max_steps_;

		/*_	Search direction.
		*/
		EnergyMinimizer* minimizer_;

		double initial_dir_grad_;
		double current_dir_grad_;
		double initial_energy_;
		double current_energy_;
		double lambda_;
		double step_;
	};

} // namespace BALL

#endif // BALL_MOLMEC_MINIMIZATION/LINESEARCH_H
