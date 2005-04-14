// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// $Id: secondaryStructureProcessor.h,v 1.9 2005/04/14 12:52:23 anhi Exp $
//

#ifndef BALL_SECONDARY_STRUCTURE_PROCESSOR_H
#define BALL_SECONDARY_STRUCTURE_PROCESSOR_H

#ifndef  BALL_COMMON_H
#include <BALL/common.h>
#endif

#ifndef BALL_CONCEPT_COMPOSITE_H
# include <BALL/CONCEPT/composite.h>
#endif

#include <vector>

namespace BALL
{
  
  /** Secondary structure extraction from 3D structure.
			This class implements the DSSP algorithm described in
			"Kabsch W & Sander C (1983). Dictionary of protein secondary structure: 
			pattern recognition of hydrogen-bonded and geometrical features. 
			Biopolymers, 22, 2577-2637."
			When applied to a protein, it removes the instances of SecondaryStructure
			from the protein, predicts the secondary structure elements based
			(mostly) on H-bond patterns and backbone torsions and reinserts the
			appropriate secondary structure elements at the predicted positions.
   */
  class SecondaryStructureProcessor 
		:	public UnaryProcessor<Composite>
	{
		public:
		/**	@name	Constructors */
		//@{
		///
		SecondaryStructureProcessor();
		//@}

		/**	@name Processor-related methods */
		//@{
		///
		virtual Processor::Result operator() (Composite& composite);
		//@}


		protected:

		/// Compute the secondary structure
		void compute_();
			
		// matrix to save the possible HBondPairs
		std::vector<std::vector<Position> > HBonds_;
		//vector to save the bridges
		std::vector<std::vector<int> > posbridges_; 
		void insertTurn_(int turn, int position);
    void changeAllXToY_(char X, char Y, String& target);			
		String sheet_;
		String fiveturn_;
		String fourturn_;
		String threeturn_;
		String summary_;
	};

} //namespace BALL

#endif // BALL_STRUCTURE_SECONDARYSTRUCTUREPROCESSOR_H
